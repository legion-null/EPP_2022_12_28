#pragma once

#include "gui/InputDevice/InputDevice.h"

#include "gui/InputEvent/TouchPadEvent/TouchPadEvent.h"

namespace Epp {
namespace gui {

class TouchPad: public InputDevice {

EPP_CLASS_INFO

public:
	TouchPad();
	virtual ~TouchPad();

};

}
}

