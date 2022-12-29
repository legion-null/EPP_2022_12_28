#ifdef USE_LIB_SDL2

#pragma once

#include "gui/GUIService/GUIService.h"

E_init

namespace Epp {
namespace gui {

class GUIService_SDL2: extends GUIService {

E_CLASS_DEC(GUIService_SDL2,GUIService)

public:

public:
	GUIService_SDL2();
	virtual void destroy() override;

};

E_class(GUIService_SDL2)

}
}

#include "Screen/Screen_SDL2.h"

#endif
