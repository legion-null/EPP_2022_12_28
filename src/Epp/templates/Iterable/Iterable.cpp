#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace templates {

template<class E>
const Class *Iterable<E>::ClassInfo = Class::Register<Iterable<E>, Interface>("Epp::templates::Iterable<?>", nullptr);

}
}
