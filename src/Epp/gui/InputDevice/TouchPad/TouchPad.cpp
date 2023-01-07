#include "Epp.h"

using namespace Epp::gui;

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace gui {

const Class *TouchPad::ClassInfo = Class::Register<TouchPad, InputDevice>("Epp::gui::TouchPad", nullptr);

TouchPad::TouchPad() {

}

TouchPad::~TouchPad() {

}

}
}
