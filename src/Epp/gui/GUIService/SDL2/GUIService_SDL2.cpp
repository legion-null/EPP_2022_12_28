#ifdef USE_LIB_SDL2

#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace gui {

E_CLASS_DEF(Epp::gui::GUIService_SDL2)

void GUIService_SDL2::Static() { // 静态块，类初始化时将会执行块内代码，为了防止Epp类型构建系统出错，静态块内的代码必须与类型加载顺序无关

}

GUIService_SDL2::GUIService_SDL2() {

}

void GUIService_SDL2::destroy() {
	delete this;
}

}
}

#endif
