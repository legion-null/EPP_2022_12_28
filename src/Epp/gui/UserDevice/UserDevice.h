#pragma once

#include "gui/InputDevice/InputDevice.h"

namespace Epp {
namespace gui {

class UserDevice: public InputDevice {

EPP_CLASS_INFO

public:
	UserDevice();
	virtual ~UserDevice();

};

}
}

