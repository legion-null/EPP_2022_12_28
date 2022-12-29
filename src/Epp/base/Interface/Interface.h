#pragma once

#include "base/base.hpp"

E_init

namespace Epp {
namespace base {

interface Interface {

E_IF_DEC(Interface,Interface)

public:
	Interface();
	virtual void destroy();

};

E_class(Interface)

}
}

