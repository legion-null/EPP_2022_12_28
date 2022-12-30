#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

using namespace Epp::graphics;

namespace Epp {
namespace gui {

E_CLASS_DEF(Epp::gui::Screen)

void Screen::Static() { // 静态块，类初始化时将会执行块内代码，为了防止Epp类型构建系统出错，静态块内的代码必须与类型加载顺序无关

}

Screen::Screen() {

}

void Screen::destroy() {
	delete this;
}

Screen::Screen(i32 w, i32 h, Color::Type colorType, Rot rot) :
		Base(w, h, colorType, rot) {
}

void Screen::refreshRect(i32 x0, i32 y0, i32 w, i32 h) {
	rMapPixel(x0, y0);
	this->display->copyFrom(this, x0, y0, w, h, x0, y0);
}

void Screen::refresh() {
	this->display->copyFrom(this);
}

void Screen::test() {
	static const EColor testColor[7] = { C(Red), C(Orange), C(Yellow), C(Green), C(Cyan), C(Blue), C(Purple) };

	for (i32 i = 0;; i++) {
		Base::clear(testColor[i % 7]);

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
