#include "Epp.h"

using namespace Epp::gui;

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace gui {

const Class *MouseEvent::ClassInfo = Class::Register<MouseEvent, InputEvent>("Epp::gui::MouseEvent", nullptr);

MouseEvent::MouseEvent() {

}

MouseEvent::~MouseEvent() {

}

}
}
