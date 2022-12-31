#include "Epp.h"

#if EPP_CURRENT_OS == EPP_OS_ANDROID

using namespace Epp;
using namespace Epp::base;

using namespace Epp::graphics;
using namespace Epp::gui;

i32 gui_Screen_Android_test_main(i32 argc, c8 **argv) {
	(void) argc;
	(void) argv;

	EScreen scr = new Screen_Android();

	scr->test();

	while (true)
		;

	return 0;
}

#endif
