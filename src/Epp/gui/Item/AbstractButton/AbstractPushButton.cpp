#include "Epp.h"

using namespace Epp::gui;

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace gui {

const Class *AbstractPushButton::ClassInfo = Class::Register<AbstractPushButton, Item>("Epp::gui::AbstractPushButton", nullptr);

AbstractPushButton::AbstractPushButton() {

}

AbstractPushButton::~AbstractPushButton() {

}

}
}
