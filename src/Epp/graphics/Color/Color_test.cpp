#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

using namespace Epp::graphics;

i32 graphics_Color_test_main(i32 argc, c8 **argv) {
	(void) argc;
	(void) argv;

	Color::Type type1;
	Color::Type type2;
	color_t c1 = 0x55555555;
	color_t c2 = 0;

	for (i32 i = Color::RGB565; i <= Color::RGBA8888; i += 1) {
		for (i32 j = Color::RGB565; j <= Color::RGBA8888; j += 1) {
			type1 = (Color::Type) i;
			type2 = (Color::Type) j;
			c2 = Color::Transform(c1, type1, type2);
			OS::Printf(S("%s ---> %s 0x%08X ---> 0x%08X"), Color::GetTypeName(type1), Color::GetTypeName(type2), c1, c2);
			if (type1 == type2) {
				if (c1 == c2) {
					OS::Printf(S("\tT"));
				} else {
					OS::Printf(S("\tF"));
				}
			}
			OS::Printf(S("\n"));
		}
		OS::Printf(S("\n"));
	}

	struct __RGBX8888 {
		u8 r;
		u8 g;
		u8 b;
		u8 x;
	};

	struct __XRGB8888 {
		u8 x;
		u8 r;
		u8 g;
		u8 b;
	};

	union __C {
		u32 value;
		struct __RGBX8888 rgbx8888;
		struct __XRGB8888 xrgb8888;
	};

	__C    __c1; __C    __c2; __c1
	.value = 0x00112233;
	__c2.value = __c1.value;

	OS::Printf(S("0x%02X 0x%02X 0x%02X 0x%02X\n"), __c1.rgbx8888.r, __c1.rgbx8888.g, __c1.rgbx8888.b, __c1.rgbx8888.x);
	OS::Printf(S("0x%08X ---> 0x%08X\n"), __c1.value, __c2.value);

	__c2.rgbx8888.r = __c1.xrgb8888.r;
	__c2.rgbx8888.g = __c1.xrgb8888.g;
	__c2.rgbx8888.b = __c1.xrgb8888.b;

	OS::Printf(S("0x%08X ---> 0x%08X\n"), __c1.value, __c2.value);

	return 0;
}
