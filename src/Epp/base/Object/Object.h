#pragma once

#include "defs.h"
#include "base/base/base.hpp"

namespace Epp {
namespace base {

class Class;
class String;

class Object {
public:
	static const Class *ClassInfo;
	virtual const Class* getClassInfo() const;

public:
	const Class* getBaseClassInfo(i32 index) const;
	const Class* getBaseClassInfo() const;

public:
	Object();
	virtual ~Object();

public:
	Object(const Object &other) = default;
	Object(Object &&other) = default;

public:
	Object& operator=(const Object &other) = default;
	Object& operator=(Object &&other) = default;

public:
	virtual bool equalTo(const Object &obj) const;

public:
	bool operator==(const Object &obj) const;

public:
	virtual const String& toString() const;
	virtual void printContent();
};

template<class E>
inline bool operator==(const E &obj1, const E &obj2) {
	return obj1 == ((const Object&) obj2);
}

template<class E>
inline bool operator!=(const E &obj1, const E &obj2) {
	return !(obj1 == obj2);
}

}
}

