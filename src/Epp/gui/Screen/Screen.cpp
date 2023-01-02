#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

using namespace Epp::graphics;

namespace Epp {
namespace gui {

const Class *Screen::ClassInfo = Class::Register<Screen, Layer>("Epp::gui::Screen", nullptr);

Screen* Screen::GetDefaultScreen() {
	EPP_CODE_LOCATE();
	return GUIService::GetDefaultGUIService()->getDefaultScreen();
}

Screen::Screen() {

}

Screen::Screen(i32 w, i32 h, Color::Type colorType, Rot rot) :
		Layer(w, h, colorType, rot) {
}

Screen::Screen(String *title, i32 w, i32 h, graphics::Color::Type colorType, graphics::Rot rot) :
		Layer(w, h, colorType, rot) {
	this->title = title;
}

String* Screen::getTitle() {
	return this->title;
}

void Screen::setTitle(String *title) {
	this->title = title;
}

void Screen::refreshRect(i32 x0, i32 y0, i32 w, i32 h) {
	rMapPixel(x0, y0);
	this->display->copyFrom(this, x0, y0, w, h, x0, y0);
}

void Screen::refresh() {
	this->display->copyFrom(this);
}

void Screen::test() {
	static Color *testColor[7] = { C(Red), C(Orange), C(Yellow), C(Green), C(Cyan), C(Blue), C(Purple) };

	for (i32 i = 0;; i++) {
		Layer::clear(testColor[i % 7]);

//		for (i32 sideLength = 100, y = 0; y + sideLength <= this->h; y += sideLength) {
//			for (i32 x = 0; x + sideLength <= this->w; x += sideLength) {
//				if (i % 2 == 0 and Diff(x, y) % (2 * sideLength) == 0) {
//					refreshRect(x, y, sideLength, sideLength);
//				} else if (i % 2 == 1 and Diff(x, y) % (2 * sideLength) == sideLength) {
//					refreshRect(x, y, sideLength, sideLength);
//				}
//			}
//		}
		refresh();
		//Thread::Sleep(1);
	}
}

}
}
