#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace base {

const Class *Object::ClassInfo = Class::Register<Epp::base::Object>("Epp::base::Object", nullptr);

const Class* Object::getClassInfo() const {
	return ClassInfo;
}

const Class* Object::getBaseClassInfo(i32 index) const {
	return getClassInfo()->getBaseClassInfo(index);
}

const Class* Object::getBaseClassInfo() const {
	return getBaseClassInfo(0);
}

Object::Object() {

}

Object::~Object() {

}

Object* Object::clone() {
	return new Object();
}

bool Object::equalTo(Object *other) {
	return true;
}

String* Object::toString() {
	return new String("This is an Element of Epp::base::Object");
}

void Object::printContent() {
//	OS::Printf(S("\n\n\n"));
//	OS::Printf(S("--------------------------------------------------------------------------------\n"));
//	OS::Printf(S("ClassName: %s\n"), this->getClass()->getFullClassName()->getValue());
//	OS::Printf(S("Address = 0x%0x16x   Size = %-5d\n"), (u64) this, sizeof(Object));
//	OS::Printf(S("--------------------------------------------------------------------------------\n"));
//
//	byte *mem = reinterpret_cast<byte*>(this);
//	for (i32 i = 0; i < (i32) sizeof(Object);) {
//		OS::Printf(S("%02X "), mem[i++]);
//		if (i % 27 == 0)
//			OS::Printf(S("\n"));
//	}
//	OS::Printf(S("\n"));
//
//	OS::Printf(S("--------------------------------------------------------------------------------\n"));
}
}

bool SafeDestroy(base::Object *obj) {
	return iSafeDestroy(obj);
}

}

