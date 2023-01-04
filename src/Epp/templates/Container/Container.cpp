#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace templates {

template<class E>
const Class *Container<E>::ClassInfo = Class::Register<Container<E>, Object>("Epp::templates::Container<E>", nullptr);

template<class E>
Container<E>::Container() {

}

template<class E>
Container<E>::~Container() {

}

template<class E>
u64 Container<E>::getNumberOfElements() const {
	return this->numberOfElements;
}

template<class E>
bool Container<E>::isEmpty() const {
	return (getNumberOfElements() == 0);
}

}
}
