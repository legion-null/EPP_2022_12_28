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
	virtual bool equalTo(const Object &other);

public:
	bool operator==(const Object &other);

public:
	virtual const String& toString() const;
	virtual void printContent();
};

}
}

