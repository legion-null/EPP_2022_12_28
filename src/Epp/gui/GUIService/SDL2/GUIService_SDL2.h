#pragma once

#include "gui/GUIService/GUIService.h"

#if EPP_MODULE_SDL2_SUPPORT == EPP_TRUE

namespace Epp {
namespace gui {

class GUIService_SDL2: extends GUIService {

EPP_CLASS_INFO

public:
	GUIService_SDL2();

public:
	virtual Epp::gui::Screen* getDefaultScreen() const override;
};

}
}

#include "Screen/Screen_SDL2.h"

#endif
