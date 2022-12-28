#pragma once

#include "defs.h"

#define E_REFLECT_DEC(classX,baseClassX) /* 反射声明 */ \
\
public:\
	friend class Epp::base::Class; /* Class类默认是任何类的友元类 */\
\
public:\
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
	virtual ~classX() {/* 保护型析构函数，不做任何事，仅用于防止创建在栈上的实例 */} \
\


#define	E_REFLECT_DEF(classX) /* 反射定义 */ \
\
	EClass classX::ClassInfo = Class::Register<classX>(new String(E_STR(classX))); /* 类型信息初始化 */\
\

