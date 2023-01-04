#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace devices {

const Class *Device::ClassInfo = Class::Register<Device, Object>("Epp::devices::Device", nullptr);

Device::Device() {

}

Device::~Device() {

}

}
}
