﻿#pragma once
#include "board/gomoku_bitboard.hpp"
#include "board/types.h"
#include "resource/patterns.h"
namespace chis {
static const int WON = 99999999;
enum GAME_STATUS {
    NORMAL,
    ENDING,
    DEFEND,
    ATTACK,
    DRAW,
};
struct GomokuPatternInfo {
    //单一棋型应该不会超过127
    int8_t pattern_cnt_blk[16] = {};
    int8_t pattern_cnt_wht[16] = {};
};
//五子棋棋盘-状态/Hash/...
template <size_t size = 15, size_t offset = 5, typename BoardTy = GomokuBitBoard<size, offset>>
class GomokuBoard {
   public:
    using GomokuBoardType = GomokuBoard<size, offset>;

    struct moves_info {
        //相邻点不会超过127
        int8_t nbrate[size + offset * 2][size + offset * 2][6] = {};
        bool pattern_center[size + offset * 2][size + offset * 2][4] = {};
    };
    struct do_info {
        int i;
        int j;
        BOARD_VAL v;
        GomokuPatternInfo p;
        moves_info m;
    };
    class hash_func {
       public:
        uint64_t operator()(const GomokuBoardType &b) const { return b.hash(); }
    };
    class equal_func {
       public:
        uint64_t operator()(const GomokuBoardType &b, const GomokuBoardType &c) const { return b.hash() == c.hash(); }
    };

