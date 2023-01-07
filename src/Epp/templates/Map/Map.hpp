#pragma once

#include "templates/Container/Container.hpp"

namespace Epp {
namespace templates {

template<class E>
class Map: public Container<E> {

EPP_CLASS_INFO

public:
	Map(){

	}

	virtual ~Map(){

	}

public:


};

template<class E>
const base::Class *Map<E>::ClassInfo = base::Class::Register<Map<E>, Container<E>>("Epp::templates::Map", nullptr);


}
}

