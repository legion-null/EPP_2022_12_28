#pragma once

#include "base/base.hpp"

E_init

namespace Epp {
namespace base {

E_import_class(String)

class Object {

E_CLASS_DEC(Object,Object)

public:
	Object();
	virtual void destroy();

public:
	virtual EObject clone();
	virtual bool equalTo(EObject other);

public:
	virtual EString toString();
	virtual void printContent();
};

E_class(Object)

}

inline bool iSafeDestroy(base::EObject obj) {
	if (obj == nullptr)
		return false;

	obj->destroy();
	return true;
}

bool SafeDestroy(base::EObject obj);

}

