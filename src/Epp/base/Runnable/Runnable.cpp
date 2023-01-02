#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace base {

const Class *Runnable::ClassInfo = Class::Register<Runnable, Interface>("Epp::base::Runnable", nullptr);

}
}
