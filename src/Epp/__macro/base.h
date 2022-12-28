#pragma once

#include "defs.h"

// 标识符转字符串
#define __E_STR(X)					#X
#define E_STR(X)					__E_STR(X)

// 字符串拼接
#define __E_TOKEN_SPLICE(A,B)		A##B
#define E_TOKEN_SPLICE(A,B)			__E_TOKEN_SPLICE(A,B)

// 编译相关信息
#define E_CODE_LOCATE			"文件:%s, 函数:%s, 行:%d\n",__FILE__,__FUNCTION__,__LINE__
#define E_TIME_STAMP			"%s,%s,%s\n",__DATE__,__TIME__,__TIMESTAMP__
#define E_CC_VERSION			"GCC 版本 = %s\n",__VERSION__
