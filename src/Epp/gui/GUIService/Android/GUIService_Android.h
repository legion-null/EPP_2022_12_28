#pragma once

#include "gui/GUIService/GUIService.h"

#if EPP_CURRENT_OS == EPP_OS_ANDROID

namespace Epp {
namespace gui {

class GUIService_Android: extends GUIService {

EPP_CLASS_INFO

public:
	static struct JAndroid *JA;

public:
	static bool IsJAndroidReady();
	static void* GetJAndroidEFP();

protected:
	struct JAndroid *jandroid = nullptr;

public:
	GUIService_Android();

public:
	virtual Screen* getScreen() const override;

};

}
}

#include "Screen/Screen_Android.h"

#endif
