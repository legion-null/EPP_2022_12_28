#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace base {

const Class *Class::ClassInfo = Class::Register<Class, Object>("Epp::base::Class", nullptr);

Class::Class(const c8 *fullClassName, i32 baseClassN, void (*classStaticInitFunc)(void)) {
	this->fullClassName = new String(fullClassName);
	this->baseClassN = baseClassN;
	this->classStaticInitFunc = classStaticInitFunc;

	this->baseClassInfoList = new const Class*[this->baseClassN];

	this->hashCode = String::CalculateHash(this->fullClassName->getValue());

	this->baseClassN = 0; // 将这个变量作为计数使用
}

String* Class::getFullClassName() {
	return this->fullClassName;
}

String* Class::getClassName() {
	return getFullClassName();
}

i32 Class::getHashCode() {
	return this->hashCode;
}

i32 Class::getNumberOfBaseClass() const {
	return this->baseClassN;
}

const Class* Class::getBaseClassInfo(i8 index) const{
	if(index<0 or index >=getNumberOfBaseClass()){
		throw 0;
	}

	return this->baseClassInfoList[index];
}

const Class* Class::getBaseClassInfo() const{
	return getBaseClassInfo(0);
}

void Class::finishRegister() {
	if (this->classStaticInitFunc != nullptr) {
		(*classStaticInitFunc)();
	}

	// 展示类元信息
	//EPP_DEBUG("Class: %s\n", this->fullClassName->getValue());
}

}
}

