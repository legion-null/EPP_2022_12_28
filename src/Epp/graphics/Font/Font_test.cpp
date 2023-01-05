#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

using namespace Epp::graphics;
using namespace Epp::gui;

i32 graphics_Font_test_main(i32 argc, c8 **argv) {
	(void) argc;
	(void) argv;

	Painter::SetDefaultIMType(Painter::Software);

	GUIService *guiService = GUIService::GetDefaultIM();
	Screen *screen = guiService->getScreen();
	Painter *painter = screen->getPainter();

	screen->clear(C(White));
	painter->setFont((Font*)Font_CMF::ASCII_16X24_1BPP);
	painter->drawCharacter(10, 10, 20, 24, 0);
	painter->drawString(10, 40, 800, 100, S("Hello,World"));

	painter->setFont((Font*)Font_CMF::UTF_BASE_CHINESE_24X24_4BPP);
	painter->drawCharacter(10, 70, 24, 24, U'你');
	painter->drawCharacter(34, 70, 24, 24, U'好');
	painter->drawCharacter(58, 70, 24, 24, U'世');
	painter->drawCharacter(82, 70, 24, 24, U'界');

	while (true) {
		screen->refresh();
	}

	return 0;
}
