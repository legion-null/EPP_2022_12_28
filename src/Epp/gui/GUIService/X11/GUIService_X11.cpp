#include "Epp.h"

#if EPP_MODULE_X11_SUPPORT == EPP_TRUE

using namespace Epp;
using namespace Epp::base;

#include "About_X11.h"

namespace Epp {
namespace gui {

const base::Class * GUIService_X11::ClassInfo = base::Class::Register<GUIService_X11, GUIService>("Epp::gui::GUIService_X11", nullptr);


GUIService_X11::GUIService_X11() {

}

Epp::gui::Screen* GUIService_X11::getScreen() const {
	EPP_CODE_LOCATE();
	return new Screen_X11();
}

}
}

#endif
