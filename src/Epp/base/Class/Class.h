#pragma once

#include "base/Object/Object.h"

E_init

namespace Epp {
namespace base {

E_import_class(String)

class Class: extends Object {

E_CLASS_DEC(Class,Object)

//public:
//	typedef Class This; /* 本类型重定义 */
//	typedef Object Base; /* 父类型重定义 */
//	typedef Class *E(Class); /* E类型定义 */
//
//public:
//	static base::EClass ClassInfo; /* 类型信息 */
//
//private:
//	static void Static(); /* 静态块 */
//
//protected:virtual ~Class() {} /* 保护型析构函数，强制对象动态创建 */
//
//public:
//	virtual base::EClass getClass() {
//		return This::ClassInfo;
//	}

public:
	template<class E>
	static EClass Register(EString fullClassName) {
		EClass classInfo = new Class(fullClassName);
		E::Static();
		return classInfo;
	}

protected:
	EString fullClassName = nullptr;
	i32 hashCode = 0;

public:
	Class();

public:
	Class(EString fullClassName);

public:
	EString getFullClassName();
	EString getClassName();
	i32 getHashCode();

};

E_class(Class)

}
}
