#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

using namespace Epp::graphics;
using namespace Epp::gui;

i32 graphics_Painter_test_main(i32 argc, c8 **argv) {
	(void) argc;
	(void) argv;

	EPP_CODE_LOCATE();

	Screen *scr = Screen::GetDefaultScreen();
	Painter *painter = scr->getPainter();

	painter->setColor(Color::White);
	painter->drawRect(100, 100, 500, 500);
	painter->fillRect(200, 200, 200, 200);
	painter->drawCircle(400, 400, 100);

	i32 size = 100;
	u32* fb = new u32[size * size];

	for (i32 x = 0; x < size; x++)
		for (i32 y = 0; y < size; y++) {
			if (y < size / 2) { // 上半
				if (x >= 0 and x < size / 2) { // 左上
					fb[y * size + x] = Color::Red;
				} else { //右上
					fb[y * size + x] = Color::Green;
				}
			} else { // 下半
				if (x >= 0 and x < size / 2) { //左下
					fb[y * size + x] = Color::Blue;
				} else { //右下
					fb[y * size + x] = Color::Yellow;
				}
			}

		}

	Image *img1 = new Image((u8*) fb, size, size, Color::XRGB8888); // 原色
	Image *img2 = new Image((u8*) fb, size, size, Color::RGBX8888); // R G 0 B
	Image *img3 = new Image((u8*) fb, size, size, Color::ARGB8888); //
	Image *img4 = new Image((u8*) fb, size, size, Color::RGBA8888);

	EPP_DEBUG("%s", "1:");
	painter->drawImage(0, 0, size, size, img1);
	EPP_DEBUG("%s", "2:");
	painter->drawImage(110, 0, size, size, img2);
	EPP_DEBUG("%s", "3:");
	painter->drawImage(220, 0, size, size, img3);
	EPP_DEBUG("%s", "4:");
	painter->drawImage(330, 0, size, size, img4);

	while (true)
		scr->refresh();

	return 0;
}
