#pragma once

#include "base/Object/Object.h"


namespace Epp {
namespace base {

class OS: extends Object {

EPP_CLASS_INFO

public:
	static const i32 BigEndian = EPP_ENDION_BIG;
	static const i32 LittleEndian = EPP_ENDION_LITTLE;

public:
	static bool IsLittleEndian();

public:
	static void Printf(String* fmt, ...);
	static void PrintMemory(byte *address, i32 len);

public:
	OS();
};


}
}

