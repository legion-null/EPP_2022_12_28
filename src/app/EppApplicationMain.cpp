#include "Epp.h"

#define EPP_TEST_UNIT_FUNC(pkg,object)		pkg##_##object##_test_main

// 单元测试
#define EPP_TEST_UNIT						EPP_TEST_UNIT_FUNC(graphics,Font)

// 声明单元测试入口函数
extern i32 EPP_TEST_UNIT(i32 argc, c8 **argv);

i32 epp_application_main(i32 argc, c8 **argv) {
	return EPP_TEST_UNIT(argc, argv);
}
