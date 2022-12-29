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
		This(1080, 1920, colorType, rot) {
}

void Screen_Android::destroy() {
	delete this;
}

Screen_Android::Screen_Android(i32 w, i32 h, Color::Type colorType, Rot rot) :
		This(S("Epp Android_ScreenSimulator Author:legion"), w, h, colorType, rot) {
}

Screen_Android::Screen_Android(EString title, i32 w, i32 h, Color::Type colorType, Rot rot) :
		This(::GetJAndroid(), title, w, h, colorType, rot) {

}

Screen_Android::Screen_Android(struct JAndroid *ja, EString title, i32 w, i32 h, Color::Type colorType, Rot rot) :
		Base(w, h, colorType, rot) {
	this->title = title->clone();
	this->jandroid = ja;

	if (this->jandroid == nullptr)
		; //SafeNew(this->jandroid);

	// 建立映射
	this->display = new FrameBuffer((byte*) 0x01, this->w, this->h, this->bpp);
}

void Screen_Android::refreshRect(i32 x0, i32 y0, i32 w, i32 h) {
	if (this->jandroid->run == false)
		return;

	::ANativeWindow_Buffer buffer;
	::ANativeWindow_lock(this->jandroid->window, &buffer, 0);

	// 地址重映射
	this->display->fb = (byte*) (buffer.bits);

	// 安卓像素格式 RGBA
	Base::refreshRect(x0, y0, w, h);

	::ANativeWindow_unlockAndPost(this->jandroid->window);
}

void Screen_Android::refresh() {
	if (this->jandroid->run == false)
		return;

	__android_log_print(ANDROID_LOG_ERROR, "EPP", "func:%s", __func__);

	::ANativeWindow_Buffer buffer;
	::ANativeWindow_lock(this->jandroid->window, &buffer, 0);

	// 地址重映射
	this->display->fb = (byte*) (buffer.bits);

	// 安卓像素格式 RGBA
	Base::refresh();

	::ANativeWindow_unlockAndPost(this->jandroid->window);
}

}
}

#endif