   public:  //关于棋盘操作
    //重载[]
    array_tmp<GomokuBoardType> operator[](size_t i) { return array_tmp<GomokuBoardType>{*this, i}; }
    //得到下一个落子方的颜色
    BOARD_VAL Turn() const { return doChain.size() % 2 ? BOARD_VAL::WHT : BOARD_VAL::BLK; }
    //落子
    GomokuBoardType &Do(int i, int j) { return Do(i, j, Turn()); }
    GomokuBoardType &Do(int i, int j, const BOARD_VAL v) {
        doChain.push_back(do_info{i, j, v, pinfo, minfo});  // TODO 优化一下，不粗暴维护
        vector_type<std::tuple<int, int, int>> need_update_pattern;
        {  //增量维护
            //得到棋型
            uint32_t pats[4] = {};
            std::tie(pats[0], pats[1], pats[2], pats[3]) = GetPattern(i, j);
            for (int k = 0; k < 4; ++k) {                                //四线棋型都要处理
                minfo.pattern_center[i + offset][j + offset][k] = true;  //选为棋型中心
                // TODO 更改resource的生成逻辑
                if (v == BOARD_VAL::BLK) {  //新棋型增加
                    ++pinfo.pattern_cnt_blk[pattern_type_map[pats[k] | (v << 10)] & 0xF];
                } else {
                    ++pinfo.pattern_cnt_wht[pattern_type_map[pats[k] | (v << 10)] >> 4];
                }
                for (int neg = -1; neg < 2; neg += 2) {  //每条线2个偏移方向
                    bool sameCenter = false, diffCenter = false, impactNb = true;
                    for (int l = 1; l < 6; ++l) {
                        int mv = neg == -1 ? -l : l;
                        BOARD_VAL side = BOARD_VAL((pats[k] >> (5 + mv) * 2) & 0x3U);  //两个方向
                        auto [xn, yn] = Nexts[k](i, j, mv);                            //偏移
                        if (side != BOARD_VAL::EMP) {                                  //遇到非空的点
                            impactNb = false;
                            // TODO 这段逻辑现在可以work, 但需要严格推导
                            //棋型中心维护 基本逻辑
                            // 1.落子会影响有效范围内的棋型
                            // 2.落子有不被 同色棋型中心点 阻挡的 异色棋型中心点，则需要更新异色棋型中心点的棋型
                            // 3.落子有被   同色棋型中心点 阻挡的 异色棋型中心点, 则异色棋型中心点棋型不收影响(且已经被更新过了)
                            // 4.落子有不被 异色棋型中心点 阻挡的
                            // 同色棋型中心点，则需要删除同色棋型中心点的标记和棋型(相当于吸收棋型) 5.落子有被   异色棋型中心点
                            // 阻挡的 同色棋型中心点, 则同色棋型中心点不收影响(中间有隔断) 非空点，检查是否为某一棋型的中心
                            if (minfo.pattern_center[xn + offset][yn + offset][k]) {  //遇到中心棋型，处理后截断
                                uint32_t pat = GetPattern(xn, yn, k);                 //得到旧的棋型中心的棋型
                                //同色+不被异色阻挡 || 异色+不被同色阻挡
                                //删除对应棋型
                                if ((side == v && !diffCenter) || (side != v && !sameCenter)) {
                                    if (side == BOARD_VAL::BLK) {
                                        --pinfo.pattern_cnt_blk[pattern_type_map[pat] & 0xF];  //减去对应的旧值
                                    } else if (side == BOARD_VAL::WHT) {
                                        --pinfo.pattern_cnt_wht[pattern_type_map[pat] >> 4];
                                    }
                                }
                                if (side == v) {  //同色点会被补回
                                    //同色子的棋型取消中心位置(被吸收) 且不需要补上新值
                                    if (!diffCenter) {
                                        minfo.pattern_center[xn + offset][yn + offset][k] = false;
                                    }
                                    sameCenter = true;
                                } else {
                                    if (!sameCenter) {
                                        //打上新值更新标记，等落子后更新
                                        need_update_pattern.push_back({xn, yn, k});
                                    }
                                    diffCenter = true;
                                }
                            }
                            //如果有两个阻挡，则后续棋子没有意义
                            if (sameCenter && diffCenter) {
                                break;
                            }
                        } else {
                            //如果nbrate不收影响(没有遇到非空点)
                            if (impactNb) {
                            // xn,yn距离为l的棋子+1
                            ++minfo.nbrate[xn + offset][yn + offset][l];
                            }
                        }
                        
                        
                    }
                }
            }
        }
        board.Set(i, j, v);    //棋盘变化
        zobrist.Set(i, j, v);  // hash变化
        {
            for (auto [i, j, k] : need_update_pattern) {  //需要更新的pattern_center
                uint32_t pat = GetPattern(i, j, k);
                BOARD_VAL val = BOARD_VAL((pat >> 10) & 0x3U);
                if (val == BOARD_VAL::BLK) {
                    ++pinfo.pattern_cnt_blk[pattern_type_map[pat] & 0xF];
                } else if (val == BOARD_VAL::WHT) {
                    ++pinfo.pattern_cnt_wht[pattern_type_map[pat] >> 4];
                }
            }
        }
        return *this;
    }
    //撤销落子
    GomokuBoardType &Undo() {
        pinfo = doChain.back().p;
        minfo = doChain.back().m;
        board.Reset(doChain.back().i, doChain.back().j);  //棋盘置空
        zobrist.Set(doChain.back().i, doChain.back().j,
                    doChain.back().v);  // hash变化
        doChain.pop_back();
        return *this;
    }
    //清空棋盘
    void Reset() {
        while (!doChain.empty()) {
            Undo();
        }
    }

   public:  //关于棋盘信息
    // Hash
    uint64_t Hash() const { return zobrist.Hash(); }
    // 着法生成
    vector_type<std::tuple<int, int>> Moves(bool must = false) {
        if (doChain.empty()) {
            return {{size / 2, size / 2}};
        }
        vector_type<std::pair<std::tuple<int, int>, int>> sorted;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (board.Get(i, j) == BOARD_VAL::EMP &&
                    (minfo.nbrate[i + offset][j + offset][1] ||
                     minfo.nbrate[i + offset][j + offset][2])) {  //选择附近至少有一个距离小于2的点的着法
                    sorted.push_back(
                        {{i, j}, minfo.nbrate[i + offset][j + offset][1] + minfo.nbrate[i + offset][j + offset][2]});
                    // cout << "Push Move " << i << "," << j << endl;
                }
            }
        }

