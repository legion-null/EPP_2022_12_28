#pragma once

#include "defs.h"

#if EPP_MODULE_X11_SUPPORT == EPP_TRUE

#include "Xlib.h"

namespace Epp{
namespace gui{

struct CX11 {
	// 显示设备相关
	Display *display;
	Window window;
	GC gc;
	XImage *img;
	// 输入设备相关
	XEvent event;
};

}
}

#endif
