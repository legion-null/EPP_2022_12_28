#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace devices {

const Class *OutputDevice::ClassInfo = Class::Register<OutputDevice, Object>("Epp::devices::OutputDevice", nullptr);

OutputDevice::OutputDevice() {

}

OutputDevice::~OutputDevice() {

}

}
}
