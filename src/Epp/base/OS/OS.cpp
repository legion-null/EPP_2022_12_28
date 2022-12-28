#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace base {

E_CLASS_DEF(Epp::base::OS)

void OS::Static() { // 静态块，类初始化时将会执行块内代码，为了防止Epp类型构建系统出错，静态块内的代码必须与类型加载顺序无关

}

void OS::Printf(EString fmt, ...) {
	::va_list args;
	::va_start(args,fmt);
	::vprintf(fmt->getValue(), args);
	::va_end(args);

	::fflush(stdout);
}

void OS::PrintMemory(byte *address, i32 len) {

}

OS::OS() {

}

}
}
