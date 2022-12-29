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
		This(nullptr, w, h, colorType, rot) {
}

Screen::Screen(byte *fb, i32 w, i32 h, Color::Type colorType, Rot rot) :
		Base(w, h, colorType, rot) {
	if (fb != nullptr){
		this->display = new FrameBuffer(fb, w, h, Color::GetBPP(colorType));
	}
}

void Screen::refreshRect(i32 x0, i32 y0, i32 w, i32 h) {
	rMapPixel(x0, y0);
	this->display->copyFrom(this, x0, y0, w, h, x0, y0);
}

void Screen::refresh() {
	this->display->copyFrom(this);
}

void Screen::test() {
	static const EColor testColor[7] = { TColor(Red), TColor(Orange), TColor(Yellow), TColor(Green), TColor(Cyan), TColor(
			Blue), TColor(Purple) };

	for (i32 i = 0;; i++) {
		clear(testColor[i % 7]);
		refresh();
	}
}

}
}
