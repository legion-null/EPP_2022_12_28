#pragma once

#include "base/Object/Object.h"
#include "base/Runnable/Runnable.h"

namespace Epp {
namespace base {

class Thread: virtual public Epp::base::Object, virtual public Epp::base::Runnable {

EPP_CLASS_INFO

public:
	static void USleep(u32 us);
	static void MSleep(u32 ms);
	static void Sleep(u32 sec);

public:
	Thread();

};

}
}

