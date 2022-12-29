#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

#include <unistd.h>

namespace Epp {
namespace base {

E_CLASS_DEF(Epp::base::Thread)

void Thread::Static() { // 静态块，类初始化时将会执行块内代码，为了防止Epp类型构建系统出错，静态块内的代码必须与类型加载顺序无关

}

void Thread::Sleep(i32 sec) {
	::sleep(sec);
}

Thread::Thread() {

}

void Thread::destroy() {
	delete this;
}

}
}
