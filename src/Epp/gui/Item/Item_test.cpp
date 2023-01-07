#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

using namespace Epp::graphics;
using namespace Epp::gui;

i32 base_Item_test_main(i32 argc, c8 **argv) {
	(void) argc;
	(void) argv;

	GUIService *guiService = GUIService::GetDefaultIM();
	Screen *screen = guiService->getScreen();

#if EPP_CURRENT_OS == EPP_OS_LINUX
	// 15.6寸屏幕
	screen->setPPM(5.56, 5.56);
	screen->setSlightDistance(550);
#endif

#if EPP_CURRENT_OS == EPP_OS_ANDROID
	// 手机屏幕
	screen->setPPM(15.54, 15.54);
	screen->setSlightDistance(300);
#endif

	Zoom2D::SetDefaultZoom(*screen, Zoom2D::Physics);

	Painter *painter = screen->getPainter();
	Item *item = new Item(10, 10, 10, 10);

	painter->setColor(Color::White);
	painter->drawRect(item->getX_px(), item->getY_px(), item->getW_px(), item->getH_px());

	while (true) {
		screen->refresh();
	}

	return 0;
}
