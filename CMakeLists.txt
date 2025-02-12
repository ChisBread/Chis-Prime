cmake_minimum_required (VERSION 3.1)
PROJECT(Chis++)
SET(CMAKE_CXX_STANDARD 17)
#头文件目录
INCLUDE_DIRECTORIES(./)
#源文件目录
AUX_SOURCE_DIRECTORY(board DIR_SRCS)
AUX_SOURCE_DIRECTORY(resource DIR_SRCS)
AUX_SOURCE_DIRECTORY(search DIR_SRCS)
AUX_SOURCE_DIRECTORY(utils DIR_SRCS)
#添加要编译的可执行文件
ADD_EXECUTABLE(${PROJECT_NAME} ${DIR_SRCS} main.cpp) #chis本体
ADD_EXECUTABLE(pbrain-${PROJECT_NAME} ${DIR_SRCS} gomocup/main.cpp) #chis本体
#LINK
SET(THREADS_PREFER_PTHREAD_FLAG ON)
FIND_PACKAGE(Threads REQUIRED)
TARGET_LINK_LIBRARIES(pbrain-${PROJECT_NAME} Threads::Threads)
#环境相关
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
    #第三方库 GTest
    SET(GTEST_ROOT ${PROJECT_SOURCE_DIR}/thirdparty/googletest/googletest)
    INCLUDE_DIRECTORIES(${GTEST_ROOT}/include)
    ADD_SUBDIRECTORY(thirdparty/googletest gtest)    
    #测试源文件目录
    AUX_SOURCE_DIRECTORY(board TEST_SRCS)
    AUX_SOURCE_DIRECTORY(resource TEST_SRCS)
    AUX_SOURCE_DIRECTORY(search TEST_SRCS)
    AUX_SOURCE_DIRECTORY(utils TEST_SRCS)
    AUX_SOURCE_DIRECTORY(test TEST_SRCS)
    #测试文件
    ADD_EXECUTABLE(TEST ${TEST_SRCS} ${GTEST_ROOT}/src/gtest_main.cc)#测试
    #添加测试
    ADD_TEST(NAME TEST COMMAND TEST)
    #添加可执行文件所需要的库 e.g libm.so
    TARGET_LINK_LIBRARIES(TEST gtest gtest_main)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")#win就生成可执行文件，不搞测试
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MD /Ox")
endif()