#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

i32 base_Error_test_main(i32 argc, c8 **argv) {
	(void) argc;
	(void) argv;

	Error *e = Error::UnknownError();

	(void) e;

	return 0;
}
