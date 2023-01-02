#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

i32 base_Object_test_main(i32 argc, c8 **argv) {
	(void) argc;
	(void) argv;

	Object* obj = new Object();
	String* str = new String("Hello,World!");
	obj->printContent();
	str->printContent();

	return 0;
}

