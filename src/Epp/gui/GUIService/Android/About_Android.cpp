#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace gui {

}
}

#include "About_Android.h"

extern "C" {

	static struct Epp::gui::JAndroid ja;

JNIEXPORT void JNICALL
Java_com_legion_epp_EPP_SurfaceCreate(JNIEnv *env, jclass clazz, jobject surface) {
	ja.window = ::ANativeWindow_fromSurface(env, surface);
	// 设置像素格式
	::ANativeWindow_setBuffersGeometry(ja.window, 0, 0, WINDOW_FORMAT_RGBA_8888);
	ja.run = true;
}

JNIEXPORT void JNICALL
Java_com_legion_epp_EPP_SurfaceChanged(JNIEnv *env, jclass clazz, jobject surface, jint width, jint height) {

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
}
}


