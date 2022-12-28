#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

i32 base_Object_test_main(i32 argc, c8 **argv) {
	(void) argc;
	(void) argv;

	EObject obj = new Object();
	EString str = new String("Hello,World!");
	obj->printContent();
	str->printContent();

	return 0;
}

