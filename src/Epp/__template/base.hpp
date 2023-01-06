#pragma once

#include "defs.h"

namespace Epp {

template<class E>
class TCopyAndMove {

public:
	E& operator=(const E &other) {
		return copy(other);
	}

	E& operator=(E &&other) {
		return move(static_cast<E&&>(other));
	}

public:
	virtual E& copy(const E &other) = 0;
	virtual E& move(E &&other) = 0;

};

template<class E>
class TEPP: public TCopyAndMove<E> {

};

}
