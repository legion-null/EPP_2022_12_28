#pragma once

#include "gui/InputDevice/InputDevice.h"

#include "gui/InputEvent/MouseEvent/MouseEvent.h"

namespace Epp {
namespace gui {

class Mouse: public InputDevice {

EPP_CLASS_INFO

public:
	Mouse();
	virtual ~Mouse();

protected:
	virtual InputEvent* reportInputEvent() = 0;

};

}
}

