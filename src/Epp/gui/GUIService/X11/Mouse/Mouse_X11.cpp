#include "Epp.h"

#if EPP_MODULE_X11_SUPPORT == EPP_TRUE

using namespace Epp::gui;

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace gui {

const Class *Mouse_X11::ClassInfo = Class::Register<Mouse_X11, Mouse>("Epp::gui::Mouse_X11", nullptr);

Mouse_X11::Mouse_X11() {
}

Mouse_X11::~Mouse_X11() {
}

InputEvent* Mouse_X11::reportInputEvent() {
	MouseEvent *e = 0;
}

}
}

#endif
