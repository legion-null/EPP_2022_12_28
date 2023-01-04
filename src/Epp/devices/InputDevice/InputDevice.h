#pragma once

#include "devices/Device/Device.h"

namespace Epp {
namespace devices {

class InputDevice: public Device {

EPP_CLASS_INFO

public:
	InputDevice();
	virtual ~InputDevice();

};

}
}

