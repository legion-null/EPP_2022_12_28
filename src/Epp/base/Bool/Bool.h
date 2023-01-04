#pragma once

#include "base/Object/Object.h"

namespace Epp {
namespace base {



class Bool: public Epp::base::Object {

EPP_CLASS_INFO

public:
	static const Bool True;
	static const Bool False;

protected:
	bool value = false;

public:
	Bool();
	virtual ~Bool();

public:
	Bool(bool value);

public:
	bool getValue() const;

};

}
}

