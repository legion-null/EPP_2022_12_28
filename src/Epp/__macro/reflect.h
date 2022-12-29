#pragma once

#include "defs.h"

#define E_REFLECT_DEC(classX,baseClassX) /* 反射声明 */ \
\
public:\
	friend class Epp::base::Class; /* Class类默认是任何类的友元类 */\
\
public:\
	typedef classX This; /* 本类型重定义 */\
	typedef baseClassX Base; /* 父类型重定义 */\
	typedef classX* E(classX); /* E类型定义 */\
\
public:\
	static base::EClass ClassInfo; /* 类型信息 */\
\
private:\
	static void Static(); /* 静态块 */\
\
protected:\
	virtual ~classX(){::printf("~\n");} /* 保护型析构函数，强制对象动态创建 */ \
\
public:\
	virtual base::EClass getClass() {\
		return This::ClassInfo;\
	}\
\


#define	E_REFLECT_DEF(classX) /* 反射定义 */ \
\
EClass classX::ClassInfo = Class::Register<classX>(new String(E_STR(classX))); /* 类型信息初始化 */\
\

//::printf("do delete 0x%016x %s\n", (u64)this, this->ClassInfo->getFullClassName()->getValue());

