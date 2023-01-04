#pragma once

#include "templates/Container/Container.hpp"

namespace Epp {
namespace templates {

template<class E>
class Vector: public Container<E> {

EPP_CLASS_INFO

public:
	Vector();
	virtual ~Vector();

};

}
}

