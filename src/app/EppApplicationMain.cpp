#include "Epp.h"

// 单元测试
#define TEST_UNIT	graphics_Painter_test_main

// 声明单元测试入口函数
extern i32 TEST_UNIT(i32 argc, c8 **argv);

i32 epp_application_main(i32 argc, c8 **argv) {
	return TEST_UNIT(argc, argv);
}
