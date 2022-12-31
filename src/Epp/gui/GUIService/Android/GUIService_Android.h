#pragma once

#include "gui/GUIService/GUIService.h"

#if EPP_CURRENT_OS == EPP_OS_ANDROID

E_init

namespace Epp {
namespace gui {

class GUIService_Android: extends GUIService {

E_CLASS_DEC(GUIService_Android,GUIService)

public:
	static struct JAndroid *JA;

public:
	static bool IsJAndroidReady();
	static void* GetJAndroidEFP();

protected:
	struct JAndroid *jandroid = nullptr;

public:
	GUIService_Android();
	virtual void destroy() override;

};

E_class(GUIService_Android)

}
}

#include "Screen/Screen_Android.h"

#endif
