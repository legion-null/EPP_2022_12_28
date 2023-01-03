#pragma once

#if EPP_CURRENT_OS == EPP_OS_ANDROID

#include "gui/Screen/Screen.h"

namespace Epp {
namespace gui {

class Screen_Android: extends Screen {

EPP_CLASS_INFO

protected:
	static const i32 MaxNumberOfAndroidFrameBuffer = 5;

protected:
	base::String *title = nullptr;

protected:
	struct JAndroid *jandroid = nullptr;

protected:
	// Android下存在多个缓冲区，在这里对缓冲区进行记录
	Layer* androidFrameBuffer[MaxNumberOfAndroidFrameBuffer];

public:
	Screen_Android();

public:
	Screen_Android(struct JAndroid *ja, base::String *title, i32 w, i32 h, graphics::Color::Type colorType, graphics::Rot rot);

protected:
	void lockSurface();
	void lockSurfaceRect(i32 x, i32 y, i32 w, i32 h);
	void unlockSurface();

public:
	virtual void refreshRect(i32 x0, i32 y0, i32 w, i32 h) override;
	virtual void refresh() override;

};

}
}

int gui_Screen_Android_test_main(i32 argc, c8 **argv);

#endif
