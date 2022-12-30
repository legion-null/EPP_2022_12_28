#include "Epp.h"

// 单元测试
#ifdef CURRENT_OS_ANDROID
#define TEST_UNIT	gui_Screen_Android_test_main
#endif

#ifdef CURRENT_OS_LINUX
#define TEST_UNIT	gui_Screen_SDL2_test_main
#endif

// 声明单元测试入口函数
extern i32 TEST_UNIT(i32 argc, c8 **argv);

i32 epp_application_main(i32 argc, c8 **argv) {
	return TEST_UNIT(argc, argv);
}

