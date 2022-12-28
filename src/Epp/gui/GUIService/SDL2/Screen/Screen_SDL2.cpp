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
		Screen_SDL2(800, 600, Color::ARGB8888, Rot_0) {

}

void Screen_SDL2::destroy() {
	delete this;
}

Screen_SDL2::Screen_SDL2(i32 w, i32 h, Color::Type colorType, Rot rot) :
		Screen_SDL2(S("Epp SDL2_ScreenSimulator Author:legion"), w, h, colorType, rot) {
}

Screen_SDL2::Screen_SDL2(base::EString title, i32 w, i32 h, Color::Type colorType, Rot rot) :
		Base(w, h, colorType, rot) {

	this->title = title->clone();

	if(this->csdl2 == nullptr)
		this->csdl2 = new CSDL2;
	//SafeNew(this->csdl2, 1);

	::SDL_Init(SDL_INIT_EVERYTHING);

	this->csdl2->window = ::SDL_CreateWindow( //
			this->title->getValue(), //
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, //
			this->w, this->h, //
			SDL_WINDOW_SHOWN);

	this->csdl2->surface = SDL_GetWindowSurface((SDL_Window*) this->csdl2->window);

	// 缓冲区映射
	this->csdl2->fb = (u8*) (this->csdl2->surface->pixels);
	this->csdl2->fbX = new u8*[this->h];

	for (i32 i = 0; i < this->h; i++)
		this->csdl2->fbX[i] = &(this->csdl2->fb[this->lineSize * i]);

}

void Screen_SDL2::refreshRect(i32 x0, i32 y0, i32 w, i32 h) {

	::SDL_UpdateWindowSurface(this->csdl2->window);
}

void Screen_SDL2::refresh() {
	SafeCopy(this->fb, this->csdl2->fb, this->fbSize);
	::SDL_UpdateWindowSurface(this->csdl2->window);
}

}
}
