#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

#include <stdio.h>
#include <stdarg.h>

namespace Epp {
namespace base {

const Class *OS::ClassInfo = Class::Register<OS, Object>("Epp::base::OS", nullptr);

void OS::Printf(String *fmt, ...) {
	::va_list args;
	::va_start(args,fmt);
	::vprintf(fmt->getValue(), args);
	::va_end(args);

	::fflush (stdout);
}

void OS::PrintMemory(byte *address, i32 len) {

}

OS::OS() {

}

}
}
