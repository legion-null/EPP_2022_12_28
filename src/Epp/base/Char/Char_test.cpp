#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

using namespace Epp::base;

i32 base_Char_test_main(i32 argc, c8 **argv) {
	(void) argc;
	(void) argv;

	union __CharData {
		u8 utf8[4];
		u32 value;
	};

	__CharData c1 = { .value = 0 };
	__CharData c2;
//	c2.value = Char::ToUTF32(c1.value, Char::UTF8);
//	OS::Printf("%s(0x%08X) == %s(0x%08X)\n", c1.utf8, c1.value, c2.utf8, c2.value);
//	c1.value = Char::FromUTF32(c2.value, Char::UTF8);
//	OS::Printf("%s(0x%08X) == %s(0x%08X)\n", c2.utf8, c2.value, c1.utf8, c1.value);

	u64 error = 0;
	for (u32 i = 0; i <= 1114112; i++) { // 测试通过
		c1.value = i;
		c1.value = Char::FromUTF32(c1.value, Char::UTF8);
		c2.value = Char::ToUTF32(c1.value, Char::UTF8);
		c2.value = Char::FromUTF32(c2.value, Char::UTF8);
		OS::Printf("0x%08X: (0x%08X) == (0x%08X)", i, c1.value, c2.value);
		if (c1.value != c2.value) {
			OS::Printf("\tF %lu\n", error++);
			break;
		} else {
			OS::Printf("\tT\n");
		}
	}

	return 0;
}
