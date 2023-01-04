#pragma once

#include <base/Object/Object.h>

namespace Epp {
namespace devices {

class Device: public Epp::base::Object {

EPP_CLASS_INFO

public:
	Device();
	virtual ~Device();

};

}
}

