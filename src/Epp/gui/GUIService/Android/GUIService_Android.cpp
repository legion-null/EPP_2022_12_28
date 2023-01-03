#include "Epp.h"

#if EPP_CURRENT_OS == EPP_OS_ANDROID

using namespace Epp;
using namespace Epp::base;

#include "About_Android.h"

namespace Epp {
namespace gui {

const Class * GUIService_Android::ClassInfo = Class::Register<GUIService_Android, GUIService>("Epp::gui::GUIService_Android", nullptr);


struct JAndroid *GUIService_Android::JA = new struct JAndroid;

bool GUIService_Android::IsJAndroidReady() {
	EPP_CODE_LOCATE();
	return JA->running;
}

GUIService_Android::GUIService_Android() {

}

Screen* GUIService_Android::getScreen() const {
	return new Screen_Android();
}

}
}

#endif
