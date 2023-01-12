#pragma once

#include "gui/InputDevice/InputDevice.h"

#include "gui/InputEvent/MouseEvent/MouseEvent.h"

namespace Epp {
namespace gui {

class Mouse: public InputDevice {

EPP_CLASS_INFO

protected:
	i32 x = 0;
	i32 y = 0;

	bool leftButtonPressed = false;
	bool middleButtonPressed = false;
	bool rightButtonPressed = false;

public:
	Mouse();
	virtual ~Mouse();

public:
	virtual const MouseEvent& getInputEvent() override;

};

}
}

