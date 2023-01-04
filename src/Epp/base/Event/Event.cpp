#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace base {

const Class *Event::ClassInfo = Class::Register<Event, Object>("Epp::base::Event", nullptr);

Event::Event() {

}

Event::~Event() {

}

}
}
