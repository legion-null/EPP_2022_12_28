#pragma once

#include "base/Exception/Exception.h"

E_init

namespace Epp {
namespace base {

class Error: extends Exception {

E_CLASS_DEC(Error,Exception)

public:
	static EError UnknownError();

public:
	Error();
	virtual void destroy() override;

public:
	Error(EString info);

};

E_class(Error)

}
}

