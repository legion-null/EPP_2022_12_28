#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

i32 base_Error_test_main(i32 argc, c8 **argv) {
	(void) argc;
	(void) argv;

	EError e = Error::UnknownError();
	e->destroy();

	return 0;
}
