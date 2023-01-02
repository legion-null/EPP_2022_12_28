#include "Epp.h"

#if EPP_MODULE_SDL2_SUPPORT == EPP_TRUE

using namespace Epp;
using namespace Epp::base;

using namespace Epp::graphics;
using namespace Epp::gui;

i32 gui_Screen_SDL2_test_main(i32 argc, c8 **argv) {
	(void) argc;
	(void) argv;

	Screen* scr = new Screen_SDL2();

	scr->test();

	while (true)
		;

	return 0;
}

#endif
