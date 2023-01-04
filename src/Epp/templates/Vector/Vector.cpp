#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace templates {

template<class E>
const Class *Vector<E>::ClassInfo = Class::Register<Vector<E>, Container<E>>("Epp::templates::Vector<E>", nullptr);

template<class E>
Vector<E>::Vector() {

}

template<class E>
Vector<E>::~Vector() {

}

}
}
