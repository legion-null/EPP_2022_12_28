#pragma once

#include "gui/InputDevice/Mouse/Mouse.h"

#if EPP_MODULE_X11_SUPPORT == EPP_TRUE

namespace Epp {
namespace gui {

class Mouse_X11: public Mouse {

EPP_CLASS_INFO

public:
	Mouse_X11();
	virtual ~Mouse_X11();

protected:
	virtual InputEvent* reportInputEvent() override;

};

}
}

#endif
