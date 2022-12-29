#pragma once

#include "base/Object/Object.h"

E_init

namespace Epp {
namespace base {

E_import_class(String)

class Exception: extends base::Object {

E_CLASS_DEC(Exception,base::Object)

public:
	static EException UnknownException();

public:
	Exception();
	virtual void destroy() override;

public:
	Exception(EString info);

};

E_class(Exception)

}
}

