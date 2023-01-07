#include "Epp.h"

using namespace Epp::gui;

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace gui {

const Class *AbstractButton::ClassInfo = Class::Register<AbstractButton, Item>("Epp::gui::AbstractPushButton", nullptr);

AbstractButton::AbstractButton() {

}

AbstractButton::~AbstractButton() {

}

void AbstractButton::doClick() {

}

}
}
