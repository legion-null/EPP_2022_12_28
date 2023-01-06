#include "Epp.h"

using namespace Epp::devices;

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace devices {

const base::Class *Event::ClassInfo = base::Class::Register<Event, base::Event>("Epp::devices::Event", nullptr);

Event::Event() {

}

Event::~Event() {

}

}
}
