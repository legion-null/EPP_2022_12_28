#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace base {

const Class *Object::ClassInfo = Class::Register<Object>("Epp::Object", nullptr);

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

bool Object::equalTo(const Object &other) const {
	return (this->getClassInfo() == other.getClassInfo());
}

bool Object::operator ==(const Object &other) const {
	return this->equalTo(other);
}

const String& Object::toString() const {
	static String str = "This is an Element of Epp::Object";
	return str;
}

void Object::printContent() {
//	OS::Printf("\n\n\n");
//	OS::Printf("--------------------------------------------------------------------------------\n");
//	OS::Printf("ClassName: %s\n", this->getClass()->getFullClassName()->getValue());
//	OS::Printf("Address = 0x%0x16x   Size = %-5d\n", (u64) this, sizeof(Object));
//	OS::Printf("--------------------------------------------------------------------------------\n");
//
//	byte *mem = reinterpret_cast<byte*>(this);
//	for (i32 i = 0; i < (i32) sizeof(Object);) {
//		OS::Printf("%02X "), mem[i++]);
//		if (i % 27 == 0)
//			OS::Printf("\n");
//	}
//	OS::Printf("\n");
//
//	OS::Printf("--------------------------------------------------------------------------------\n");

}

}
}

