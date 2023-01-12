#pragma once

#include "gui/GUIService/GUIService.h"

#if EPP_MODULE_X11_SUPPORT == EPP_TRUE

namespace Epp {
namespace gui {

class GUIService_X11: public GUIService {

EPP_CLASS_INFO

public:
	GUIService_X11();

public:
	virtual Epp::gui::Screen* getScreen() const override;

};

}
}

#include "Screen/Screen_X11.h"

#include "Mouse/Mouse_X11.h"

#endif
