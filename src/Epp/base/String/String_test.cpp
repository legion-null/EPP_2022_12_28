#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

i32 base_String_test_main(i32 argc, c8 **argv) {
	(void) argc;
	(void) argv;

	String str = "Test";

	OS::Printf("%s", str.getValue());

	return 0;
}
