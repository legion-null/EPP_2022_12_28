#pragma once

#include "templates/List/List.hpp"

namespace Epp {
namespace templates {

template<class E>
class Queue: public List<E> {

EPP_CLASS_INFO

public:
	Queue(){

	}

	virtual ~Queue(){

	}

private:
	using List<E>::addElement;
	using List<E>::deleteElement;

public:
	void enqueue(const E &e) {
		this->addElement(e);
	}

	E dequeue() {
		E e = this->getFirst();
		this->deleteElement(0);
		return e;
	}

};

template<class E>
const base::Class *Queue<E>::ClassInfo = base::Class::Register<Queue<E>, List<E>>("Epp::templates::Queue<E>", nullptr);


}
}

