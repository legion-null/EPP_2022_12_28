#ifdef USE_SDL2_SUPPORT

#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

using namespace Epp::graphics;

#include "../About_SDL2.h"

namespace Epp {
namespace gui {

E_CLASS_DEF(Epp::gui::Screen_SDL2)

void Screen_SDL2::Static() { // 静态块，类初始化时将会执行块内代码，为了防止Epp类型构建系统出错，静态块内的代码必须与类型加载顺序无关

}

Screen_SDL2::Screen_SDL2() :
		This(800, 600, Color::XRGB8888, Rot_0) {

}

void Screen_SDL2::destroy() {
	SafeDelete(this->csdl2);
}

Screen_SDL2::Screen_SDL2(i32 w, i32 h, Color::Type colorType, Rot rot) :
		This(S("Epp SDL2_ScreenSimulator Author:legion"), w, h, colorType, rot) {
}

Screen_SDL2::Screen_SDL2(base::EString title, i32 w, i32 h, Color::Type colorType, Rot rot) :
		Base(w, h, colorType, rot) {

	this->title = title->clone();

	this->csdl2 = new struct CSDL2;

	::SDL_Init(SDL_INIT_EVERYTHING);

	this->csdl2->window = ::SDL_CreateWindow( //
			this->title->getValue(), //
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, //
			this->w, this->h, //
			SDL_WINDOW_SHOWN);

	this->csdl2->surface = SDL_GetWindowSurface((SDL_Window*) this->csdl2->window);

	// 建立映射
	this->display = new Layer((byte*) (this->csdl2->surface->pixels), this->w, this->h, this->colorType, this->rot);
}

void Screen_SDL2::refreshRect(i32 x0, i32 y0, i32 w, i32 h) {
	Base::refreshRect(x0, y0, w, h);
	::SDL_UpdateWindowSurface(this->csdl2->window);
}

void Screen_SDL2::refresh() {
	Base::refresh();
	::SDL_UpdateWindowSurface(this->csdl2->window);
}

}
}

#endif
