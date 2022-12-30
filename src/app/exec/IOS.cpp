#ifdef CURRENT_OS_IOS

#include "Epp.h"

extern i32 epp_application_main(i32 argc, c8 **argv);

i32 main(i32 argc, c8 **argv) {
	return epp_application_main(argc, argv);
}

#endif
