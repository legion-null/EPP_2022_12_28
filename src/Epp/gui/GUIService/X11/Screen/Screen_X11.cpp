#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

using namespace Epp::graphics;

#include "../About_X11.h"

namespace Epp {
namespace gui {

const base::Class * Screen_X11::ClassInfo = base::Class::Register<Screen_X11, Screen>("Epp::gui::Screen_X11", nullptr);


Screen_X11::Screen_X11() {

}

Screen_X11::Screen_X11(i32 w, i32 h, Color::Type colorType, Rot rot) {
}

Screen_X11::Screen_X11(base::String* title, i32 w, i32 h, Color::Type colorType, Rot rot) :
		Screen(w, h, colorType, rot) {
	this->title = title->clone();

	this->cx11 = new struct CX11;

	this->cx11->display = ::XOpenDisplay(0);
	this->cx11->window = ::XCreateSimpleWindow(this->cx11->display, DefaultRootWindow(this->cx11->display), 0, 0, this->w, this->h, //
			1, ::BlackPixel(this->cx11->display, 0), ::BlackPixel(this->cx11->display, 0));

	::XStoreName(this->cx11->display, this->cx11->window, this->title->getValue());

	this->cx11->gc = DefaultGC(this->cx11->display, DefaultScreen(this->cx11->display));

	this->cx11->img = ::XCreateImage(this->cx11->display, DefaultVisual(this->cx11->display, DefaultScreen(this->cx11->display)), DefaultDepth(this->cx11->display, DefaultScreen(this->cx11->display)),
			::ZPixmap, 0, (c8*) this->fb, this->w, this->h, this->bpp, 0);

	// 建立映射

	::XMapWindow(this->cx11->display, this->cx11->window);
	::XFlush(this->cx11->display);
}

void Screen_X11::refresh() {
}

void Screen_X11::refreshRect(i32 x0, i32 y0, i32 w, i32 h) {
}

}
}
