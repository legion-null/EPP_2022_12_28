#pragma once

#include "defs.h"

#define interface		class

#define extends			public
#define implements		public virtual

#define E(classX)					E_TOKEN_SPLICE(E,classX)

#define E_class(classX)	\
\
typedef classX::E(classX) E(classX); /* E类型定义 */\
\

#define E_import_class(classX) \
\
class classX;\
\
typedef classX* E(classX); /* E类型定义 */\
\

#define E_init \
\
namespace Epp {\
namespace base {\
	E_import_class(Class)\
}\
}\
\

