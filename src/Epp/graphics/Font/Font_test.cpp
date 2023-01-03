#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

using namespace Epp::graphics;
using namespace Epp::gui;

i32 graphics_Font_test_main(i32 argc, c8 **argv) {
	(void) argc;
	(void) argv;

	GUIService *guiService = GUIService::GetDefaultIM();
	Screen *screen = guiService->getScreen();
	Painter *painter = screen->getPainter();

	screen->clear(C(White));
	painter->setFont((Font*)Font_CMF::ASCII_16X24_1BPP);
	painter->drawCharacter(10, 10, 20, 20, 0);
	painter->drawString(10, 50, 800, 100, S("Hello,World"));

	while (true) {
		screen->refresh();
	}

	return 0;
}
