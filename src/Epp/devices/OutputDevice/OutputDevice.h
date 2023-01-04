#pragma once

#include "devices/Device/Device.h"

namespace Epp {
namespace devices {

class OutputDevice: public Device {

EPP_CLASS_INFO

public:
	OutputDevice();
	virtual ~OutputDevice();

};

}
}

