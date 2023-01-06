#pragma once

#include "base/Object/Object.h"

#include "templates/Iterable/Iterable.hpp"

namespace Epp {
namespace templates {

template<class E>
class Container: virtual public Epp::base::Object, virtual public Iterable<E> {
EPP_CLASS_INFO

protected:
	u64 n = 0;

public:
	Container() {

	}

	virtual ~Container() {

	}

public:
	u64 getN() const {
		return this->n;
	}

	bool isEmpty() const {
		return (getN() == 0 ? true : false);
	}

public:
	virtual const E& getElement(u64 index) const = 0;
	virtual void setElement(u64 index, const E &e) const = 0;

public:
	const E& operator[](u64 index) const {
		return this->getElement(index);
	}

	E& operator[](u64 index) {
		return (E&) (this->getElement(index));
	}

public:
	const E& getFirst() {
		return getElement(0);
	}

	const E& getLast() {
		return getElement(getN() - 1);
	}

	void setFirst(const E &e) {
		setElement(0, e);
	}

	void setLast(const E &e) {
		setElement(getN() - 1, e);
	}

public:
	virtual void addElement(const E &e) = 0;
	virtual void deleteElement(u64 index) = 0;
	virtual void updateElement(u64 index, const E &newE) = 0;
	virtual u64 searchElement(const E &e) = 0;

public:
	virtual u64 searchElement(bool (*customizedCompareFunc)(E &e1, E &e2), E &e) = 0;

public:
	void paintAllElements() {
		for (u64 i = 0; i < this->getN(); i++) {
			base::OS::Printf("[%d] %s\n", i, base::String::ValueOf(this->getElement(i)).getValue());
		}
	}

public:
	virtual Iterator<E>* getIterator() override {
		return nullptr;
	}

};

template<class E>
const base::Class *Container<E>::ClassInfo = base::Class::Register<Container<E>, base::Object>("Epp::templates::Container<E>", nullptr);

}
}

