#pragma once

#include "Epp.hpp"

#include <SDL2/SDL.h>

namespace Epp {
namespace gui {

struct CSDL2 {
	// 屏幕相关
	::SDL_Window *window;
	::SDL_Surface *surface;
	u8 *fb;
	u8 **fbX;
	// 输入相关
	::SDL_Event event;
};

}
}
