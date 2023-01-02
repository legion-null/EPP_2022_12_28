#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

using namespace Epp::graphics;
using namespace Epp::gui;

i32 graphics_Painter_test_main(i32 argc, c8 **argv) {
	(void) argc;
	(void) argv;

	EPP_CODE_LOCATE();

	Screen* scr = Screen::GetDefaultScreen();
	Painter* painter = new Painter_Software(scr);

	painter->setColor(C(White));
	painter->drawRect(100, 100, 500, 500);
	painter->fillRect(200, 200, 200, 200);
	painter->drawCircle(400, 400, 100);

	while (true)
		scr->refresh();

	return 0;
}
