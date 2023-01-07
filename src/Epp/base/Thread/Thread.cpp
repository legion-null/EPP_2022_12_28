#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

#include <unistd.h>

namespace Epp {
namespace base {

const Class *Thread::ClassInfo = Class::Register<Thread, Object, Runnable>("Epp::base::Thread", nullptr);

void Thread::USleep(u32 us) {
#if EPP_CURRENT_OS == EPP_OS_WINDOWS
	::Sleep(us / 1000);
#else
	::usleep(us);
#endif
}

void Thread::MSleep(u32 ms) {
	USleep(1000 * ms);
}

void Thread::Sleep(u32 sec) {
#if EPP_CURRENT_OS == EPP_OS_WINDOWS
	::Sleep(1000 * sec);
#else
	::sleep(sec);
#endif
}

Thread::Thread() {

}

}
}
