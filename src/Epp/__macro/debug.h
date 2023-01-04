#pragma once

#include "defs.h"

// 代码定位相关
#define EPP_FILE_LOC0				__FILE__
#define EPP_FUNC_LOC				__FUNCTION__
#define EPP_LINE_LOC				__LINE__

// 调试相关
#ifdef EPP_TARGET_DEBUG
	#define EPP_DEBUG(...)			Epp::__Debug(__VA_ARGS__)
#else
	#define EPP_DEBUG(...)
#endif

#define EPP_CODE_LOCATE(...)			EPP_DEBUG("-----> %s:%d   %s\n", EPP_FILE_LOC, EPP_LINE_LOC, EPP_FUNC_LOC)
#define EPP_FUNC_LOCATE(fmt,...)		EPP_DEBUG("-----> %s:%d   %s(" fmt ")\n", EPP_FILE_LOC, EPP_LINE_LOC, EPP_FUNC_LOC, __VA_ARGS__)

