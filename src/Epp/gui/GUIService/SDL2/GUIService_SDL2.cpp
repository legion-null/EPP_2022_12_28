#include "Epp.h"

#if EPP_MODULE_SDL2_SUPPORT == EPP_TRUE

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace gui {

const Class *GUIService_SDL2::ClassInfo = Class::Register<GUIService_SDL2, GUIService>("Epp::gui::GUIService_SDL2", nullptr);

GUIService_SDL2::GUIService_SDL2() {

}

Screen* GUIService_SDL2::getScreen() const {
	return new Screen_SDL2();
}

}
}

#endif
