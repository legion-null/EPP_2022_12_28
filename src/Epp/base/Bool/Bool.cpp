#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace base {

const Class *Bool::ClassInfo = Class::Register<Bool, Object>("Epp::base::Bool", nullptr);

const Bool Bool::True = true;
const Bool Bool::False = false;

Bool::Bool() {

}

Bool::~Bool() {

}

Bool::Bool(bool value) {
	this->value = value;
}

bool Bool::getValue() const {
	return this->value;
}

}
}
