#pragma once

#include <jni.h>
#include <android/native_window.h>
#include <android/native_window_jni.h>

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
Java_com_legion_epp_EPP_SurfaceCreate(JNIEnv *env, jclass clazz, jobject surface);

JNIEXPORT void JNICALL
Java_com_legion_epp_EPP_SurfaceChanged(JNIEnv *env, jclass clazz, jobject surface, jint width, jint height);

JNIEXPORT void JNICALL
Java_com_legion_epp_EPP_SurfaceDestroy(JNIEnv *env, jclass clazz, jobject surface);

JNIEXPORT void JNICALL
Java_com_legion_epp_EPP_TouchEvent(JNIEnv *env, jclass clazz, jint x, jint y, jboolean touch);

}

#include "Epp.hpp"

namespace Epp {
namespace gui {

struct JAndroid {
	// 屏幕相关
	ANativeWindow *window;
	// 输入相关

	// 状态相关
	bool run;
};

}
}

