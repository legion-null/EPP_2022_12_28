#ifdef CURRENT_OS_ANDROID

#pragma once

#include "gui/GUIService/GUIService.h"

E_init

namespace Epp {
namespace gui {

class GUIService_Android: extends GUIService {

E_CLASS_DEC(GUIService_Android,GUIService)

public:
	GUIService_Android();
	virtual void destroy() override;

};

E_class(GUIService_Android)

}
}

#include "Screen/Screen_Android.h"

#endif
