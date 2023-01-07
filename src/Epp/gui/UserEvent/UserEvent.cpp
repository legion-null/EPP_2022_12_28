#include "Epp.h"

using namespace Epp::gui;

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace gui {

const Class *UserEvent::ClassInfo = Class::Register<UserEvent, InputEvent>("Epp::gui::UserEvent", nullptr);

UserEvent::UserEvent() {

}

UserEvent::~UserEvent() {

}

}
}
