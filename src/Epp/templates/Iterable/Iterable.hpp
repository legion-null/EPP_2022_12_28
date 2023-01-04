#pragma once

#include "base/Interface/Interface.h"

#include "templates/Iterator/Iterator.hpp"

namespace Epp {
namespace templates {

template<class E>
class Iterable: implements base::Interface {

EPP_CLASS_INFO

public:
	virtual Iterator<E>* getIterator() = 0;

};

}
}

