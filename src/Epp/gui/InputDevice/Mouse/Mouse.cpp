#include "Epp.h"

using namespace Epp::gui;

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace gui {

const Class *Mouse::ClassInfo = Class::Register<Mouse, InputDevice>("Epp::gui::Mouse", nullptr);

Mouse::Mouse() {

}

Mouse::~Mouse() {

}

}
}
