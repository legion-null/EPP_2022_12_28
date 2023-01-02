#pragma once

#include "defs.h"

#if EPP_CURRENT_OS == EPP_OS_ANDROID

#include <android/native_window.h>
#include <android/native_window_jni.h>

namespace Epp {
namespace gui {

struct JAndroid {
	// 屏幕相关
	ANativeWindow *window = nullptr;
	i32 w = 0;
	i32 h = 0;
	// 输入相关

	// 状态相关
	bool running = false;
};

}
}

#endif

