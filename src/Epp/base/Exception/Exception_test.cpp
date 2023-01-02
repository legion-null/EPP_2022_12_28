#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

i32 base_Exception_test_main(i32 argc, c8 **argv) {
	(void) argc;
	(void) argv;

	Exception* e = Exception::UnknownException();

	return 0;
}
