#pragma once

#include "base/Object/Object.h"

#include "templates/Iterable/Iterable.hpp"

namespace Epp {
namespace templates {

template<class E>
class Container: extends base::Object, implements Iterable<E> {
EPP_CLASS_INFO

protected:
	i32 numberOfElements = 0;

public:
	Container();
	~Container();

public:
	i32 getNumberOfElements() const;

	bool isEmpty() const;

public:
	virtual E* getElement(i32 index) = 0;
	virtual void setElement(i32 index, const E *e) = 0;

public:
	virtual void addElement(const E *e) = 0;
	virtual void deleteElement(i32 index) = 0;
	virtual void updateElement(const E *oldE, const E *newE) = 0;
	virtual i32 searchElement(const E *e) = 0;

public:
	virtual i32 searchElement(bool (*customizedCompareFunc)(const E *e1, const E *e2)) = 0;

};

}
}

