#pragma once

#include "base/Interface/Interface.h"

E_init

namespace Epp {
namespace base {

class Runnable: extends Interface {

E_IF_DEC(Runnable,Interface)

public:
	Runnable();
	virtual void destroy() override;

};

E_class(Runnable)

}
}

