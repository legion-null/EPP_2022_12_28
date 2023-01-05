#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

//static const c8 *text =
//		"aarch64,alpha,arm,avr,cris,hppa,i386,loongarch64,m68k,microblaze,microblazeel,mips,mips64,mips64el,mipsel,nios2,or1k,ppc,ppc64,riscv32,riscv64,rx,s390x,sh4,sh4eb,sparc,sparc64,tricore,x86_64,xtensa,xtensaeb,";

//static const c8 *text = "Bit1Gray,Bit2Gray,Bit4Gray,Bit8Gray,Bit1Palette,Bit2Palette,Bit3Palette,Bit4Palette,RGB232,RGB555,RGB565,RGB888,XRGB8888,RGBX8888,ARGB1555,ARGB8888,RGBA8888,";

static const c8 *text = "Windows,MacOS,Android,IOS,X11,SDL2,LinuxFB,";

i32 tools_GetEnumName_main(i32 argc, c8 **argv) {
	(void) argc;
	(void) argv;

	OS::Printf("const c8* %s::GetEnumName(%s e) {\n", "GUIService", "IMType");
	OS::Printf("switch(e) {\n");
	c8 enumName[100];
	for (i32 i = 0; i < String::strlen(text); i++) {
		if (text[i] != ',') {
			i32 j = 0;
			for (; text[i] != ',' and text[i] != '\0'; j++, i++) {
				enumName[j] = text[i];
			}
			enumName[j] = 0;
			OS::Printf("case %s:\n", enumName);
			OS::Printf("return EPP_STR(%s);\n", enumName);
		}
	}
	OS::Printf("default:\nthrow new Exception(\"Careless forced transformation\");\n");
	OS::Printf("}\n");
	OS::Printf("}");

	return 0;
}
