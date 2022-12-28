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

Screen::Screen(i32 w, i32 h, graphics::Color::Type colorType, graphics::Rot rot) :
		Base(w, h, colorType, rot) {
}

void Screen::refresh() {
	refreshRect(0, 0, this->w, this->h);
}

void Screen::test() {
	static const EColor testColor[7] = { TColor(Red), TColor(Orange), TColor(Yellow), TColor(Green), TColor(Cyan), TColor(Blue),
			TColor(Purple) };

	for (i32 i = 0;; i++) {
		clear(testColor[i % 7]);
		refresh();
	}
}

}
}
