#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

#include <unistd.h>

namespace Epp {
namespace base {

const Class *Thread::ClassInfo = Class::Register<Thread, Object, Runnable>("Epp::base::Thread", nullptr);

void Thread::Sleep(i32 sec) {
	::sleep(sec);
}

Thread::Thread() {

}

}
}
