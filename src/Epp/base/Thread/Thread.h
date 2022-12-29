#pragma once

#include "base/Object/Object.h"

E_init

namespace Epp {
namespace base {

class Thread: extends base::Object {

E_CLASS_DEC(Thread,base::Object)

public:
	static void Sleep(i32 sec);

public:
	Thread();
	virtual void destroy() override;

};

E_class(Thread)

}
}

