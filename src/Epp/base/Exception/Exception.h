#pragma once

#include "base/Object/Object.h"


namespace Epp {
namespace base {


class Exception: extends Object {

EPP_CLASS_INFO

public:
	static Exception* UnknownException();

public:
	Exception();

public:
	Exception(const c8* info);

};


}
}

