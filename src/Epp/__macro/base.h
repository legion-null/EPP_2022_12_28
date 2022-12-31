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

// 导出符号相关宏
#if EPP_CURRENT_COMPILER == EPP_COMPILER_GCC
	#define __EPP_EXPORT		__attribute__ ((visibility("default")))
	#define __EPP_HIDDEN		__attribute__ ((visibility("hidden")))
	#define __EPP_IMPORT
#endif

#if EPP_CURRENT_COMPILER == EPP_COMPILER_CLANG
	#define __EPP_EXPORT		__attribute__ ((visibility("default")))
	#define __EPP_HIDDEN		__attribute__ ((visibility("hidden")))
	#define __EPP_IMPORT
#endif

#if EPP_CURRENT_COMPILER == EPP_COMPILER_MSVC
	#define __EPP_EXPORT		__declspec(dllexport)
	#define __EPP_HIDDEN
	#define __EPP_IMPORT		__declspec(dllimport)
#endif

#define EPP_EXPORT		__EPP_EXPORT
#define EPP_HIDDEN		__EPP_HIDDEN
#define EPP_IMPORT		__EPP_IMPORT
