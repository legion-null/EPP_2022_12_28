#ifdef CURRENT_OS_LINUX

#include "Epp.h"

i32 main(i32 argc, c8 **argv) {
	extern i32 epp_application_main(i32 argc, c8 **argv);

	return epp_application_main(argc, argv);
}

#endif
