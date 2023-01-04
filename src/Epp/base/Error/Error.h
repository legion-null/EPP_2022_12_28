#pragma once

#include "base/Exception/Exception.h"

namespace Epp {
namespace base {

class Error: extends Exception {

EPP_CLASS_INFO

public:
	static Error* UnknownError();

public:
	Error();

public:
	Error(const c8* info);

};

}
}

