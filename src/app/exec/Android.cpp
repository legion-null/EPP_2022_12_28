#ifdef CURRENT_OS_ANDROID

#include "Epp.h"

#include <jni.h>

extern "C"
JNIEXPORT jint JNICALL
Java_com_legion_epp_EPP_EPPMain(JNIEnv *env, jclass clazz, jobjectArray args) {
	extern i32 epp_application_main(i32 argc, c8 **argv);

	i32 argc = 0;
	c8 **argv = nullptr;

	while (Epp::gui::GUIService_Android::IsJAndroidReady() == false) {
		Epp::base::Thread::Sleep(1);
	}

	return epp_application_main(argc, argv);
}

#endif
