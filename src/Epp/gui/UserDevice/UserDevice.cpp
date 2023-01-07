#include "Epp.h"

using namespace Epp::gui;

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace gui {

const Class *UserDevice::ClassInfo = Class::Register<UserDevice, InputDevice>("Epp::gui::UserDevice", nullptr);

UserDevice::UserDevice() {

}

UserDevice::~UserDevice() {

}

}
}
