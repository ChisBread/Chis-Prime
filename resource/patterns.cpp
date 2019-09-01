#include "resource/patterns.h"

namespace chis {

uint8_t GomokuPatterns::pattern_map[1U << 22] = {};
bool GomokuPatterns::inited = false;
const uint32_t patterns[2724] = {
    0x3a8a23a,  0x328aba,   0xc0b0,     0xe8a2bb,   0x322aabd,  0x3aa02ba,
    0x30a8ba,   0x3802032,  0x3a0a037,  0xeaa80bd,  0x32a222ba, 0x3002aba,
    0x3a8282b7, 0xc82837,   0xca2a2bb,  0x382a0b9,  0x30a282ba, 0x3882234,
    0x3aaa2abd, 0x30828b7,  0xea8ba,    0x388a80ba, 0x30a228b8, 0x3228b8,
    0x32028237, 0x32820ab7, 0xc8882b7,  0xe88b7,    0xe00a8ba,  0x38020b3,
    0x3a0a0b7,  0x3a828237, 0x3002a38,  0xc828b7,   0xca2a23b,  0x3a8a2bb,
    0x328a3a,   0xe8a23a,   0x3a02033,  0x322aa3d,  0x3aa023a,  0x38aaa8bd,
    0x30a839,   0x382208b5, 0xe8837,    0xe00a839,  0x30a2823a, 0x382a039,
    0x38822b7,  0x3082837,  0x388a803a, 0xea83a,    0x30a22838, 0x322838,
    0x388a2038, 0xe20aa3c,  0xe08a83a,  0x328aa8bd, 0xc22a0ba,  0x3aa22abb,
    0x380a2a3a, 0x3a820b7,  0xca282ba,  0xe2282b8,  0xca22b8,   0x3882a0b9,
    0x320a0ab7, 0x3aa288ba, 0x3aa20ba,  0x382a883c, 0xe28037,   0x3a020033,
    0x32aa083d, 0x3802a2ba, 0x38a8bb,   0x32aa88bd, 0x3222a23b, 0x3a8803a,
    0x3a82037,  0xca2823a,  0xe228238,  0xca2238,   0x3882a039, 0x388a20b8,
    0xe08a8bb,  0xe20aabd,  0xc22a03a,  0x3aa22a3b, 0x380a2aba, 0x32aa08bd,
    0x3802a23a, 0x38a83a,   0x32aa883d, 0x3a880ba,  0x3aa2883a, 0x3aa203a,
    0x382a88bc, 0xe280b7,   0x302a039,  0xca2ba,    0x302835,   0xc8220b5,
    0x322a02ba, 0xc208835,  0x32a20aba, 0x38220b5,  0x32a038,   0x3a2a023a,
    0xe088aba,  0xe2aa83d,  0xea2a0ba,  0xe8aa03c,  0x30228038, 0x382a0ab9,
    0x30aa803d, 0x38828237, 0xea223a,   0x30aa2a3c, 0x308aa8bd, 0x3022aba,
    0x30aa023c, 0x38022aba, 0xc2088b7,  0x3822035,  0x32a20a3a, 0x3a2a02ba,
    0x32a0b8,   0xe088a38,  0xca238,    0x3028b7,   0xc822035,  0x322a023a,
    0x388282b7, 0xea22ba,   0xe208a38,  0x308aa83d, 0x30aa02bc, 0x3022a3a,
    0x3a020b3,  0xea2a03a,  0xe8aa0bc,  0x302280b8, 0x382a0a39, 0x30aa80bd,
    0xc022aba,  0x3230,     0x38820034, 0x30028a3a, 0xc0288b8,  0xc008032,
    0xeaa8a3d,  0x3a08b7,   0x380228b8, 0x3222a83c, 0xca0a0b7,  0x382a08b9,
    0xea8aa3c,  0x388200b4, 0x320a0a37, 0x30028aba, 0xc022a3a,  0x32b0,
    0x38022838, 0x382a0839, 0xca20a38,  0xea8aabd,  0xc028838,  0x30aaa8bd,
    0xc0080b3,  0x30022838, 0xca200b8,  0x320a283a, 0xeaa083d,  0x3b0,
    0x300a283a, 0x38aaa0bd, 0x308a883b, 0xeaaa3d,   0x388aba,   0x38a200b8,
    0x3822a03a, 0xc888237,  0xe2aa2bd,  0xc20ab7,   0x38a0a37,  0xc82a039,
    0x3aaa803d, 0xe8a80ba,  0xc020834,  0xe2a803c,  0xea2003a,  0x30a2aba,
    0xc2a0a39,  0x38aaa83d, 0x320a82b9, 0xc20b3,    0x3822a0ba, 0xe2aa23d,
    0xca2038,   0xe2aa8bd,  0xc20a37,   0x320a8aba, 0xeaa08bd,  0x300a28ba,
    0x308a88bb, 0x388a38,   0xeaaabd,   0x38a20038, 0xc2a0ab9,  0x320a8239,
    0xc82a0b9,  0x302a82bc, 0x3aaa80bd, 0xe8a803a,  0xe2a80bc,  0xc0208b4,
    0xea200ba,  0x30a2a3a,  0x388aa0bc, 0x32208b4,  0xe0228b8,  0xc2a22ba,
    0x3a2a803c, 0xca08aba,  0xe80aabd,  0x300a8a3a, 0xe2a02ba,  0x308a2a3a,
    0x3a22237,  0xe0a22b8,  0xe2882b8,  0xc0aa23c,  0x32a228ba, 0xe82aba,
    0xc828aba,  0x3002a8bc, 0x3a208b7,  0x30a28ba,  0x328a03a,  0xeaa883d,
    0x382aba,   0xca08a38,  0xc2888b8,  0x300a8aba, 0x3a0837,   0x308a2aba,
    0xe2a023a,  0xc088aba,  0x3220834,  0x3aa0ba,   0x3a2a80bc, 0xc2a223a,
    0xe82a38,   0x3002a83c, 0xc828a3a,  0x3a20837,  0x30a283a,  0x328a0ba,
    0x382a38,   0xeaa88bd,  0x3a222b7,  0xe0a2238,  0xe288238,  0x32a2283a,
    0xc0aa2bc,  0xe008b3,   0xca888ba,  0x38031,    0xe28a23a,  0x308202b4,
    0x38880b7,  0x3a822aba, 0xe022aba,  0x380a8239, 0x30a0235,  0x3220ab7,
    0xe2a3a,    0x308a8a3b, 0x380a8039, 0x32882b8,  0xc0a8039,  0xc0a238,
    0xe08835,   0xca22a3a,  0x3202835,  0x3a080b7,  0x38a0037,  0xe0a839,
    0x382220b7, 0x32a282ba, 0x380200b2, 0x30820234, 0x3888037,  0x3a822a3a,
    0xe022a3a,  0x30a02b5,  0x3220a37,  0xe2aba,    0xe00832,   0xca8883a,
    0x380b3,    0x3a08037,  0x38a00b7,  0xe0a8ba,   0x32a2823a, 0xeaa83d,
    0xe0088b7,  0x308a8abb, 0x3a2ba,    0xc0a80b9,  0xe088b7,   0xc0a2ba,
    0xca22aba,  0xc28a8bb,  0x3a00b3,   0xc080b3,   0xc0a2a3a,  0x302a823c,
    0x322a83c,  0x38aaaabd, 0xe8202b7,  0xe028aba,  0x38a282ba, 0xc228038,
    0xc88aabd,  0xc222a3a,  0x38aa2bc,  0xe2a0ba,   0x3a2a83c,  0xe02a0b9,
    0xcaa0abc,  0x30aa0bc,  0x30822a3a, 0x300aa83d, 0x322a8bc,  0xe820237,
    0x38aaaa3d, 0x38a2823a, 0xe028a3a,  0xc2280b8,  0x3a222237, 0xc28a83a,
    0x32228038, 0x3a0033,   0xc08032,   0xc0a2aba,  0xcaa0a3c,  0x30aa03c,
    0x30822aba, 0xc88aa3c,  0xc222aba,  0x38aa23c,  0x3a0a0237, 0xe2a03a,
    0x3a22a03a, 0x3a828aba, 0x3a2a8bc,  0xe02a039,  0x30228b8,  0x3882aba,
    0x380aaa3d, 0x328a20ba, 0x38082b7,  0x38820b4,  0x3a0280b6, 0x302a2ba,
    0x302222b7, 0x302aa0bd, 0x32080b4,  0x3228838,  0x30828037, 0x3202aabd,
    0x32820037, 0x3a2883a,  0x3a2200b7, 0x30aa3c,   0xe08aabd,  0x30020a37,
    0xe2220b7,  0xc20a8ba,  0xca8a3a,   0x3808234,  0x32828aba, 0x3a028036,
    0x302a23a,  0x30222237, 0x32028b7,  0x32828037, 0x3882a38,  0x380aaabd,
    0x328a203a, 0x30aabd,   0xe08aa3c,  0xe222037,  0x3a2a3a,   0xc20a839,
    0xca8aba,   0x3208034,  0x308280b7, 0x32288b8,  0x3202aa3d, 0x3a288ba,
    0x382a2a3a, 0xc8880b7,  0xc2834,    0x3202a8bc, 0xe222b7,   0xc82aba,
    0x3a82a039, 0xc2b0,     0x3a0a08b7, 0x3a0a0a37, 0x320282b7, 0xc288838,
    0x3a8a0ba,  0x388a82ba, 0xc0a34,    0x322aaa3d, 0x320a2ba,  0xc088a38,
    0x3a828037, 0xc888037,  0xc28b7,    0x3202a83c, 0xc82a38,   0xe22237,
    0x3a82a0b9, 0xc230,     0xe200b3,   0x322aaabd, 0x320a238,  0x3a8a03a,
    0x388a823a, 0x380a82b9, 0x38a22aba, 0x30a2a83c, 0xc22a2bb,  0xea08837,
    0xe808aba,  0xc888a38,  0xe28237,   0x3088aba,  0x3022a23b, 0x380aa83d,
    0x3882a2ba, 0xca8aa3c,  0x322a82bc, 0x32aaaabd, 0x30280b6,  0x3222aabd,
    0x3082a38,  0x320a2aba, 0x3828838,  0x3a28a3b,  0x3a8823a,  0xe282b7,
    0x328200b7, 0xca2803a,  0x3022a2bb, 0x380aa8bd, 0x3882a23a, 0x38a22a3a,
    0x30a2a8bc, 0xea088b7,  0xc22a23b,  0xe808a38,  0x3082aba,  0x320a2a3a,
    0x38288b8,  0x3a28abb,  0x3a882ba,  0x322a823c, 0x32aaaa3d, 0x3028036,
    0x32a2023a, 0x302aabd,  0xc8082b7,  0xc208aba,  0x382a8a3c, 0x308032,
    0x32aaa8bd, 0xea280ba,  0x32220a37, 0x3a2a003a, 0x380a0a37, 0x32a23a,
    0xc088235,  0x30228238, 0x38aa023c, 0x302a28ba, 0x38828037, 0x322280b8,
    0x3a22a0ba, 0xeaa8bd,   0x30aa003c, 0xea2803a,  0x32220ab7, 0x3a2a00ba,
    0x380a0ab7, 0x32a2ba,   0xc808234,  0x382a8abc, 0xc208a38,  0x3080b3,
    0x32aaa83d, 0x3022838,  0x320a8a3a, 0xcaa28bc,  0x30aa00bc, 0xca20b8,
    0x3a0200b3, 0x3882034,  0x302282b8, 0x38aa02bc, 0x302a283a, 0x38aa20bc,
    0x388280b7, 0x32aa20bd, 0x302aa03d, 0x3820834,  0x320a0237, 0xc288b8,
    0x32222838, 0xea0a839,  0x3a20ab7,  0xe220237,  0x3002aabd, 0xc8288b8,
    0xea08a38,  0x3828b7,   0x32828a3a, 0x3a22a23b, 0xea88abb,  0x3aa003a,
    0xeb0,      0xca0a238,  0x3aaa3d,   0x32aa83d,  0x32a22abb, 0x3a30,
    0xeaaa83d,  0xe8a283b,  0x3a20a37,  0x382a2aba, 0xe82a8bc,  0xc828838,
    0x3002aa3d, 0xea08aba,  0x382837,   0x38208b4,  0x320a02b7, 0xc28838,
    0xe8a0ba,   0x32820a37, 0xea0a8ba,  0x32aa8bd,  0x32a22a3b, 0x3ab0,
    0xeaaa8bd,  0x38028aba, 0xea88a3a,  0x3a2220b7, 0xca0a2ba,  0xe8228b8,
    0x38a202b8, 0xc2a8bc,   0x3a8aaabd, 0xe888a38,  0x308aabd,  0xc28aba,
    0xc8aaabd,  0xcaa23c,   0x3a8a28bb, 0xe8a2abb,  0xea8a83a,  0x328b7,
    0xea2023a,  0xe8a00ba,  0xe8a82ba,  0x3820ab7,  0x320a80b9, 0xc28a3a,
    0xcaa2bc,   0x38a20238, 0x38aa2a3c, 0xc2a83c,   0xe888aba,  0x3a8aaa3d,
    0x308aa3c,  0x30a2883a, 0xe8a823a,  0x3820a37,  0x320a8039, 0xe8a2a3b,
    0x3a8a283b, 0xea8a8bb,  0x32833,    0x3aa2083a, 0xca8aabd,  0xea202ba,
    0x388222b7, 0xe228a3a,  0xc2a20ba,  0x328a0aba, 0x300a88ba, 0x32222037,
    0xc08a0b8,  0x32a0838,  0xe2a00ba,  0x32a88bc,  0xcaa08bc,  0x300a0837,
    0xe28a83a,  0xe0a20b8,  0xc022b7,   0xc0a2238,  0xc8a0a38,  0x308a22b8,
    0x38a2aa3d, 0xe22aa3d,  0x300a8ba,  0x38020ab7, 0xeaa203d,  0xe2880b8,
    0xe2a003a,  0x32a883c,  0xcaa083c,  0x300a08b7, 0xc2a203a,  0x300a883a,
    0xeaa22bd,  0x322220b7, 0x30a80b9,  0x32a08b8,  0xc08a038,  0x38a2aabd,
    0x30a82b9,  0xe22aabd,  0x38020a37, 0xeaa20bd,  0xe288038,  0xe8a03a,
    0xe0a2038,  0xc02234,   0xc8a0ab8,  0x382a803c, 0x38028a3a, 0xc820834,
    0x30022035, 0x38a20b8,  0xe822838,  0xe888837,  0x30a0035,  0xe80ab7,
    0x308a0a38, 0x302a0239, 0x32822838, 0xc20834,   0x3a082b7,  0x3a8aa83d,
    0x32a280ba, 0xc28aa3c,  0x3a02aba,  0x300220b5, 0xc8208b4,  0x300228b8,
    0x38a2038,  0x30a00b5,  0xe8888b7,  0x38220235, 0xc2aaabd,  0x32aa203d,
    0x3a08237,  0x3a8aa8bd, 0x32a2803a, 0x3a02a38,  0xc28aabd,  0xe80a34,
    0x308a0ab8, 0x3a22a2bb, 0x328228b8, 0xe2202b7,  0x3a8037,   0xe020ab7,
    0x3a02b3,   0xe0aa2bc,  0xe220a37,  0x382288b8, 0xc082b7,   0xc80a8ba,
    0xc8a28ba,  0x30aa2bc,  0x3282037,  0xe228aba,  0xc2a80bc,  0xe02033,
    0xe8282b7,  0x32a0a38,  0xe28b7,    0x3828aba,  0xe822237,  0x30020233,
    0xe2aaabd,  0x30a22a3a, 0x30820034, 0xe2082b7,  0xc0a22b8,  0x32820b7,
    0xe020b3,   0xc2a803c,  0xe828237,  0xe020a37,  0x3a0233,   0xe0aa23c,
    0xe220ab7,  0x38228838, 0xc08234,   0x30aa23c,  0xc8a283a,  0x308200b4,
    0x30aa2abc, 0xe208234,  0xe2837,    0xe02a23a,  0x3828a3a,  0xe8222b7,
    0x300202b3, 0x30a22aba, 0x300a839,  0x328a22ba, 0xc222838,  0xe888b7,
    0x322aba,   0x3802aba,  0x32022838, 0x38a22838, 0xe8088b7,  0xca0a8ba,
    0xe80833,   0xc8a82ba,  0x3202234,  0x38aa3c,   0x30220235, 0xcaa2abc,
    0x38aa823d, 0xe8a0aba,  0xc2aa23d,  0x3a8200b7, 0x302aaabd, 0x32082b7,
    0xc220a37,  0xe820037,  0xe88837,   0x320228b8, 0x3802a38,  0xe808835,
    0x38a228b8, 0xe808b3,   0xc8a823a,  0x3a0a2aba, 0x308a00b8, 0x3aa208ba,
    0xc2228b8,  0xc2aa2bd,  0x38822237, 0x3a820037, 0x30220035, 0x3208234,
    0xc220ab7,  0xe8200b7,  0x32022b7,  0x32228238, 0x38aabd,   0x302202b5,
    0x38aa82bd, 0xcaa2a3c,  0x320280b6, 0xe008032,  0x308a2238, 0x3a82a23a,
    0xc288038,  0xe28aba,   0x3208b4,   0xc880b4,   0x30a208b8, 0xe220b7,
    0xe8aa3c,   0xe220837,  0x32aaabd,  0x380a0b7,  0x30088b7,  0xe0aabd,
    0x320a0b7,  0x3802a0b9, 0xe20233,   0x3808033,  0x30aaa0bd, 0xe22037,
    0xe8aabd,   0xe2208b7,  0x3aa2a83c, 0xe0080b3,  0x3a82a2ba, 0xe28a3a,
    0xc2880b8,  0x320834,   0x30a20838, 0xc88034,   0x320a037,  0x302a0b9,
    0x38080b3,  0x30aaa03d, 0xe82037,   0x32aaa3d,  0x3008835,  0x380a036,
    0x3020032,  0xea23a,    0x38aa223c, 0x3022a03a, 0x3a0a0037, 0x30228aba,
    0xc8a2ba,   0x32aa283d, 0x300a2aba, 0xe82a039,  0xea0837,   0x30282b7,
    0x3aa08ba,  0x320aa03c, 0xe20a037,  0x3008aba,  0xc8a238,   0x32aa28bd,
    0x3a0a88ba, 0xe82a0b9,  0x300a2a3a, 0xe228038,  0xea08b7,   0x30200b2,
    0x3288b8,   0x38aa22bc, 0x3022a0ba, 0x30228a3a, 0xe20a0b7,  0x3008a38,
    0x3028237,  0xc80a839,  0x3a8aba,   0x30a238,   0xe8a003a,  0x320aa0bc,
    0xc02a8bc,  0x380a08b7, 0xe80a8ba,  0x38aa08bc, 0x38aa8abd, 0x3aa2283a,
    0xc008aba,  0x308234,   0xca20038,  0x308a83a,  0xea282ba,  0xca00b4,
    0x3022237,  0xc088035,  0xc8080b3,  0x38aa003c, 0xe22a8bc,  0x30aaa83d,
    0xea8aba,   0x3aa8a3d,  0x322a283b, 0xe2288b8,  0xc80a0b7,  0xe88aba,
    0x30aa28bc, 0x38220a37, 0x308a8bb,  0x302a8a3c, 0xca0034,   0xea2823a,
    0x30222b7,  0xc808033,  0xc0880b5,  0x38aa00bc, 0xc02a83c,  0x380a0837,
    0xe0aa3c,   0xe80a839,  0x3aa228ba, 0x3082b7,   0xc008a38,  0x322a28bb,
    0xe88aabd,  0xe228838,  0xc80a036,  0x30aa283c, 0xe22a83c,  0xea8a3a,
    0x3aa8abd,  0x320a0037, 0xea88ba,   0x308aa23c, 0xe820b7,   0x3aa88bd,
    0x380208b4, 0x328a083a, 0x38822838, 0x302aa2bd, 0x382a28ba, 0x3088837,
    0x302234,   0x32a2a03a, 0x3a228aba, 0x3aa883d,  0x3828037,  0x38020834,
    0x328a08ba, 0x388228b8, 0x3a02aabd, 0x382a283a, 0x302aa23d, 0x322282b8,
    0x320a00b7, 0xea883a,   0x308aa2bc, 0x32028036, 0x3222aa3d, 0x30888b7,
    0x3022b7,   0x3a0a02b7, 0x32a2a0ba, 0xe8aaabd,  0xca8a2bb,  0xc022838,
    0x3a22aba,  0xc00a036,  0x308a20b8, 0x328aaabd, 0xcaa03c,   0x3aaaabd,
    0xe8a02ba,  0x322a80bc, 0x380288b8, 0xe28a03a,  0x30a8239,  0xea8883a,
    0xe220037,  0x3088035,  0x32aaa2bd, 0x3a8288b8, 0xc00a0b7,  0x308a2038,
    0xcaa0bc,   0x38aaa03d, 0x3aaaa3d,  0xe8aaa3d,  0x3a220037, 0xc0228b8,
    0x3a22a3a,  0xea888ba,  0xe8a023a,  0x30a20ab8, 0x38028838, 0xe88aa3c,
    0xe28a0ba,  0x32222237, 0x32a2003a, 0x3822a3a,  0xeaa82bd,  0xc08a2ba,
    0x3282aabd, 0x300282b7, 0x38228a3a, 0xc8a2aba,  0x3a228b8,  0x38aba,
    0x3a2a28bb, 0xea22abb,  0xc020b3,   0x32220b7,  0xeaa223d,  0x3a8a2a3b,
    0x30a8039,  0x32a37,    0x3aaa203d, 0x30028237, 0x38228aba, 0xc8a2a3a,
    0x3a22838,  0x38a37,    0x3a2a283b, 0xea22a3b,  0x322222b7, 0x30020032,
    0x3822aba,  0x32a200ba, 0xeaa823d,  0x328a88bb, 0xc08a238,  0x3282aa3d,
    0x3222037,  0x38aa8a3d, 0x3aaabd,   0xe8a28bb,  0x3a8a2abb, 0xeaa8abd,
    0x32aba,    0x3aaa20bd, 0x328a0a3a, 0x3aaaa2bd, 0xc02032,   0xe2a20bb,
    0xc220b5,   0xe0a0037,  0x30022237, 0x322208b7, 0xe88a38,   0x3a0220b5,
    0xe082b7,   0x38aa203c, 0x302a8abc, 0x38a2a83c, 0x38220ab7, 0x38222a3a,
    0xc20aa3c,  0x32202b4,  0x3a202b7,  0x3a82b7,   0x302a0039, 0xc2a00b9,
    0xe020834,  0x382aa83d, 0xe08234,   0x38a2a8bc, 0xe2a203b,  0xe0a00b7,
    0xc22035,   0x300222b7, 0x3a022035, 0xe2200b7,  0xc2a0039,  0xe0208b4,
    0x308a08b8, 0x38222aba, 0xc20aabd,  0x3220234,  0x3a8237,   0x3a20237,
    0x302a00b9, 0x3a2aa03d, 0xe02234,   0x30828aba, 0xea30,     0xe8280b7,
    0x320a37,   0xc2a82bc,  0xe0aa0bc,  0x308228b8, 0x3a02835,  0x380a80b9,
    0xc88a038,  0x38280b7,  0x32a8a3c,  0xc8a02b8,  0xe2080b4,  0x38a2238,
    0xc0a2038,  0xeab0,     0xe828037,  0x320ab7,   0xc2a823c,  0xe0aa03c,
    0xe022b7,   0x32828237, 0x30828a3a, 0xca8a23a,  0xc8a0238,  0xe208034,
    0x38a22b8,  0x38228238, 0xc0a20b8,  0x3a028b7,  0x32a28ba,  0xc88a0b8,
    0x30aa8abd, 0x32a8abc,  0xca08837,  0x32022aba, 0xe028838,  0x3aabd,
    0xc8aa03c,  0xca220b8,  0x3a022a3a, 0xe222a3a,  0x38aa83d,  0x320200b3,
    0x3202033,  0xc8a80ba,  0x30880b5,  0xc28a2bb,  0xca2aa3d,  0x3a8a003a,
    0xc2aa03d,  0x388a038,  0xe0031,    0x3a02a83c, 0x3aa2aa3d, 0xe222aba,
    0x32a220ba, 0x38aa8bd,  0x32020033, 0x32020b3,  0xc8a803a,  0x32022a3a,
    0x3aa3a,    0xe0288b8,  0x382202b5, 0xc8aa0bc,  0xca22038,  0x388a0b8,
    0x3a0a883a, 0x3aaa0a3d, 0xe00b1,    0x3a02a8bc, 0x3aa2aabd, 0x3208aba,
    0xca2aabd,  0xc28a23a,  0x3a8a00ba, 0xc2aa0bd,  0xc288238,  0xc0a036,
    0x308a0838, 0xe822aba,  0xc82234,   0x3882837,  0xe8a8bb,   0x3082a039,
    0xc882b7,   0x30822838, 0x30020b3,  0x3888aba,  0x300200b2, 0xe0082b7,
    0x30aaa2bd, 0x30a222b8, 0xc08b3,    0x322aa8bd, 0xe830,     0xc8834,
    0x38022a3a, 0x3a82aa3d, 0xe8a83a,   0x38828b7,  0x3082a0b9, 0xc88234,
    0xc2882b8,  0x38822aba, 0xc822b7,   0xe822a3a,  0x30aaa23d, 0x30a22238,
    0xc0832,    0xca0ab7,   0xe8b0,     0x322aa83d, 0xc88b7,    0x3a82aabd,
    0x32220837, 0x3a822037, 0x3002032,  0x302a2aba, 0x3888a38,  0xe008234,
    0x38a2ba,   0xea037,    0x32aa2abd, 0x3aaaaa3d, 0x322034,   0x3aaa22bd,
    0xe82a23a,  0x3a80b7,   0x328a8a3b, 0xca283a,   0x30aaa3d,  0x32aa00bd,
    0xc8a0b8,   0x3a82aba,  0x3802835,  0xe20a238,  0x30202b3,  0xc0a0a37,
    0x30220ab7, 0x30a0b7,   0xca2a83c,  0xca80b8,   0xc02aa3d,  0x3802aabd,
    0x30aaabd,  0x32aa003d, 0xc8a038,   0x38a238,   0xea0b7,    0x32aa2a3d,
    0x3220b4,   0x3aaaaabd, 0x382a8bc,  0x3a228038, 0x30220a37, 0xc0a0ab7,
    0x30a035,   0xca8038,   0xca2a8bc,  0xc02aabd,  0x3a82a38,  0xe20a2ba,
    0x38028b7,  0x3020233,  0x300a0ab7, 0x3aaa83d,  0x300232,   0x3a828b7,
    0x3aa2803a, 0x322a883c, 0x30a202b8, 0x3022035,  0xca02b4,   0x38820234,
    0x388a283a, 0xca8ba,    0xe08a038,  0x32a288ba, 0xea0ab7,   0x30a2a23b,
    0x3a22aa3d, 0xc0a0b7,   0xea283a,   0xe0880b5,  0x3aa0a3a,  0x308a38,
    0xc80aabd,  0x380aa23c, 0x3a2a2a3b, 0xc80a2ba,  0xca0234,   0x30220b5,
    0x388a28ba, 0xe08a0b8,  0xca838,    0x3aaa8bd,  0x300a0a37, 0x3208a38,
    0x3002b3,   0x32a283a,  0x3aa280ba, 0x3a82837,  0x322a88bc, 0xca088b7,
    0x3aa0aba,  0x308aba,   0x380a2238, 0x380aa2bc, 0x3a022aba, 0x38aa803d,
    0xc80a238,  0xea0a37,   0x30a2a2bb, 0x3a22aabd, 0x32a202ba, 0xe088035,
    0xea28ba,   0xea2283a,  0x3a020ab7, 0x308aa03c, 0xc82aabd,  0x3a0a00b7,
    0x3a2aa2bd, 0x3aaaa83d, 0x322a2a3b, 0xeaaaabd,  0xc8228b8,  0x32a83c,
    0xc80ab7,   0x32a2a23b, 0x38b0,     0x302032,   0x38228b8,  0xe8aa83d,
    0x3aaaa03d, 0x3a2aa23d, 0x32228838, 0x3aaaa8bd, 0x322a2abb, 0x3aa03a,
    0xea228ba,  0x308aa0bc, 0x3a020a37, 0xc82aa3d,  0x3822838,  0xc22a8bc,
    0xe8aa8bd,  0xeaaaa3d,  0xc822838,  0xc80a34,   0x32a8bc,   0x32a2a2bb,
    0x3020b3,   0x3830,     0x308b3,    0xc028036,  0x388033,   0x322202b7,
    0xc00a238,  0x320a2038, 0x3a2202b7, 0x32aabd,   0xeaa02bd,  0xc282b7,
    0x380220b5, 0x3a0a283a, 0xc200b2,   0x300a22b8, 0x388202b4, 0x38828aba,
    0x32aa02bd, 0x388a2a3a, 0x32a22ba,  0x328aabd,  0x32220237, 0xc00a2ba,
    0x320a20b8, 0x3a220237, 0xca0a37,   0x32aa3d,   0x3aaa283d, 0x30831,
    0xc0280b6,  0x32020a37, 0x3880b3,   0x3a220a37, 0x302a02b9, 0x38828a3a,
    0x388a2aba, 0xc208b4,   0x3aa2a2bb, 0x328aa3c,  0x32a223a,  0xeaa023d,
    0xc28237,   0x30b0,     0x3a0a28ba, 0xca28ba,   0x380232,   0x300a2238,
    0xca20ab8,  0x32222b7,  0x30ab7,    0x30022aba, 0xc0aa83d,  0x32822a3a,
    0xc2aa3d,   0x3a0aa8bd, 0x38022237, 0x3aaa08bd, 0x38a208b8, 0x3822a83c,
    0x300aa3c,  0x3a8a803a, 0x3a0a0ab7, 0xc82a83c,  0x32222a3a, 0x3aaa883d,
    0x30022a3a, 0x30a33,    0xc0aa8bd,  0xc2aabd,   0xe28aabd,  0xeaa803d,
    0x3222237,  0x3a8a80ba, 0x300aabd,  0xc82a8bc,  0x32222aba, 0x3aaa88bd,
    0x3a0aa83d, 0x3aaa083d, 0x38a20838, 0x3822a8bc, 0x300aa2bc, 0x3a0222b7,
    0x30a20a38, 0xe2a22bb,  0xea20aba,  0xc222b7,   0xe0a8039,  0xcaa283c,
    0x3a8a8bb,  0x32a2203a, 0x328222b7, 0x38a08b7,  0x3a837,    0x3a0208b4,
    0x32200b4,  0xe0220b5,  0xe0a02b7,  0xc8aba,    0x3002a0b9, 0x3a200b7,
    0x32888b8,  0xc2a02b9,  0x30028036, 0xe02a2ba,  0x38aa80bd, 0x3a0a0837,
    0x3282a8bc, 0x32822237, 0x3a8ba,    0x38a0837,  0x3a022237, 0x300aa23c,
    0x3aa2203a, 0xe2a223b,  0xea20a3a,  0xc22237,   0xe0a80b9,  0x3288838,
    0xc2a0239,  0x300280b6, 0x300832,   0x3220034,  0xe022035,  0xe0a0237,
    0x3002a039, 0xc8a38,    0x3a20037,  0x388a00b8, 0x38222838, 0x38a883b,
    0xe00a2ba,  0x388aaa3d, 0x3a2a0ba,  0x300a0236, 0x3288aba,  0xca8a0ba,
    0x30a28abb, 0x322288b8, 0xcaaa8bd,  0xc0a08b7,  0xc88a238,  0xe022838,
    0x3a088b7,  0x38833,    0xe08033,   0x3222a8bc, 0xc8088b7,  0xc8a00b8,
    0xca880ba,  0xc0a883a,  0x3a283a,   0xc888aba,  0x3a2a03a,  0x388aaabd,
    0xca8a03a,  0x3288a38,  0x30a28a3b, 0x382228b8, 0x38a88bb,  0xe080b3,
    0xc8a0038,  0x308aaa3d, 0xca8803a,  0xc0a88ba,  0x3a28ba,   0xcaaa83d,
    0xc88a2ba,  0xc0a0837,  0x3a08837,  0x388b7,    0xca222b8,  0xe2a83c,
    0xc8aa23c,  0xc20a2ba,  0x3228238,  0x320202b3, 0x3a2823a,  0x3282a23a,
    0xe02a83c,  0x302208b5, 0x38aaabd,  0xe0233,    0x3a8a023a, 0xca30,
    0x322a03a,  0xc228838,  0xea08237,  0x388a238,  0xc28a0ba,  0x3a220ab7,
    0xc2208b5,  0x38a2883a, 0x32282b8,  0x3a282ba,  0x32020233, 0xe02a8bc,
    0x3282a2ba, 0x30220835, 0x38aaa3d,  0xca22238,  0xe2a8bc,   0xc8aa2bc,
    0xc22a3a,   0xc20a238,  0xc2288b8,  0x388a2ba,  0xc28a03a,  0xc220835,
    0x3a8220b7, 0x38a288ba, 0xe02b3,    0x3a8a02ba, 0xcab0,     0x322a0ba,
    0xe00a0b7,  0x3208835,  0x380a2ba,  0xe208b4,   0x3a0288b8, 0x302a2a3a,
    0xe80b3,    0x3082a23a, 0xc8b0,     0x3202a2ba, 0x32028a3a, 0x30022b7,
    0xc820b4,   0x328a28bb, 0xe28aa3c,  0x38a22238, 0x3a0a8ba,  0xe2228b8,
    0x30820b4,  0x388a88bb, 0x30a220b8, 0xe008a38,  0x3a8222b7, 0xc288a38,
    0xe8033,    0x3082a2ba, 0xca0aabd,  0xc830,     0x3202a23a, 0xe00a036,
    0x32088b7,  0xe20834,   0x3a028838, 0x3082034,  0x388a883b, 0x30a22038,
    0xe008aba,  0x3aa2003a, 0x3a822237, 0xc288aba,  0x3002234,  0x3a828a3a,
    0xc82034,   0x328a283b, 0x30aa8a3d, 0x3a0a839,  0x38a222b8, 0xe222838,
    0x32aa80bd, 0x3a2282b8, 0xe28838,   0x328aa0bc, 0x32a2a3a,  0x3aa28ba,
    0x322237,   0x38a0b7,   0x3a8a83a,  0x3a020834, 0xe2aa3d,   0x3008234,
    0x38aa0abc, 0x300ab7,   0x3282a83c, 0xea082b7,  0x3a8883a,  0x3a82a83c,
    0x32a0ab8,  0x3aa220ba, 0xca2aba,   0xe820ab7,  0x38aaa2bd, 0xca82b8,
    0x3a0aabd,  0xc22a83c,  0xe2aabd,   0x3008b3,   0x38aa0a3c, 0x30082b7,
    0x300a34,   0x32020ab7, 0x3a228238, 0x32aa803d, 0xe288b8,   0x3a237,
    0x328aa03c, 0x3aa283a,  0x3222b7,   0x38a037,   0xca2a3a,   0xe2aaa3d,
    0x38aaa23d, 0xe820a37,  0xca8238,   0xe0882b7,  0x3a0aa3c,  0x3a888ba,
    0xe00a238,  0x3a82a8bc, 0x3aa2a23b, 0x300a02b6, 0xc208034,  0x3aa2823a,
    0x322a22bb, 0x380a20b8, 0xea2a8bc,  0xca288ba,  0x30222aba, 0x30228838,
    0x388288b8, 0x30aa883d, 0x3aa2aba,  0x30aa08bc, 0x30a2a03a, 0x38aa283c,
    0x328237,   0x300aa8bd, 0x3a2aa0bd, 0x3882a83c, 0x380aa03c, 0x30020ab7,
    0xea0237,   0x3a8a20ba, 0x302288b8, 0x38828838, 0x30aa88bd, 0x3aa2a3a,
    0x30a2a0ba, 0x30aa083c, 0xc2080b4,  0x3aa282ba, 0x322a223b, 0x380a2038,
    0xea2a83c,  0xca2883a,  0xcaa883d,  0x380aa0bc, 0x3882a8bc, 0xea02b7,
    0x302220b7, 0x38aa28bc, 0x3282b7,   0x30222a3a, 0x3aa200ba, 0x382a00b9,
    0xea2a3a,   0xea288ba,  0xe22a23b,  0xc88a38,   0x3a0aaabd, 0x308aaabd,
    0xca20838,  0xea2aabd,  0x32aa23d,  0x322a8abc, 0xc02a2ba,  0x320a0837,
    0x388208b4, 0x32a2aba,  0x3a2a083a, 0xe80a2ba,  0xc22aba,   0xca208b8,
    0xea2aa3d,  0x328280b7, 0x320a08b7, 0x382a0039, 0x32aaa23d, 0xea2aba,
    0xe22a2bb,  0xea2883a,  0xc88aba,   0x320aaa3d, 0x308a82ba, 0xe80a238,
    0x380a238,  0x32aa2bd,  0xc02a23a,  0x3aa222ba, 0x38820834, 0x3a2a08ba,
    0xc028237,  0x320a2238, 0x3a2228b8, 0xe8a88bb,  0xc020032,  0xe2a883c,
    0xea2083a,  0x30a20238, 0x3820033,  0xea882ba,  0x300a20b8, 0x380222b7,
    0x308a80ba, 0x3882b7,   0xcaa3c,    0x38020233, 0x322a0a3a, 0x328a023a,
    0x38a2a03a, 0xc280b5,   0xca0aa3c,  0x32a20ba,  0xc822a3a,  0x382a83c,
    0xeaa00bd,  0x38820ab7, 0x382234,   0xe2a88bc,  0xc0200b2,  0xea208ba,
    0x38200b3,  0xea8823a,  0x3a0a2a3a, 0xc0282b7,  0x320a22b8, 0x3a2280b8,
    0x3a222838, 0xe8a883b,  0x32a203a,  0xc822aba,  0x322a803c, 0xeaa003d,
    0x38820a37, 0x3822b7,   0xe88a83a,  0x300a2038, 0x308a803a, 0xcaa20bc,
    0x388234,   0xcaabd,    0x322a0aba, 0x38a02b7,  0x328a02ba, 0xc28035,
    0x38222037, 0xc808a38,  0xcaa88bd,  0x308a02b8, 0xcaaaabd,  0x30222037,
    0xe8a083a,  0x38028237, 0xe8a22ba,  0x30a20b8,  0x328a83a,  0xc228aba,
    0xc008b3,   0xe2a0aba,  0xc022237,  0x3802b3,   0x3288238,  0x38a8abb,
    0x3aa8bd,   0x3a0a2238, 0x38aa083c, 0x32220037, 0xe088235,  0xe8a08ba,
    0x380282b7, 0xe8a223a,  0x30a2038,  0xc808aba,  0x308a0238, 0xcaaaa3d,
    0x328a223a, 0x38a8a3b,  0x3aa83d,   0x322200b7, 0x320aa23c, 0x328a8bb,
    0x3882aabd, 0xc228a3a,  0xe2a0a3a,  0xc00832,   0xc0222b7,  0x3a8a82ba,
    0xe0a8239,  0xe2a08ba,  0x3a2a8abc, 0x32a80bc,  0xe0a283a,  0xe0a037,
    0x328220b7, 0x32a28a3b, 0x300aa0bc, 0xc20233,   0x3a8a203a, 0xc08a38,
    0x38a2aba,  0x32820237, 0x3002a2ba, 0x3a8aa23c, 0xc2a28ba,  0x300a80b9,
    0xc008835,  0xe0222b7,  0xe0a0b7,   0x32a28abb, 0x32822037, 0x300aa03c,
    0xc202b3,   0xe0a82b9,  0x3a2a8a3c, 0xe2a083a,  0x32a803c,  0xe0a28ba,
    0x3a2aa83d, 0xc2a283a,  0x300a8039, 0xe022237,  0xc0882b7,  0x38a2a3a,
    0xc08aba,   0x32aa023d, 0x328202b7, 0x3002a23a, 0x3a8aa2bc, 0xe20a37,
    0x308208b4, 0x3a883a,   0xe88a8bb,  0x3a8a0aba, 0xc02a38,   0x3a0a80b9,
    0x3282237,  0x320a28ba, 0x3a022b7,  0x382aabd,  0x388a8abb, 0x30aa8bd,
    0xc088b7,   0xc820034,  0xc2a8abc,  0x3888837,  0x388aa8bd, 0xe22b7,
    0xe888037,  0x308a823a, 0xca882ba,  0xe208aba,  0x382aa3d,  0x3a02234,
    0x388a8a3b, 0x30aa83d,  0xc08835,   0xe20ab7,   0x30820834, 0x3a88ba,
    0x3a8a0a3a, 0xe2237,    0xe8880b7,  0xca8823a,  0x3aa2223a, 0xc2a8a3c,
    0xc8200b4,  0x38888b7,  0x388a0838, 0xc20a0b7,  0x32022237, 0x38a2a0ba,
    0x3aa2a8bc, 0x3282a039, 0xe822037,  0x3228038,  0x30828838, 0xc0aabd,
    0xe82a2ba,  0x3a2803a,  0xe82237,   0xe0a2a3a,  0xe88a238,  0xc8a20b8,
    0x3aaa223d, 0x3aaa28bd, 0x322a23b,  0x382aa2bd, 0x38220035, 0x3a2a23b,
    0xc8aaa3d,  0x3a2aba,   0xc0aa3c,   0x3a280ba,  0xe822b7,   0xe0a2aba,
    0x320222b7, 0xc20a037,  0x3802aa3d, 0x3282a0b9, 0x308288b8, 0x32280b8,
    0x382200b5, 0x302aa3d,  0x3a2a2bb,  0xe88a2ba,  0xc8a2038,  0x322a2bb,
    0x30aa0a3c, 0x38088b7,  0xe2b0,     0x30822b7,  0x3202a0b9, 0xe82b7,
    0x38aa2abc, 0x3202b3,   0xe028237,  0x38a28a3b, 0xcaa803d,  0x30a88ba,
    0x38a22038, 0x3a8208b7, 0x3a8a3a,   0x3a2a0aba, 0xe88237,   0x32822b7,
    0x3202a039, 0x322228b8, 0x320aa2bc, 0xe8237,    0x32a00b8,  0x320233,
    0x30aa0abc, 0x3808835,  0x3882aa3d, 0xe230,     0x3082234,  0x3a2a0a3a,
    0xe882b7,   0x38a28abb, 0xe0282b7,  0xcaa80bd,  0x3a820837, 0x38a220b8,
    0xc2032,    0x32aa223d, 0x3a8aabd,  0xc0232,    0x38822035, 0x322aa23d,
    0x3008032,  0x320aa8bd, 0x32aa82bd, 0x38822a3a, 0x328a8abb, 0x328aa2bc,
    0xe828aba,  0xea8a2bb,  0xc0088b7,  0xea080b7,  0x38220835, 0x30a200b8,
    0x320a8ba,  0x30288b8,  0x322a3a,   0xc888b7,   0xcb0,      0x3aa2a0ba,
    0xc888837,  0x3a0aaa3d, 0xc80833,   0x30080b3,  0x320aa83d, 0x32aa823d,
    0x328aa23c, 0x32aa22bd, 0x3a8aa3c,  0xc02b3,    0x322aa2bd, 0x3028838,
    0xc2aaa3d,  0xc88837,   0x3aa2a03a, 0xc8888b7,  0xc808b3,   0xe828a3a,
    0x322a08ba, 0xea08037,  0x30a20038, 0x320a839,  0x388220b5, 0x302aba,
    0x3a88a3a,  0x3aa2023a, 0xeaa0bd,   0x302a20ba, 0x32aaa0bd, 0x328a82ba,
    0xe8a8abb,  0x380aabd,  0x3020834,  0x322a20bb, 0x3028aba,  0xea0037,
    0xc2082b7,  0x328034,   0x3088b7,   0x382aa03d, 0x3a22a8bc, 0x3aa28a3b,
    0x32aaa03d, 0x328a823a, 0xe8a8a3b,  0x322a203b, 0x30208b4,  0x3028a3a,
    0x30a883a,  0x302a38,   0x3a828838, 0x3a88abb,  0x3aa202ba, 0x302a203a,
    0xeaa03d,   0x388a08b8, 0x3a22a83c, 0x3aa28abb, 0xe8220b7,  0x388aa03c,
    0x300a00b6, 0xea00b7,   0xc208234,  0x3280b4,   0x308835,   0x30aa203c,
    0xeaa2a3d,  0xe22a03a,  0x3088235,  0xea82ba,   0x32a2a8bc, 0x320aa3c,
    0x32aa03d,  0x30aaaa3d, 0xeaaa03d,  0x3aaa23d,  0xc22aa3d,  0x308a038,
    0x3a2aaabd, 0x38a20a38, 0xc088837,  0x38a0237,  0xc02a0b9,  0x380a00b6,
    0xe80a0b7,  0xea823a,   0x30882b7,  0x32a2a83c, 0x320aabd,  0x32aa0bd,
    0x30aaaabd, 0x30aa20bc, 0xeaa2abd,  0xe22a0ba,  0x388a0ab8, 0xc808835,
    0xc0888b7,  0xc02a039,  0x380a0036, 0xe80a036,  0xe202b3,   0xeaaa0bd,
    0xca08037,  0x3aaa2bd,  0xc22aabd,  0x308a0b8,  0x38a20ab8, 0x3a2aaa3d,
    0x320a88ba, 0x3aa80bd,  0xc020233,  0x30a8aba,  0xea8a03a,  0x322a083a,
    0x3820233,  0xca08237,  0xe28a8bb,  0x3a0a22b8, 0xea880ba,  0xc2a0b9,
    0xea0a238,  0x3222a2bb, 0x382033,   0xea2223a,  0x32aa0abd, 0x328a003a,
    0xc828037,  0x3888237,  0x32a0038,  0x382a20ba, 0xc028a3a,  0x302aa83d,
    0x320b3,    0x38202b3,  0xca082b7,  0x382a23a,  0x382aa0bd, 0xc2a039,
    0xea8803a,  0xea0a2ba,  0x320a883a, 0x3aa803d,  0xea0a037,  0x30a8a3a,
    0xc0202b3,  0xea8a0ba,  0x380202b3, 0xc8280b7,  0x328aaa3d, 0x382a203a,
    0xc028aba,  0x302aa8bd, 0x32031,    0x3820b3,   0xea222ba,  0x32aa0a3d,
    0x328a00ba, 0x300a0036, 0xe2888b8,  0x32228aba, 0x3a228a3a, 0x30a22b8,
    0xc08a8bb,  0x38028036, 0x30820a37, 0xe8a20ba,  0xe02aabd,  0x328838,
    0xeaa283d,  0x3a8a22ba, 0xc022035,  0x302b3,    0xc00a839,  0xe2a8abc,
    0x3a08a38,  0x3a8202b7, 0x3822aabd, 0x3aaa8abd, 0x30a2238,  0x380280b6,
    0xc08a83a,  0x30820ab7, 0xe02aa3d,  0xe8a203a,  0x38a2a23b, 0xe02835,
    0xe288838,  0x32228a3a, 0x3a08aba,  0x3822aa3d, 0x3aaa8a3d, 0xeaa28bd,
    0xc0220b5,  0x30231,    0xc00a8ba,  0xe2a8a3c,  0xe2a2a3b,  0xc20032,
    0x388a0a38, 0x3aaa023d, 0x32a82bc,  0xca080b7,  0xc0a839,   0x382a80bc,
    0x3a8280b7, 0xc00aabd,  0x3aaaa23d, 0x3a0aa23c, 0xcaa22bc,  0x32a2083a,
    0xe0a238,   0x3a8aa03c, 0x32228b8,  0x3a2a2abb, 0xe020233,  0xcaa003c,
    0x3a2a20bb, 0xc00a34,   0x300a82b9, 0xc00aa3c,  0x3a0aa2bc, 0xcaa223c,
    0x32a208ba, 0xe0a2ba,   0xe2a2abb,  0x30a08b7,  0x3aaa02bd, 0x38a2a2bb,
    0x32a823c,  0xc0a8ba,   0xcaa00bc,  0x3a2a203b, 0x300a8239, 0xc00ab7,
    0x3a8aa0bc, 0x30a2ba,   0x3222838,  0x38020032, 0xe0202b3,  0xc0a28ba,
    0x3a22b7,   0x382280b8, 0x3222a03a, 0x382a02b9, 0x3808a38,  0xc820234,
    0x3a0a8239, 0x3a0228b8, 0xc2a08b9,  0xc0aaa3d,  0x328a2a3b, 0xe888237,
    0x38a283a,  0x388aabd,  0x300a0b7,  0x3a8a8abb, 0xe20b3,    0xe2a28bb,
    0xc0a8aba,  0x302200b5, 0x3222a0ba, 0x3808aba,  0x3a8a223a, 0x3a820237,
    0xc0a283a,  0x3a2237,   0x388aa3c,  0x3a8a8a3b, 0x300a036,  0xe2033,
    0xc0a8a3a,  0xe2a283b,  0x3a0a82b9, 0xc8202b4,  0x3a022838, 0x3282837,
    0xc2a0839,  0x328a2abb, 0x38a28ba,  0xe8882b7,  0x3a0a8039, 0x302a0ab9,
    0x3a02a0b9, 0x30822035, 0xc0a0236,  0xe8288b8,  0xc2aa8bd,  0xe22a3a,
    0xcaaa23d,  0x388a8bb,  0x38a823a,  0xc2220b7,  0xc8a8abb,  0xe88a038,
    0xe820837,  0x320220b5, 0x30a288ba, 0x3aaa0abd, 0xe2088b7,  0xc2a883c,
    0xc8a22b8,  0xe02aba,   0xc88a83a,  0x3282aba,  0xea0a0b7,  0xc2aa83d,
    0xcaaa2bd,  0xe22aba,   0x38a82ba,  0x388a83a,  0x302a0a39, 0x3a02a039,
    0x308220b5, 0xc0a02b6,  0xe828838,  0xc2a88bc,  0xe02a38,   0xc8a2238,
    0xc88a8bb,  0x3282a38,  0xc222037,  0xc8a8a3b,  0xe88a0b8,  0xe8208b7,
    0xea2ba,    0x32022035, 0xe208835,  0x3aaa2a3d, 0xc220235,  0x38aa0bc,
    0x388aa2bc, 0xe0b0,     0xe028036,  0x302a83c,  0xcaa823d,  0xc8aa83d,
    0xca228b8,  0x3a0a37,   0x30222838, 0xe808033,  0xc8234,    0x380a8ba,
    0xe0a0a37,  0xc22b7,    0xe08aba,   0xe88037,   0x3802234,  0x38aa883d,
    0x388aa23c, 0xe030,     0xe0280b6,  0xc2202b5,  0x32a2aabd, 0x380a839,
    0xc2234,    0xe0a0ab7,  0xe08a38,   0xe880b7,   0xe008835,  0x38aa88bd,
    0x302a8bc,  0xcaa82bd,  0xc8aa8bd,  0x3a0ab7,   0xca22838,  0x302228b8,
    0xe8080b3,  0xc82b7,    0x322aa03d, 0xca2a0ba,  0x3a028a3a, 0x3aa20aba,
    0x3a0a238,  0x30a2aabd, 0x3828237,  0xe20a839,  0x3022a8bc, 0x32028aba,
    0x3a2aabd,  0xc8aabd,   0x3082a83c, 0x382a2ba,  0x30a280ba, 0x3aa00ba,
    0x320032,   0xe22838,   0x3aa20a3a, 0x30a2aa3d, 0x3a0a2ba,  0x38282b7,
    0xe20a8ba,  0x3aa083a,  0x322aa0bd, 0xca2a03a,  0x3a028aba, 0xc00b1,
    0xe30,      0x3200b2,   0x3a2a88bc, 0x380a8a3a, 0xe228b8,   0x382a0239,
    0x3022a83c, 0x3a2aa3d,  0xc8aa3c,   0x3082a8bc, 0x30a2803a, 0xe82a83c,
    0x302a22ba, 0x3020ab7,  0x3a8a823a, 0xc0aaabd,  0xc8a8bb,   0x388a2238,
    0x3082aabd, 0xeaa2bd,   0x328a80ba, 0xe2280b8,  0x3a822b7,  0xca88ba,
    0x3a2288b8, 0x3aa22ba,  0x3a020233, 0xe20033,   0x3082aa3d, 0x328a803a,
    0xeaa23d,   0xe8a0a3a,  0xe80aa3c,  0x3a82237,  0x302a223a, 0x3020a37,
    0xc8a83a,   0x388a22b8, 0x3802a039, 0xca883a,   0x3a228838, 0x3aa223a,
    0x388a0238, 0x3a0202b3, 0x302a803c, 0x382282b8, 0x38222b7,  0xca0b7,
    0xea0aabd,  0xca28a3b,  0x322a00ba, 0xc020ab7,  0xe088837,  0x3aaa03d,
    0x380a883a, 0xea80ba,   0xe8aba,    0xe08a238,  0xeaaa23d,  0xea2a2bb,
    0xe8aa23c,  0x308a238,  0x30aa22bc, 0xc8222b7,  0xea203a,   0x30aa823d,
    0xca0837,   0x380a02b6, 0xc020a37,  0xe0888b7,  0x3aaa0bd,  0xe028b7,
    0xea803a,   0x3822237,  0xca034,    0xea0aa3c,  0x322a003a, 0xca28abb,
    0xc822237,  0x30aa82bd, 0xea20ba,   0xe2a23b,   0x380a0236, 0xca08b7,
    0xe8a3a,    0x32a2883a, 0xeaaa2bd,  0xea2a23b,  0x308a2ba,  0xe8aa2bc,
    0x30aa223c, 0x32aa8a3d, 0x3aa82bd,  0x322b7,    0xea8a23a,  0x382a22ba,
    0xea28a3b,  0x3a0a20b8, 0xea2203a,  0xc2a2ba,   0x38022b7,  0xcaa8bd,
    0xeaa0a3d,  0xc2a2a3a,  0x308a0038, 0xc008234,  0xc828237,  0xca20238,
    0x30a0ab7,  0x32a2aa3d, 0xeaa3d,    0x3a2aa8bd, 0x3808b3,   0xea28abb,
    0x3a0a2038, 0xea220ba,  0xc2a23a,   0xc0ab7,    0x3aa823d,  0x32aa8abd,
    0x32233,    0xe288a38,  0x382a223a, 0x382a823c, 0x30a0a37,  0x3aaaa0bd,
    0xeaabd,    0x380833,   0xeaa0abd,  0xcaa83d,   0xc2a2aba,  0xc0082b7,
    0xca202b8,  0xc8282b7,  0x302a80bc, 0xc028b7,   0x38228038, 0x3a222a3a,
    0x302a88bc, 0x322a8a3c, 0xc80aa3c,  0x380ab7,   0x328a2bb,  0x388837,
    0x3a8a88bb, 0xe2aa0bd,  0x3822a23b, 0x388a02b8, 0x3aaa823d, 0x32a02b8,
    0x300b1,    0xc82a23a,  0x308a283a, 0xcaaabd,   0x380a22b8, 0xe2a823c,
    0xe08a2ba,  0x3a220837, 0x380a88ba, 0x380a34,   0x3888b7,   0x328a23a,
    0xe2aa03d,  0x3a8a883b, 0x3a2a883c, 0x3822a2bb, 0xc02835,   0x3a222aba,
    0x302a883c, 0x308a28ba, 0xcaaa3d,   0xe2a82bc,  0x3a2208b7, 0x3aaa82bd,
    0x32a0238,  0xc82a2ba,  0x300288b8, 0x3aa23a,   0x3a0aa03c, 0xe0a37,
    0xc820ab7,  0x3a0a8aba, 0x3aaa003d, 0x3a2a22bb, 0x32822aba, 0xc02aba,
    0x302a0839, 0x3a2a823c, 0x328208b7, 0xe0aaa3d,  0xc228b8,   0x3202aba,
    0xe020033,  0x32020834, 0x328a883b, 0xcaa023c,  0x3a22037,  0x32a2223a,
    0xc0aa03c,  0xe0a08b7,  0xcaa203c,  0x3a2a82bc, 0x302a08b9, 0xe0aaabd,
    0x32820837, 0x3a2222b7, 0xc22838,   0x382aa23d, 0x30028838, 0x3aa2ba,
    0xe0ab7,    0x3a0aa0bc, 0x3a0a8a3a, 0xc820a37,  0x3aaa00bd, 0x3a2a223b,
    0x3802a8bc, 0xc0aa0bc,  0x380a28ba, 0xe0a0837,  0xe288aba,  0x3202a38,
    0xe0200b3,  0xca280ba,  0xcaa02bc,  0x3a220b7,  0x382a82bc, 0x30020834,
    0x380a8aba, 0x3228aba,  0x3a20b7,   0xca88a3a,  0x38882b7,  0x38233,
    0x382222b7, 0xc0a8239,  0x3a033,    0xe0a883a,  0xc08aa3c,  0x32880b8,
    0x3a820a37, 0x3222a3a,  0x300a2ba,  0x3228a3a,  0x3a2037,   0x380aa3c,
    0xca88abb,  0x382b7,    0x300208b4, 0x3802a83c, 0x3222aba,  0x300a238,
    0x38222237, 0xc0a82b9,  0x320aaabd, 0x3a0b7,    0xe0a88ba,  0x3288038,
    0xc08aabd,  0x3a820ab7, 0x30822237, 0x38a280ba, 0xcaaa03d,  0xcaa8abd,
    0xc0a0036,  0x3022aabd, 0x3a8a083a, 0xe0833,    0xca0a839,  0x38a803a,
    0x3a02a2ba, 0xc228238,  0xc8a08b8,  0xe2a2bb,   0x388aa83d, 0x3a222037,
    0xca8a8bb,  0xe82aabd,  0xe0aa83d,  0x302aaa3d, 0xc2222b7,  0x3a8a08ba,
    0x320208b4, 0xe08b3,    0x38a80ba,  0x388a0038, 0x3a02a23a, 0x308222b7,
    0x38a2803a, 0xcaaa0bd,  0xcaa8a3d,  0xc0a00b6,  0x3022aa3d, 0xca8a83a,
    0xe82aa3d,  0xe0aa8bd,  0x30a0837,  0xc222237,  0x328aa83d, 0xc2282b8,
    0x38aa03c,  0xc8a0838,  0x380a283a, 0xc220035,  0x300aaa3d, 0x3a8228b8,
    0x32828838, 0x3a0282b7, 0xc8032,    0x3088a38,  0xe28a2bb,  0x382aa8bd,
    0xe808234,  0x30828237, 0xe00aabd,  0xc2a38,    0xe00ab7,   0x30028b7,
    0xc8a883b,  0x320288b8, 0xe82837,   0xe0a8a3a,  0xe2222b7,  0x382aaabd,
    0x328288b8, 0x3a028237, 0xc80b3,    0xca0a037,  0x38a0ab7,  0xc2200b5,
    0x300aaabd, 0x38022035, 0x3a02aa3d, 0x3a822838, 0x3002835,  0x32828b7,
    0xc8a88bb,  0x32028838, 0xe828b7,   0xe222237,  0xe0a8aba,  0x382aaa3d,
    0x328282b7, 0xe8082b7,  0x308282b7, 0xe00aa3c,  0xc2aba,    0xe00a34};
}  // namespace chis
