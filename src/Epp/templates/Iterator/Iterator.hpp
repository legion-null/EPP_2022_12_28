#pragma once

#include "base/Interface/Interface.h"

namespace Epp {
namespace templates {

template<class E>
class Iterator: public Epp::base::Object {

EPP_CLASS_INFO

public:
	virtual bool hasNext() const = 0;
	virtual E next() const = 0;
	virtual void remove() const = 0;
};

template<class E>
const base::Class *Iterator<E>::ClassInfo = base::Class::Register<Iterator<E>, base::Object>("Epp::templates::Iterator<?>:", nullptr);


}
}

