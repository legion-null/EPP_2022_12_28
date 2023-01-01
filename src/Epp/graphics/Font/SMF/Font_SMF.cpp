#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace graphics {

E_CLASS_DEF(Epp::graphics::Font_SMF)

void Font_SMF::Static() { // 静态块，类初始化时将会执行块内代码，为了防止Epp类型构建系统出错，静态块内的代码必须与类型加载顺序无关

}

Font_SMF::Font_SMF() {

}

void Font_SMF::destroy() {
	Base::destroy();
}

}
}
