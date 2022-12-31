#include "Epp.h"

#if EPP_CURRENT_OS == EPP_OS_ANDROID

using namespace Epp;
using namespace Epp::base;

#include "About_Android.h"

namespace Epp {
namespace gui {

E_CLASS_DEF(Epp::gui::GUIService_Android)

void GUIService_Android::Static() { // 静态块，类初始化时将会执行块内代码，为了防止Epp类型构建系统出错，静态块内的代码必须与类型加载顺序无关

}

struct JAndroid *GUIService_Android::JA = new struct JAndroid;

bool GUIService_Android::IsJAndroidReady() {
	__android_log_print(ANDROID_LOG_ERROR, "EPP", "func:%s", __func__);
	return JA->running;
}

GUIService_Android::GUIService_Android() {

}

void GUIService_Android::destroy() {
	delete this;
}



}
}

#endif