        auto enemy_pat = Turn() == BOARD_VAL::BLK ? pinfo.pattern_cnt_wht : pinfo.pattern_cnt_blk;
        auto me_pat = Turn() == BOARD_VAL::BLK ? pinfo.pattern_cnt_blk : pinfo.pattern_cnt_wht;

        // TODO 增量点棋型
        if (!must && ((me_pat[PAT_TYPE::S4] || me_pat[PAT_TYPE::L4A] || me_pat[PAT_TYPE::L4B] || me_pat[PAT_TYPE::L3A] ||
                       me_pat[PAT_TYPE::L3B] || me_pat[PAT_TYPE::S3] ||
                       me_pat[PAT_TYPE::L2A] + me_pat[PAT_TYPE::L2B] + me_pat[PAT_TYPE::L2C] > 1) ||
                      //有4、有3、有两个活2
                      (enemy_pat[PAT_TYPE::S4] || enemy_pat[PAT_TYPE::L4A] || enemy_pat[PAT_TYPE::L4B] ||
                       enemy_pat[PAT_TYPE::L3A] || enemy_pat[PAT_TYPE::L3B] || enemy_pat[PAT_TYPE::S3] ||
                       enemy_pat[PAT_TYPE::L2A] + enemy_pat[PAT_TYPE::L2B] + enemy_pat[PAT_TYPE::L2C] > 1))) {
            for (auto &item : sorted) {
                auto [x, y] = item.first;
                uint8_t pats[4] = {};
                //敌方
                std::tie(pats[0], pats[1], pats[2], pats[3]) =
                    GetPatternType(x, y, Turn() == BOARD_VAL::BLK ? BOARD_VAL::WHT : BOARD_VAL::BLK);
                int enemy_info[16] = {};
                PAT_TYPE enemy_pty = PAT_TYPE::NON;
                for (int i = 0; i < 4; ++i) {
                    if (Turn() == BOARD_VAL::BLK) {  //白色反派
                        pats[i] = pats[i] >> 4;
                    } else {
                        pats[i] = pats[i] & 0x0F;
                    }
                    ++enemy_info[pats[i]];
                    if (enemy_pty < pats[i]) {
                        enemy_pty = PAT_TYPE(pats[i]);
                    }
                }
                //己方
                std::tie(pats[0], pats[1], pats[2], pats[3]) =
                    GetPatternType(x, y, Turn() == BOARD_VAL::BLK ? BOARD_VAL::BLK : BOARD_VAL::WHT);
                int me_info[16] = {};
                PAT_TYPE me_pty = PAT_TYPE::NON;
                for (int i = 0; i < 4; ++i) {
                    if (Turn() == BOARD_VAL::BLK) {
                        pats[i] = pats[i] & 0x0F;
                    } else {
                        pats[i] = pats[i] >> 4;
                    }
                    ++me_info[pats[i]];
                    if (me_pty < pats[i]) {
                        me_pty = PAT_TYPE(pats[i]);
                    }
                }
                //优先级判断
                //己方>敌方
                //成5>活4>=44=43>33
                if (me_info[PAT_TYPE::FIVE]) {
                    // cout << "mov " << 1 << endl;
                    return {{x, y}};
                } else if (enemy_info[PAT_TYPE::FIVE]) {
                    // cout << "mov " << 2 << endl;
                    item.second = WON + 9;
                    //己方 活4或者44, 43
                } else if (me_info[PAT_TYPE::L4A] || me_info[PAT_TYPE::L4B] || me_info[PAT_TYPE::S4] > 1 ||
                           (me_info[PAT_TYPE::S4] && (me_info[PAT_TYPE::L3A] || me_info[PAT_TYPE::L3B]))) {
                    // cout << "mov " << 3 << " " << x << "," << y << endl;
                    item.second = WON + 8;
                    //对方 活4或者44, 43
                } else if (enemy_info[PAT_TYPE::L4A] || enemy_info[PAT_TYPE::L4B] || enemy_info[PAT_TYPE::S4] > 1 ||
                           (enemy_info[PAT_TYPE::S4] && (enemy_info[PAT_TYPE::L3A] + enemy_info[PAT_TYPE::L3B]))) {
                    // cout << "mov " << 4 << endl;
                    item.second = WON + 7;
                    //己方 33
                } else if (me_info[PAT_TYPE::L3A] + me_info[PAT_TYPE::L3B] > 1) {
                    // cout << "mov " << 5 << endl;
                    item.second = WON + 6;
                    //对方 33
                } else if (enemy_info[PAT_TYPE::L3A] + enemy_info[PAT_TYPE::L3B] > 1) {
                    item.second = WON + 5;
                    //己方 冲4或成3
                } else if (me_info[PAT_TYPE::S4] || me_info[PAT_TYPE::L3A] || me_info[PAT_TYPE::L3A]) {
                    item.second = WON + 4;
                }
                // val >= WON+8 | 不考虑冲4，以val截断
                // val == WON+7 | 除了val,考虑冲4点 WON+4
            }
        }
        std::sort(sorted.begin(), sorted.end(), [](auto a, auto b) { return a.second > b.second; });
        vector_type<std::tuple<int, int>> ret;
        //存在成5
        if (sorted.front().second >= WON + 8) {
            for (auto &s : sorted) {
                if (s.second < WON + 4) {
                    break;
                }
                ret.push_back({s.first});
            }
        } else {
            for (auto &s : sorted) {
                ret.push_back({s.first});
            }
        }
        return ret;
    }
    // 评估函数 NegaEva
    int Evaluation() {
        static const int evaluation[14] = {
            -5, 
            5,  //S1
            15, //L1
            45, //S2
            220, 235, 250, //L2 ABC
            280, //S3
            485, 520, //L3
            580, //S4
            850, 900, //L4
            WON
        };
        int val = 0;
        for (int i = 1; i < 14; ++i) {
            val += (pinfo.pattern_cnt_blk[i] * evaluation[i]);
            val -= (pinfo.pattern_cnt_wht[i] * evaluation[i]);
        }
        return Turn() == BOARD_VAL::WHT ? -val : val;
    }
    // 是否终结局面
    std::tuple<int, GAME_STATUS> Ending() {
        if (doChain.size() == size * size) {
            return {0, GAME_STATUS::DRAW};
        }
        // check 先手胜利 A为下一步先手 返回A的胜负
        auto check = [this](const int8_t(&A)[16], const int8_t(&B)[16]) -> std::tuple<int, GAME_STATUS> {
            /********* 终结 *********/
            // B已经赢了
            if (B[PAT_TYPE::FIVE]) {
                return {-WON, GAME_STATUS::ENDING};
            }
            // A已经赢了
            else if (A[PAT_TYPE::FIVE]) {
                return {WON, GAME_STATUS::ENDING};
            }
            // A先手，有4直接赢
            else if (A[PAT_TYPE::L4A] || A[PAT_TYPE::L4B] || A[PAT_TYPE::S4]) {
                return {WON, GAME_STATUS::ENDING};
            }
            // 到这里，A已经没5没4了
            // B活四
            if (B[PAT_TYPE::L4A] || B[PAT_TYPE::L4B]) {
                return {-WON, GAME_STATUS::ENDING};
            }
            // B没有成5点
            if (!B[PAT_TYPE::S4]) {
                // A有成活四点就必胜了
                if (A[PAT_TYPE::L3A] || A[PAT_TYPE::L3B]) {
                    return {WON, GAME_STATUS::ENDING};
                }
            }
            // A没有成4点（只能被动防守），则考虑B有杀
            if (!(A[PAT_TYPE::L3A] || A[PAT_TYPE::L3B] || A[PAT_TYPE::S3])) {
                // B必胜的情况
                // B下一把有两个及以上成5点，大概率堵不住（待统计）
                if (B[PAT_TYPE::S4] > 1) {
                    return {-WON, GAME_STATUS::ENDING};
                }
                // B下一把有一个成5点（只能防守），同时又有成活4点
                else if (B[PAT_TYPE::S4] && (B[PAT_TYPE::L3A] || B[PAT_TYPE::L3B])) {
                    return {-WON, GAME_STATUS::ENDING};
                }
                // B下一把有两个及以上成活四点 (双活三)
                else if (B[PAT_TYPE::L3A] + B[PAT_TYPE::L3B] > 1) {
                    return {-WON, GAME_STATUS::ENDING};
                }
            }
            /********* 防守 *********/
            //对方有4或者活3
            if (B[PAT_TYPE::S4] || B[PAT_TYPE::L3A] || B[PAT_TYPE::L3B]) {
                return {0, GAME_STATUS::DEFEND};
            }
            /********* 进攻 *********/
            if (A[PAT_TYPE::S3] || A[PAT_TYPE::L3A] || A[PAT_TYPE::L3B]) {
                // || A[PAT_TYPE::L2A] || A[PAT_TYPE::L2B] || A[PAT_TYPE::L2C]
                return {0, GAME_STATUS::ATTACK};
            }
            return {0, GAME_STATUS::NORMAL};
        };
        int val = 0;
        GAME_STATUS status;
        if (Turn() == BOARD_VAL::BLK) {  //黑先手
            std::tie(val, status) = check(pinfo.pattern_cnt_blk, pinfo.pattern_cnt_wht);
        } else {
            std::tie(val, status) = check(pinfo.pattern_cnt_wht, pinfo.pattern_cnt_blk);
            val = -val;
        }
        return {Turn() == BOARD_VAL::WHT ? -val : val, status};
    }
    // 全局棋型信息
    GomokuPatternInfo PatternInfo() const { return pinfo; }
    // 单点取值
    BOARD_VAL Get(int i, int j) const { return board.Get(i, j); }
    // TODO uint8_t -> PAT_TYPE
    // 得到点的四线棋型对应的类型
    std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> GetPatternType(int i, int j) const {
        auto [h, s, p, n] = board.GetPattern(i, j);
        return {pattern_type_map[h], pattern_type_map[s], pattern_type_map[p], pattern_type_map[n]};
    }
    // 得到点的四线棋型对应的类型（空点填充)
    std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> GetPatternType(int i, int j, uint32_t v) const {
        auto [h, s, p, n] = board.GetPattern(i, j);
        return {pattern_type_map[h | (v << 10)], pattern_type_map[s | (v << 10)], pattern_type_map[p | (v << 10)],
                pattern_type_map[n | (v << 10)]};
    }
    // 得到点的四线棋型
    std::tuple<uint32_t, uint32_t, uint32_t, uint32_t> GetPattern(int i, int j) const { return board.GetPattern(i, j); }
    // 得到点的单线棋型
    uint32_t GetPattern(int i, int j, int k) const { return board.GetPattern(i, j, k); }

   public:  //棋盘状态 (对，就是public，别问为什么)
    // status
    vector_type<do_info> doChain;
    moves_info minfo;
    BoardTy board;  //棋盘
    // hashing
    ZobristHash<size, 4> zobrist;
    // pattern
    GomokuPatterns pattern_type_map;
    GomokuPatternInfo pinfo;
};
template <typename BTy, typename VTy>
using GomokuBoardMap = std::unordered_map<BTy, VTy, typename BTy::hash_func, typename BTy::equal_func>;
}  // namespace chis