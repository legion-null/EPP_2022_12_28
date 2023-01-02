#pragma once
#include "defs.h"

extern const c8* __GetFileBaseName(const c8 *path);

// 标识符转字符串
#define __EPP_STR(X)				#X
#define EPP_STR(X)					__EPP_STR(X)

// 字符串拼接
#define __EPP_TOKEN_SPLICE(A,B)		A##B
#define EPP_TOKEN_SPLICE(A,B)		__EPP_TOKEN_SPLICE(A,B)

// 代码定位相关
#define EPP_FILE_LOC0				__FILE__
#define EPP_FUNC_LOC				__FUNCTION__
#define EPP_LINE_LOC				__LINE__

#define EPP_FILE_LOC				__GetFileBaseName(EPP_FILE_LOC0)
// 编译相关信息
#define __EPP_TIME_STAMP			"%s,%s,%s\n",__DATE__,__TIME__,__TIMESTAMP__
#define __EPP_CC_VERSION			"GCC Version = %s\n",__VERSION__

// 调试相关
#ifdef EPP_DEBUG
	#define EPP_DEBUG(fmt,...)		Epp::__Debug(fmt, __VA_ARGS__)
#else
	#define EPP_DEBUG(fmt,...)
#endif

#define EPP_CODE_LOCATE(...)		EPP_DEBUG("-----> %s:%d   %s\n", EPP_FILE_LOC, EPP_LINE_LOC, EPP_FUNC_LOC)

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
