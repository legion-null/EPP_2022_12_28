#pragma once

#include "base/base.hpp"

E_init

namespace Epp {
namespace base {

interface Interface {

E_IF_DEC(Interface,Interface)

public:
	virtual void destory();

};

E_class(Interface)

}
}

