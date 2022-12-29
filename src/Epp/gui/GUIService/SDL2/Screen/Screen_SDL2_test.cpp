#include "Epp.h"

#ifdef USE_LIB_SDL2

using namespace Epp;
using namespace Epp::base;

using namespace Epp::graphics;
using namespace Epp::gui;

i32 gui_Screen_SDL2_test_main(i32 argc, c8 **argv) {
	(void) argc;
	(void) argv;

	EScreen_SDL2 scr = new Screen_SDL2();

	scr->test();

	while (true)
		;

	return 0;
}

#endif
