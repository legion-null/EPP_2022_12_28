#pragma once

#include "gui/InputDevice/InputDevice.h"

#include "gui/InputEvent/MouseEvent/MouseEvent.h"

namespace Epp {
namespace gui {

class KeyBoard: public InputDevice {

EPP_CLASS_INFO

public:
	KeyBoard();
	virtual ~KeyBoard();

};

}
}

