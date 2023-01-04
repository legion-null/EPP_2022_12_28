#include "Epp.h"

#if EPP_MODULE_SDL2_SUPPORT == EPP_TRUE

using namespace Epp;
using namespace Epp::base;

using namespace Epp::graphics;

#include "../About_SDL2.h"

namespace Epp {
namespace gui {

const Class * Screen_SDL2::ClassInfo = Class::Register<Screen_SDL2, Screen>("Epp::gui::Screen_SDL2", nullptr);


Screen_SDL2::Screen_SDL2() :
		Screen_SDL2(800, 600, Color::XRGB8888, Rot_0) {

}

Screen_SDL2::Screen_SDL2(i32 w, i32 h, Color::Type colorType, Rot rot) :
		Screen_SDL2(S("Epp SDL2_ScreenSimulator Author:legion"), w, h, colorType, rot) {
}

Screen_SDL2::Screen_SDL2(String* title, i32 w, i32 h, Color::Type colorType, Rot rot) :
		Screen(w, h, colorType, rot) {

	this->title = title->clone();

	this->csdl2 = new CSDL2;

	::SDL_Init(SDL_INIT_EVERYTHING);

	this->csdl2->window = ::SDL_CreateWindow( //
			this->title->getValue(), //
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, //
			this->w, this->h, //
			SDL_WINDOW_SHOWN);

	this->csdl2->surface = ::SDL_GetWindowSurface((SDL_Window*) this->csdl2->window);

	// 建立映射
	this->display = new Layer((byte*) (this->csdl2->surface->pixels), this->w, this->h, this->colorType, this->rot);
}

void Screen_SDL2::refreshRect(i32 x0, i32 y0, i32 w, i32 h) {
	Screen::refreshRect(x0, y0, w, h);
	::SDL_UpdateWindowSurface(this->csdl2->window);
}

void Screen_SDL2::refresh() {
	Screen::refresh();
	::SDL_UpdateWindowSurface(this->csdl2->window);
}

}
}

#endif
