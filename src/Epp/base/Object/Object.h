#pragma once

#include "defs.h"
#include "base/base/base.hpp"

namespace Epp {
namespace base {

class Class;
class String;

class Object {
public:\
	static const Epp::base::Class *ClassInfo;

	virtual const Epp::base::Class* getClassInfo() const;

public:
	const Epp::base::Class* getBaseClassInfo(i32 index) const;
	const Epp::base::Class* getBaseClassInfo() const;

public:
	Object();
	virtual ~Object();

public:
	virtual Object* clone();
	virtual bool equalTo(Object *other);

public:
	virtual String* toString();
	virtual void printContent();
};
}

inline bool iSafeDestroy(base::Object *obj) {
	if (obj == nullptr)
		return false;

	delete obj;
	return true;
}

bool SafeDestroy(base::Object *obj);

}

