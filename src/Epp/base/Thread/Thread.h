#pragma once

#include "base/Object/Object.h"
#include "base/Runnable/Runnable.h"

namespace Epp {
namespace base {

class Thread: virtual public Epp::base::Object, virtual public Epp::base::Runnable {

EPP_CLASS_INFO

public:
	static void Sleep(i32 sec);

public:
	Thread();

};

}
}

