#include "Epp.h"

#if EPP_CURRENT_OS == EPP_OS_ANDROID

using namespace Epp;
using namespace Epp::base;

using namespace Epp::graphics;

#include "../About_Android.h"

namespace Epp {
namespace gui {

const base::Class * Screen_Android::ClassInfo = base::Class::Register<Screen_Android, Screen>("Epp::gui::Screen_Android", nullptr);


Screen_Android::Screen_Android() :
		Screen_Android(GUIService_Android::JA, //
				S("Epp Android_ScreenSimulator Author:legion"), //
				GUIService_Android::JA->w, GUIService_Android::JA->h, //
				Color::RGBX8888, //
				Rot_0 //
				) {
}

Screen_Android::Screen_Android(struct JAndroid *ja, String* title, i32 w, i32 h, Color::Type colorType, Rot rot) :
		Screen(w, h, colorType, rot) {
	this->title = title->clone();
	this->jandroid = ja;
}

void Screen_Android::lockSurfaceRect(i32 x0, i32 y0, i32 w, i32 h) {
	::ARect rect = { .left = x0, .top = y0, .right = this->w - w - x0, .bottom = this->h - h - y0 };

	::ANativeWindow_Buffer buffer;
	::ANativeWindow_lock(this->jandroid->window, &buffer, &rect);

	// 地址重映射
	if (this->display == nullptr) {
		this->display = new Layer((byte*) buffer.bits, this->w, this->h, this->colorType, this->rot);
	} else if (this->display->getFb() != buffer.bits) {
		delete this->display;
		this->display = new Layer((byte*) buffer.bits, this->w, this->h, this->colorType, this->rot);
	}
}

void Screen_Android::lockSurface() {
	::ANativeWindow_Buffer buffer;
	::ANativeWindow_lock(this->jandroid->window, &buffer, 0);

	// 地址重映射
	if (this->display == nullptr) {
		this->display = new Layer((byte*) buffer.bits, this->w, this->h, this->colorType, this->rot);
	} else if (this->display->getFb() != buffer.bits) {
		delete this->display;
		this->display = new Layer((byte*) buffer.bits, this->w, this->h, this->colorType, this->rot);
	}
}

void Screen_Android::unlockSurface() {
	::ANativeWindow_unlockAndPost(this->jandroid->window);
}

void Screen_Android::refreshRect(i32 x0, i32 y0, i32 w, i32 h) {
	if (this->jandroid->running == false)
		return;

	lockSurface();
	Screen::refreshRect(x0, y0, w, h);
	unlockSurface();

	EPP_CODE_LOCATE();
}

void Screen_Android::refresh() {
	if (this->jandroid->running == false)
		return;

	lockSurface();
	Screen::refresh();
	unlockSurface();
}

}
}

#endif
