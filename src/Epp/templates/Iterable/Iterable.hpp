#pragma once

#include "base/Interface/Interface.h"

#include "templates/Iterator/Iterator.hpp"

namespace Epp {
namespace templates {

template<class E>
class Iterable: virtual public base::Interface {

EPP_CLASS_INFO

public:
	virtual Iterator<E>* getIterator() = 0;

};

template<class E>
const base::Class *Iterable<E>::ClassInfo = base::Class::Register<Iterable<E>, base::Interface>("Epp::templates::Iterable<?>", nullptr);


}
}

