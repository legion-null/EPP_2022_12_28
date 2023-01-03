#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace gui {

const base::Class *GUIService::ClassInfo = base::Class::Register<GUIService, GUIService>("Epp::gui::GUIService", nullptr);

const bool GUIService::ValidityOfIM[GUIService::NumberOfIM] = { (EPP_CURRENT_OS == EPP_OS_WINDOWS),	//
		(EPP_CURRENT_OS == EPP_OS_MACOS),	//
		(EPP_CURRENT_OS == EPP_OS_ANDROID),	//
		(EPP_CURRENT_OS == EPP_OS_IOS),		//
		(EPP_MODULE_X11_SUPPORT == EPP_TRUE),	//
		(EPP_MODULE_SDL2_SUPPORT == EPP_FALSE),	//
		false //
		};

bool GUIService::IsAvailable(IMType type) {
	return ValidityOfIM[type];
}

GUIService::IMType GUIService::DefaultIMType = GUIService::InitDefaultIMType();

GUIService::IMType GUIService::InitDefaultIMType() {
	// EPP_CODE_LOCATE();
	for (i32 i = 0; i < NumberOfIM; i++) {
		if (ValidityOfIM[i] == true)
			return (IMType) i;
	}

	return Unavailable;
}

GUIService::IMType GUIService::GetDefaultIMType() {
	EPP_CODE_LOCATE();
	return DefaultIMType;
}

void GUIService::SetDefaultIMType(IMType type) {
	EPP_CODE_LOCATE();
	if (IsAvailable(type) == false)
		throw new Exception();

	DefaultIMType = type;
}

GUIService* GUIService::GetIM(IMType type) {
	EPP_CODE_LOCATE();

	if(IsAvailable(type) == false){
		throw new Exception();
	}

	switch (type) {
	case Windows:
#if EPP_CURRENT_OS == EPP_OS_WINDOWS
		return new GUIService_Windows();
#endif
		break;
	case MacOS:
#if EPP_CURRENT_OS == EPP_OS_MACOS
		return new GUIService_MacOS();
#endif
		break;
	case Android:
#if EPP_CURRENT_OS == EPP_OS_ANDROID
		return new GUIService_Android();
#endif
		break;
	case IOS:
#if EPP_CURRENT_OS == EPP_OS_IOS
		return new GUIService_IOS();
#endif
		break;
	case X11:
#if EPP_MODULE_X11_SUPPORT == EPP_TRUE
		return new GUIService_X11();
#endif
		break;
	case SDL2:
#if EPP_MODULE_SDL2_SUPPORT == EPP_TRUE
		return new GUIService_SDL2();
#endif
		break;
	case LinuxFB:
#if EPP_MODULE_LINUXFB_SUPPORT == EPP_TRUE
		return new GUIService_SDL2();
#endif
		break;
	}

	throw new Exception();
}

GUIService* GUIService::GetDefaultIM() {
	EPP_CODE_LOCATE();
	return GetIM(GetDefaultIMType());
}

GUIService::GUIService() {
	EPP_CODE_LOCATE();

}

Screen* GUIService::getScreen(i32 index) const {
	return screenList[index];
}

Screen* GUIService::getScreen() const {
	EPP_CODE_LOCATE();

	return getScreen(0);
}



}
}
