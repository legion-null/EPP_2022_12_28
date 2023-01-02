#pragma once

#include "base/Object/Object.h"

namespace Epp {
namespace base {

class Thread: extends Object, implements Runnable {

EPP_CLASS_INFO

public:
	static void Sleep(i32 sec);

public:
	Thread();

};

}
}

