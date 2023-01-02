#pragma once

#include "base/Interface/Interface.h"

namespace Epp {
namespace base {

class Runnable: extends Interface {

EPP_CLASS_INFO

public:
	virtual void run() = 0;
};

}
}

