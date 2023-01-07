#include "Epp.h"

using namespace Epp::gui;

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace gui {

const Class *TouchPadEvent::ClassInfo = Class::Register<TouchPadEvent, InputEvent>("Epp::gui::TouchPadEvent", nullptr);

TouchPadEvent::TouchPadEvent() {

}

TouchPadEvent::~TouchPadEvent() {

}

}
}
