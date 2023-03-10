#include "Epp.h"

#if EPP_CURRENT_OS == EPP_OS_ANDROID

using namespace Epp;
using namespace Epp::base;

using namespace Epp::graphics;
using namespace Epp::gui;

#include <jni.h>

#include "About_Android.h"

extern "C" {

/*
 * JNI函数命名规范
 *
 * 例如：
 * 类 com.test.JNI.Test 下有native方法两个
 *
 * public static void func(...);
 * public void method(...);
 *
 * 生成的C语言函数声明如下
 *
 * 静态方法 func
 * JNIEXPORT void JNICALL
 * Java_com_test_JNI_Test_func(JNIEnv *env, jclass clazz, ...);
 *
 * 成员方法 method
 * JNIEXPORT void JNICALL
 * Java_com_test_JNI_Test_func(JNIEnv *env, jobject obj, ...);
 *
 * 变量类型详见<jni.h>
 *
 */

JNIEXPORT void JNICALL
Java_com_legion_epp_EPP_SurfaceCreate(JNIEnv *env, jclass clazz, jobject surface) {
	EPP_CODE_LOCATE();

	GUIService_Android::JA->window = ::ANativeWindow_fromSurface(env, surface);
}

JNIEXPORT void JNICALL
Java_com_legion_epp_EPP_SurfaceChanged(JNIEnv *env, jclass clazz, jobject surface, jint width, jint height) {
	EPP_FUNC_LOCATE("___, %d, %d", width, height);

	// 设置像素格式
	::ANativeWindow_setBuffersGeometry(GUIService_Android::JA->window, width, height, WINDOW_FORMAT_RGBX_8888);

	// 设置屏幕分辨率等信息
	GUIService_Android::JA->w = width;
	GUIService_Android::JA->h = height;
	GUIService_Android::JA->colorType = Color::RGBX8888;

	// 设置启动标志
	GUIService_Android::JA->running = true;
}

JNIEXPORT void JNICALL
Java_com_legion_epp_EPP_SurfaceDestroy(JNIEnv *env, jclass clazz, jobject surface) {
	EPP_CODE_LOCATE();

	// 设置启动标志
	GUIService_Android::JA->running = false;
}

JNIEXPORT void JNICALL
Java_com_legion_epp_EPP_TouchEvent(JNIEnv *env, jclass clazz, jint x, jint y, jboolean touch) {
	EPP_CODE_LOCATE();

//	state.x = x;
//	state.y = y;
//	state.is_touched = touch;
}

}

#endif

