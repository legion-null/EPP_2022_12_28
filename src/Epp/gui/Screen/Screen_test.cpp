#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

using namespace Epp::gui;

i32 gui_Screen_test_main(i32 argc, c8 **argv) {
	(void) argc;
	(void) argv;

	GUIService *guiService = GUIService::GetDefaultIM();
	Screen *screen = guiService->getScreen();

	screen->test();

	return 0;
}
