#pragma once

#include "base/Object/Object.h"

namespace Epp {
namespace base {

class String;

class Class final: extends Object {

EPP_CLASS_INFO

protected:
	String *fullClassName = nullptr;
	i32 hashCode = 0;

	void (*classStaticInitFunc)(void) = nullptr;

protected:
	const Class **baseClassInfoList = nullptr; // 这里需要保证基类先被创建
	i8 baseClassN = 0;

protected:
	Class() = delete;
	Class(const c8 *fullClassName, i32 baseClassN, void (*classStaticInitFunc)(void));

public:
	String* getFullClassName();
	String* getClassName();
	i32 getHashCode();

public:
	i32 getNumberOfBaseClass() const;

	const Class* getBaseClassInfo(i8 index) const;
	const Class* getBaseClassInfo() const;

private:
	template<class E>
	static void __DealWithClassInfo(Class *classInfo) {
		if (classInfo->baseClassN == 0) {
			// 对本类元信息进行相关处理

		} else {
			// 对基类元信息进行相关处理
			classInfo->baseClassInfoList[classInfo->baseClassN++] = E::ClassInfo;
		}
	}

	template<class E, class F, class ...ARGS>
	static void __DealWithClassInfo(Class *classInfo) {
		__DealWithClassInfo<E>(classInfo);
		__DealWithClassInfo<F, ARGS...>(classInfo);
	}

private:
	void finishRegister();

public:
	template<class ThisClass, class ...BaseClassList>
	static Class* Register(const c8 *fullClassName, void (*classStaticInitFunc)(void)) {
		Class *classInfo = new Class(fullClassName, sizeof...(BaseClassList), classStaticInitFunc);

		// 通过可变参数模板函数遍历每一个类型，并进行相应处理
		__DealWithClassInfo<ThisClass, BaseClassList...>(classInfo);

		// 完成注册
		classInfo->finishRegister();

		return classInfo;
	}
};
}
}

