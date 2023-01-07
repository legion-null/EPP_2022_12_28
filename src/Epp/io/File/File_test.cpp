#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

using namespace Epp::io;

i32 io_File_test_main(i32 argc, c8 **argv) {
	(void) argc;
	(void) argv;

	File::GetStandardOutput().write((u8*)"Hello,World!", 12);

	return 0;
}
