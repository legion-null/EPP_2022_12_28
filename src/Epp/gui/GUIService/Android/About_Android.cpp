#ifdef CURRENT_OS_ANDROID

#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

#include "About_Android.h"

// 单元测试
#define TEST_UNIT	gui_Screen_Android_test_main

// 声明单元测试入口函数
extern i32 TEST_UNIT(i32 argc, c8 **argv);

i32 EPPAndroidMain(i32 argc, c8 **argv) {
	return TEST_UNIT(argc, argv);
}

#endif

extern "C" {

Epp::gui::JAndroid ja;

Epp::gui::JAndroid* GetJAndroid() {
	return &ja;
}

JNIEXPORT void JNICALL
Java_com_legion_epp_EPP_SurfaceCreate(JNIEnv *env, jclass clazz, jobject surface) {
	ja.window = ::ANativeWindow_fromSurface(env, surface);
	// 设置像素格式
	::ANativeWindow_setBuffersGeometry(ja.window, 1080, 1920, WINDOW_FORMAT_RGBX_8888);
	__android_log_print(ANDROID_LOG_ERROR, "EPP", "func:%s", __func__);
}

JNIEXPORT void JNICALL
Java_com_legion_epp_EPP_SurfaceChanged(JNIEnv *env, jclass clazz, jobject surface, jint width, jint height) {
	ja.run = true;
	__android_log_print(ANDROID_LOG_ERROR, "EPP", "func:%s", __func__);
}

JNIEXPORT void JNICALL
Java_com_legion_epp_EPP_SurfaceDestroy(JNIEnv *env, jclass clazz, jobject surface) {
	ja.run = false;
}

JNIEXPORT void JNICALL
Java_com_legion_epp_EPP_TouchEvent(JNIEnv *env, jclass clazz, jint x, jint y, jboolean touch) {
//	state.x = x;
//	state.y = y;
//	state.is_touched = touch;
	__android_log_print(ANDROID_LOG_ERROR, "EPP", "func:%s", __func__);
}
}


