#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace base {

E_CLASS_DEF(Epp::base::Class)

void Class::Static() { // 静态块，类初始化时将会执行块内代码，为了防止Epp类型构建系统出错，静态块内的代码必须与类型加载顺序无关

}

Class::Class() {

}

Class::Class(EString fullClassName) {
	this->fullClassName = fullClassName;
	this->hashCode = String::CalculateHash(this->fullClassName->getValue());

	// 输出类型注册信息
	OS::Printf(S("Registering class: [ %-30s HashCode = 0x%08x ]\n"), this->fullClassName->getValue(), this->hashCode);
}

EString Class::getFullClassName() {
	return this->fullClassName;
}

EString Class::getClassName() {
	return getFullClassName();
}

i32 Class::getHashCode() {
	return this->hashCode;
}

}
}

