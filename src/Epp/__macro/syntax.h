#pragma once

#include "defs.h"

#define interface				class

#define public_class			class EPP_EXPORT
#define protected_class			class EPP_HIDDEN
#define private_class			class EPP_HIDDEN

#define public_interface		class EPP_EXPORT
#define protected_interface		class EPP_HIDDEN
#define private_interface		class EPP_HIDDEN

#define extends					public
#define implements				public virtual

#define E(classX)				EPP_TOKEN_SPLICE(E,classX)

#define E_class(classX)	\
\
typedef classX* E(classX); /* E类型定义 */\
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

