#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

#include <stdio.h>
#include <stdarg.h>

namespace Epp {
namespace base {

const Class *OS::ClassInfo = Class::Register<OS, Object>("Epp::base::OS", nullptr);

bool OS::IsLittleEndian() {
	return (LittleEndian == 1);
}

const c8* OS::GetEnumName(OS_t e) {
	switch (e) {
	case Linux:
		return EPP_STR(Linux);
	case MacOS:
		return EPP_STR(MacOS);
	case Windows:
		return EPP_STR(Windows);
	case Android:
		return EPP_STR(Android);
	case IOS:
		return EPP_STR(IOS);
	default:
		throw new Exception("Careless forced transformation");
	}
}

const c8* OS::GetEnumName(arch_t e) {
	switch (e) {
	case aarch64:
		return EPP_STR(aarch64);
	case alpha:
		return EPP_STR(alpha);
	case arm:
		return EPP_STR(arm);
	case avr:
		return EPP_STR(avr);
	case cris:
		return EPP_STR(cris);
	case hppa:
		return EPP_STR(hppa);
	case i386:
		return EPP_STR(i386);
	case loongarch64:
		return EPP_STR(loongarch64);
	case m68k:
		return EPP_STR(m68k);
	case microblaze:
		return EPP_STR(microblaze);
	case microblazeel:
		return EPP_STR(microblazeel);
	case mips:
		return EPP_STR(mips);
	case mips64:
		return EPP_STR(mips64);
	case mips64el:
		return EPP_STR(mips64el);
	case mipsel:
		return EPP_STR(mipsel);
	case nios2:
		return EPP_STR(nios2);
	case or1k:
		return EPP_STR(or1k);
	case ppc:
		return EPP_STR(ppc);
	case ppc64:
		return EPP_STR(ppc64);
	case riscv32:
		return EPP_STR(riscv32);
	case riscv64:
		return EPP_STR(riscv64);
	case rx:
		return EPP_STR(rx);
	case s390x:
		return EPP_STR(s390x);
	case sh4:
		return EPP_STR(sh4);
	case sh4eb:
		return EPP_STR(sh4eb);
	case sparc:
		return EPP_STR(sparc);
	case sparc64:
		return EPP_STR(sparc64);
	case tricore:
		return EPP_STR(tricore);
	case x86_64:
		return EPP_STR(x86_64);
	case xtensa:
		return EPP_STR(xtensa);
	case xtensaeb:
		return EPP_STR(xtensaeb);
	default:
		throw new Exception("Careless forced transformation");
	}
}

void OS::PrintInfo() {
	Printf("OS:");
}

void OS::Printf(const c8 *fmt, ...) {
	::va_list args;
	::va_start(args,fmt);
	::vprintf(fmt, args);
	::va_end(args);

	::fflush(stdout);
}

void OS::PrintMemory(u8 *address, i32 len) {
	(void) address;
	(void) len;
}

OS::OS() {

}

}
}
