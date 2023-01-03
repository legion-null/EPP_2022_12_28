#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace gui {

const base::Class *GUIService::ClassInfo = base::Class::Register<GUIService, GUIService>("Epp::gui::GUIService", nullptr);

const bool GUIService::ValidityOfSupportInterfaces[GUIService::NumberOfSupportInterfaces] = { (EPP_CURRENT_OS == EPP_OS_WINDOWS),	//
		(EPP_CURRENT_OS == EPP_OS_MACOS),	//
		(EPP_CURRENT_OS == EPP_OS_ANDROID),	//
		(EPP_CURRENT_OS == EPP_OS_IOS),		//
		(EPP_MODULE_X11_SUPPORT == EPP_TRUE),	//
		(EPP_MODULE_SDL2_SUPPORT == EPP_FALSE),	//
		false //
		};

bool GUIService::IsAvailable(Type type) {
	return ValidityOfSupportInterfaces[type];
}

GUIService::Type GUIService::DefaultGuiServiceType = GUIService::InitDefaultGuiServiceType();

GUIService::Type GUIService::InitDefaultGuiServiceType() {
	EPP_CODE_LOCATE();
	for (i32 i = 0; i < NumberOfSupportInterfaces; i++) {
		if (ValidityOfSupportInterfaces[i] == true)
			return (Type) i;
	}

	return Unavailable;
}

GUIService::Type GUIService::GetDefaultGuiServiceType() {
	EPP_CODE_LOCATE();
	return DefaultGuiServiceType;
}

void GUIService::SetDefaultGuiServiceType(Type type) {
	EPP_CODE_LOCATE();
	if (IsAvailable(type) == false)
		throw 0;

	DefaultGuiServiceType = type;
}

GUIService* GUIService::GetGUIService(Type type) {
	EPP_CODE_LOCATE();

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
		break;
	}

	throw 0;
}

GUIService* GUIService::GetDefaultGUIService() {
	EPP_CODE_LOCATE();
	return GetGUIService(GetDefaultGuiServiceType());
}

GUIService::GUIService() {
	EPP_CODE_LOCATE();

}

Screen* GUIService::getScreen() const {
	EPP_CODE_LOCATE();
	return nullptr;
}

}
}
