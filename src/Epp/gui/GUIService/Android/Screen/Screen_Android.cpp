#include "Epp.h"

#if EPP_CURRENT_OS == EPP_OS_ANDROID

using namespace Epp;
using namespace Epp::base;

using namespace Epp::graphics;

#include "../About_Android.h"

namespace Epp {
namespace gui {

const Class *Screen_Android::ClassInfo = Class::Register<Screen_Android, Screen>("Epp::gui::Screen_Android", nullptr);

Screen_Android::Screen_Android() :
		Screen_Android(GUIService_Android::JA, //
				"Epp Android_ScreenSimulator Author:legion", //
				GUIService_Android::JA->w, GUIService_Android::JA->h, //
				GUIService_Android::JA->colorType, //
				Rot_0 //
				) {
}

Screen_Android::Screen_Android(struct JAndroid *ja, const String &title, i32 w, i32 h, Color::Type colorType, Rot rot) :
		Screen(title, w, h, colorType, rot) {
	EPP_FUNC_LOCATE("0x%016x, %s, %d, %d, %s", ja, title->getValue(), w, h, Color::GetEnumName(colorType));
	this->jandroid = ja;
}

void Screen_Android::lockSurface() {
	::ANativeWindow_Buffer buffer;
	::ANativeWindow_lock(this->jandroid->window, &buffer, 0);

	//EPP_DEBUG("buffer:%d %d %d", buffer.width, buffer.height, buffer.stride);

	// 地址重映射
	if (this->display == nullptr) {
		this->display = new Layer((u8*) buffer.bits, buffer.stride, this->h, this->colorType, this->rot);
		// 同时将这个buffer.bits的指针添加到表里，下次直接查表
	} else if (this->display->getFb() != buffer.bits) {
		delete this->display;
		// display->
		this->display = new Layer((u8*) buffer.bits, buffer.stride, this->h, this->colorType, this->rot);
	}
}

void Screen_Android::lockSurfaceRect(i32 x, i32 y, i32 w, i32 h) {

}

void Screen_Android::unlockSurface() {
	::ANativeWindow_unlockAndPost(this->jandroid->window);
}

void Screen_Android::refreshRect(i32 x0, i32 y0, i32 w, i32 h) {
	throw new Exception("不支持区域刷新");
}

void Screen_Android::refresh() {
	if (this->jandroid->running == false)
		return;

	lockSurface();
	if (this->display->getWidth() == this->w) {
		this->display->copyFrom(this);
	} else { // Android 下存在缓冲区
		this->display->copyFrom(this, 0, 0, this->w, this->h, 0, 0);
	}
	unlockSurface();
}



}
}

#endif
