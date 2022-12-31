#pragma once

#include "Epp.hpp"

#if EPP_MODULE_SDL2_SUPPORT == EPP_TRUE

#include <SDL2/SDL.h>

namespace Epp {
namespace gui {

struct CSDL2 {
	// 屏幕相关
	::SDL_Window *window;
	::SDL_Surface *surface;
	// 输入相关
	::SDL_Event event;
};

}
}

#endif
