#pragma once

#include "base/Object/Object.h"

E_init

namespace Epp {
namespace base {

class OS: extends Object {

E_CLASS_DEC(OS, Object)

public:
	static void Printf(EString fmt, ...);
	static void PrintMemory(byte *address, i32 len);

public:
	OS();

};

E_class(OS)

}
}

