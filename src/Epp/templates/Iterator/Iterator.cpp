#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace templates {

template<class E>
const Class *Iterator<E>::ClassInfo = Class::Register<Iterator<E>, Object>("Epp::templates::Iterator<?>:", nullptr);

}
}
