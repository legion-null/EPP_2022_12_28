#pragma once

#include "defs.h"

#if EPP_CURRENT_OS == EPP_OS_ANDROID

#include <jni.h>
#include <android/log.h>
#include <android/native_window.h>
#include <android/native_window_jni.h>

//#undef EPP_DEBUG
#undef EPP_CODE_LOCATE

#define EPP_CODE_LOCATE(...)		__android_log_print(3, "EPP","File:%s, Func:%s, Row:%d\n",__FILE__,__FUNCTION__,__LINE__)

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

