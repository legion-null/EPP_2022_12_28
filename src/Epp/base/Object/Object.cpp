#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace base {

E_CLASS_DEF(Epp::base::Object)

void Object::Static() { // 静态块，类初始化时将会执行块内代码，为了防止Epp类型构建系统出错，静态块内的代码必须与类型加载顺序无关
}

Object::Object() {

}

void Object::destroy() {

	delete this;
}

EObject Object::clone() {
	return new Object();
}

bool Object::equalTo(EObject other) {
	return true;
}

EString Object::toString() {
	return new String("This is an Element of Epp::base::Object");
}

void Object::printContent() {
	OS::Printf(S("\n\n\n"));
	OS::Printf(S("--------------------------------------------------------------------------------\n"));
	OS::Printf(S("ClassName: %s\n"), this->getClass()->getFullClassName()->getValue());
	OS::Printf(S("Address = 0x%0x16x   Size = %-5d\n"), (u64) this, sizeof(Object));
	OS::Printf(S("--------------------------------------------------------------------------------\n"));

	byte *mem = reinterpret_cast<byte*>(this);
	for (i32 i = 0; i < (i32) sizeof(Object);) {
		OS::Printf(S("%02X "), mem[i++]);
		if (i % 27 == 0)
			OS::Printf(S("\n"));
	}
	OS::Printf(S("\n"));

	OS::Printf(S("--------------------------------------------------------------------------------\n"));
}
}

bool SafeDestroy(base::EObject obj) {
	return iSafeDestroy(obj);
}

}

