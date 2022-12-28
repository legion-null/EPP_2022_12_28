#pragma once

#include "defs.h"

#define E_CLASS_DEC(classX,baseClassX) /* 类声明 */ \
\
E_REFLECT_DEC(classX,baseClassX) /* 反射声明 */\
\

#define	E_CLASS_DEF(classX) /* 类定义 */ \
\
E_REFLECT_DEF(classX) /* 反射定义 */\
\

