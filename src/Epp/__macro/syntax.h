#pragma once

#include "defs.h"

#define self					(*this)

#define EPP_NULL_MACRO
#define EPP_LINE_NOTE 			/EPP_NULL_MACRO/
#define EPP_NOTE				/EPP_NULL_MACRO*

#define EPP_CLASS_INFO \
\
public:\
	static const Epp::base::Class *ClassInfo;\
\
	virtual const Epp::base::Class* getClassInfo() const override {\
		return ClassInfo;\
	}\
\

