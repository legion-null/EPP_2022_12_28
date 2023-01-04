#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace devices {

const Class *InputDevice::ClassInfo = Class::Register<InputDevice, Device>("Epp::devices::InputDevice", nullptr);

InputDevice::InputDevice() {

}

InputDevice::~InputDevice() {

}

}
}
