#pragma once

#include "base/Object/Object.h"

namespace Epp {
namespace base {



class OS: public Epp::base::Object {

EPP_CLASS_INFO

public: // 系统常量表，这些值在编译时就已经确定
	// 大小端相关
#if EPP_ENDIAN_LITTLE == EPP_TRUE
	static constexpr i32 Endian = 1;
#endif

#if EPP_ENDIAN_BIG == EPP_TRUE
	static constexpr i32 Endian = 0;
#endif

	// 用于方便大小端代码编程，其值在编译时就已经确定
	static constexpr i32 BigEndian = (Endian == 0) ? 1 : 0;
	static constexpr i32 LittleEndian = (Endian == 1) ? 1 : 0;

	// CPU架构相关

	// 系统相关
	enum OS_t : i8 {
		Linux = 0, MacOS, Windows, Android, IOS,
	};

	static const c8* GetEnumName(OS_t e);

#ifdef EPP_TARGET_OS_LINUX
	static constexpr OS_t CurrentOS = Linux;
#endif

#ifdef EPP_TARGET_OS_MACOS
	static constexpr OS_t CurrentOS = MacOS;
#endif

#ifdef EPP_TARGET_OS_WINDOWS
	static constexpr OS_t CurrentOS = Windows;
#endif

#ifdef EPP_TARGET_OS_ANDROID
	static constexpr OS_t CurrentOS = Android;
#endif

#ifdef EPP_TARGET_OS_IOS
	static constexpr OS_t CurrentOS = IOS;
#endif

	// 架构相关
	enum arch_t : i8 {
		aarch64 = 0,
		alpha,
		arm,
		avr,
		cris,
		hppa,
		i386,
		loongarch64,
		m68k,
		microblaze,
		microblazeel,
		mips,
		mips64,
		mips64el,
		mipsel,
		nios2,
		or1k,
		ppc,
		ppc64,
		riscv32,
		riscv64,
		rx,
		s390x,
		sh4,
		sh4eb,
		sparc,
		sparc64,
		tricore,
		x86_64,
		xtensa,
		xtensaeb,
	};

	static const c8* GetEnumName(arch_t e);

#ifdef EPP_TARGET_ARCH_AARCH64
	static constexpr arch_t CurrentArch = aarch64;
#endif

#ifdef EPP_TARGET_ARCH_ALPHA
	static constexpr arch_t CurrentArch = alpha;
#endif

#ifdef EPP_TARGET_ARCH_ARM
	static constexpr arch_t CurrentArch = arm;
#endif

#ifdef EPP_TARGET_ARCH_AVR
	static constexpr arch_t CurrentArch = avr;
#endif

#ifdef EPP_TARGET_ARCH_CRIS
	static constexpr arch_t CurrentArch = cris;
#endif

#ifdef EPP_TARGET_ARCH_HPPA
	static constexpr arch_t CurrentArch = hppa;
#endif

#ifdef EPP_TARGET_ARCH_I386
	static constexpr arch_t CurrentArch = i386;
#endif

#ifdef EPP_TARGET_ARCH_LOONGARCH64
	static constexpr arch_t CurrentArch = loongarch64;
#endif

#ifdef EPP_TARGET_ARCH_M68K
	static constexpr arch_t CurrentArch = m68k;
#endif

#ifdef EPP_TARGET_ARCH_MICROBLAZE
	static constexpr arch_t CurrentArch = microblaze;
#endif

#ifdef EPP_TARGET_ARCH_MICROBLAZEEL
	static constexpr arch_t CurrentArch = microblazeel;
#endif

#ifdef EPP_TARGET_ARCH_MIPS
	static constexpr arch_t CurrentArch = mips;
#endif

#ifdef EPP_TARGET_ARCH_MIPS64
	static constexpr arch_t CurrentArch = mips64;
#endif

#ifdef EPP_TARGET_ARCH_MIPS64EL
	static constexpr arch_t CurrentArch = mips64el;
#endif

#ifdef EPP_TARGET_ARCH_MIPSEL
	static constexpr arch_t CurrentArch = mipsel;
#endif

#ifdef EPP_TARGET_ARCH_NIOS2
	static constexpr arch_t CurrentArch = nios2;
#endif

#ifdef EPP_TARGET_ARCH_OR1K
	static constexpr arch_t CurrentArch = or1k;
#endif

#ifdef EPP_TARGET_ARCH_PPC
	static constexpr arch_t CurrentArch = ppc;
#endif

#ifdef EPP_TARGET_ARCH_PPC64
	static constexpr arch_t CurrentArch = ppc64;
#endif

#ifdef EPP_TARGET_ARCH_RISCV32
	static constexpr arch_t CurrentArch = riscv32;
#endif

#ifdef EPP_TARGET_ARCH_RISCV64
	static constexpr arch_t CurrentArch = riscv64;
#endif

#ifdef EPP_TARGET_ARCH_RX
	static constexpr arch_t CurrentArch = rx;
#endif

#ifdef EPP_TARGET_ARCH_S390X
	static constexpr arch_t CurrentArch = s390x;
#endif

#ifdef EPP_TARGET_ARCH_SH4
	static constexpr arch_t CurrentArch = sh4;
#endif

#ifdef EPP_TARGET_ARCH_SH4EB
	static constexpr arch_t CurrentArch = sh4eb;
#endif

#ifdef EPP_TARGET_ARCH_SPARC
	static constexpr arch_t CurrentArch = sparc;
#endif

#ifdef EPP_TARGET_ARCH_SPARC64
	static constexpr arch_t CurrentArch = sparc64;
#endif

#ifdef EPP_TARGET_ARCH_TRICORE
	static constexpr arch_t CurrentArch = tricore;
#endif

#ifdef EPP_TARGET_ARCH_X86_64
	static constexpr arch_t CurrentArch = x86_64;
#endif

#ifdef EPP_TARGET_ARCH_XTENSA
	static constexpr arch_t CurrentArch = xtensa;
#endif

#ifdef EPP_TARGET_ARCH_XTENSAEB
	static constexpr arch_t CurrentArch = xtensaeb;
#endif

	// 外部模块支持
	static constexpr bool ModuleSupport_SDL2 = (EPP_MODULE_SDL2_SUPPORT == EPP_TRUE);
	static constexpr bool ModuleSupport_X11 = (EPP_MODULE_X11_SUPPORT == EPP_TRUE);
	static constexpr bool ModuleSupport_LinuxFB = (EPP_MODULE_LINUXFB_SUPPORT == EPP_TRUE);
	static constexpr bool ModuleSupport_OpenGL = (EPP_MODULE_OPENGL_SUPPORT == EPP_TRUE);

public:
	static void PrintInfo();

public:
	static bool IsLittleEndian();

public:
	static void Printf(const c8 *fmt, ...);
	static void PrintMemory(u8 *address, i32 len);

public:
	OS();
};

}
}

