#pragma once

#include "defs.h"

#define extends			public
#define implements		virtual public

#define EPP_CLASS_INFO \
\
public:\
	static const Epp::base::Class *ClassInfo;\
\
	virtual const Epp::base::Class* getClassInfo() const override {\
		return ClassInfo;\
	}\
\

