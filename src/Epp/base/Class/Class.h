#pragma once

#include "base/Object/Object.h"

E_init

namespace Epp {
namespace base {

E_import_class(String)

class Class: extends Object {

E_CLASS_DEC(Class,Object)

protected:
	EString fullClassName = nullptr;
	i32 hashCode = 0;

public:
	Class();

public:
	Class(EString fullClassName);

public:
	EString getFullClassName();
	EString getClassName();
	i32 getHashCode();

};

E_class(Class)

}
}
