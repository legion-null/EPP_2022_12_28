#include "Epp.h"

// 单元测试
#define TEST_UNIT	gui_Screen_SDL2_test_main

// 声明单元测试入口函数
extern i32 TEST_UNIT(i32 argc, c8 **argv);

i32 main(i32 argc, c8 **argv) {

	return TEST_UNIT(argc, argv);
}
