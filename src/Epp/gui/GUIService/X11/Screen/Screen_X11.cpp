#include "Epp.h"

#if EPP_MODULE_X11_SUPPORT == EPP_TRUE

#include "../About_X11.h"

using namespace Epp::gui;

using namespace Epp;
using namespace Epp::base;

using namespace Epp::graphics;

namespace Epp {
namespace gui {

const Class *Screen_X11::ClassInfo = Class::Register<Screen_X11, Screen>("Epp::gui::Screen_X11", nullptr);

Screen_X11::Screen_X11() :
		Screen_X11(800, 600, Color::XRGB8888, Rot_0) {

}

Screen_X11::Screen_X11(i32 w, i32 h, Color::Type colorType, Rot rot) :
		Screen_X11(S("Epp X11_ScreenSimulator Author:legion"), w, h, colorType, rot) {
}

Screen_X11::Screen_X11(String *title, i32 w, i32 h, Color::Type colorType, Rot rot) :
		Screen(title, w, h, colorType, rot) {
	EPP_CODE_LOCATE();

	this->title = title->clone();

	this->cx11 = new struct CX11;

	this->cx11->display = ::XOpenDisplay(0);
	this->cx11->window = ::XCreateSimpleWindow(this->cx11->display, DefaultRootWindow(this->cx11->display), 0, 0, this->w, this->h, //
			1, BlackPixel(this->cx11->display, 0), BlackPixel(this->cx11->display, 0));

	setTitle(title);

	this->cx11->gc = DefaultGC(this->cx11->display, DefaultScreen(this->cx11->display));

	this->cx11->img = ::XCreateImage(this->cx11->display, DefaultVisual(this->cx11->display, DefaultScreen(this->cx11->display)),
			DefaultDepth(this->cx11->display, DefaultScreen(this->cx11->display)),
			ZPixmap, 0, (c8*) this->fb, this->w, this->h, this->bpp, 0);

	// 建立映射

	::XMapWindow(this->cx11->display, this->cx11->window);
	::XFlush(this->cx11->display);
}

void Screen_X11::setTitle(String *title) {
	Screen::setTitle(title);
	::XStoreName(this->cx11->display, this->cx11->window, this->title->getValue());
}

void Screen_X11::refreshRect(i32 x0, i32 y0, i32 w, i32 h) {
	rMapPixel(x0, y0);
	::XPutImage(this->cx11->display, this->cx11->window, this->cx11->gc, this->cx11->img, x0, y0, x0, y0, w, h);
	::XFlush(this->cx11->display);
}

void Screen_X11::refresh() {
	refreshRect(0, 0, this->w, this->h);
}

}
}

#endif
