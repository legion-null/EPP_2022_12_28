#include "Epp.h"

#if EPP_CURRENT_OS == EPP_OS_ANDROID

using namespace Epp;
using namespace Epp::base;

using namespace Epp::graphics;
using namespace Epp::gui;

i32 gui_Screen_Android_test_main(i32 argc, c8 **argv) {
	(void) argc;
	(void) argv;

	GUIService *guiService = GUIService::GetDefaultIM();
	Screen *screen = guiService->getScreen();
	Painter *painter = screen->getPainter();

	painter->setColor(C(White));
	painter->fillRect(0, 0, screen->getWidth(), screen->getHeight());
	painter->setColor(C(Red));
	painter->fillRect(0, 0, screen->getWidth() / 2, screen->getHeight());
	painter->setColor(C(Green));
	painter->fillRect(screen->getWidth() / 2, 0, screen->getWidth() / 2, screen->getHeight());

	screen->refresh();
	Thread::Sleep(1);

	while (true)
		screen->refresh();

	return 0;
}

#endif
