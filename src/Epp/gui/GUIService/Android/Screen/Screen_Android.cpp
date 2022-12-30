#ifdef CURRENT_OS_ANDROID

#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

using namespace Epp::graphics;

#include "../About_Android.h"

namespace Epp {
namespace gui {

E_CLASS_DEF(Epp::gui::Screen_Android)

void Screen_Android::Static() { // 静态块，类初始化时将会执行块内代码，为了防止Epp类型构建系统出错，静态块内的代码必须与类型加载顺序无关

}

Screen_Android::Screen_Android() :
		This(GUIService_Android::JA, //
				S("Epp Android_ScreenSimulator Author:legion"), //
				GUIService_Android::JA->w, GUIService_Android::JA->h, //
				Color::RGBX8888, //
				Rot_0 //
				) {
}

void Screen_Android::destroy() {
	Base::destroy();
}

Screen_Android::Screen_Android(struct JAndroid *ja, EString title, i32 w, i32 h, Color::Type colorType, Rot rot) :
		Base(w, h, colorType, rot) {
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
		__android_log_print(ANDROID_LOG_ERROR, "EPP", "更换fb(0x%016x -> 0x%016x)", buffer.bits, this->display->getFb());
		this->display->destroy();
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
		__android_log_print(ANDROID_LOG_ERROR, "EPP", "更换fb(0x%016x -> 0x%016x)", buffer.bits, this->display->getFb());
		this->display->destroy();
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
	Base::refreshRect(x0, y0, w, h);
	unlockSurface();

	__android_log_print(ANDROID_LOG_ERROR, "EPP", "func:%s", __func__);
}

void Screen_Android::refresh() {
	if (this->jandroid->running == false)
		return;

	lockSurface();
	Base::refresh();
	unlockSurface();

	__android_log_print(ANDROID_LOG_ERROR, "EPP", "func:%s", __func__);
}

}
}

#endif
