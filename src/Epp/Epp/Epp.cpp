#include "Epp.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>

using namespace Epp;

#if EPP_CURRENT_OS == EPP_OS_ANDROID
#include <android/log.h>
#endif

namespace Epp {
void* origin(uSize size);
void finality(void *ptr);
}

void* operator new(size_t size) {
	// 覆盖operator new函数
	return Epp::origin(size);
}

void operator delete(void *ptr) {
	// 覆盖operator delete函数
	return Epp::finality(ptr);

}

namespace Epp {

void __Debug(const c8 *fmt, ...) {
	va_list (args);
	va_start(args, fmt);
#if EPP_CURRENT_OS == EPP_OS_ANDROID
	__android_log_vprint(3, "EPP", fmt, args);
#else
	::vprintf(fmt, args);
#endif
	va_end(args);
}

void* origin(uSize size) {
	void *ptr = ::malloc(size); // ::calloc(1,size)
//EPP_DEBUG("EPP operator new 0x%016x\n", ptr);
	return ptr;
}

void finality(void *ptr) {
//EPP_DEBUG("EPP operator delete 0x%016x\n", ptr);
	::free(ptr);
}

void Swap(byte *a, byte *b, i32 elSize) {
	return iSwap(a, b, elSize);
}

void SetMemory(byte *mem, byte *value, i32 elSize, i32 elNum) {
	return iSetMemory(mem, value, elSize, elNum);
}

void Copy(const byte *src, byte *dest, i32 elSize, i32 elNum) {
	return iCopy(src, dest, elSize, elNum);
}

void SafeCopy(const byte *src, byte *&dest, i32 elSize, i32 elNum) {
	return iSafeCopy(src, dest, elSize, elNum);
}

void Move(const byte *src, byte *dest, i32 elSize, i32 elNum) {
	return iMove(src, dest, elSize, elNum);
}

void SafeMove(const byte *src, byte *&dest, i32 elSize, i32 elNum) {
	return iSafeMove(src, dest, elSize, elNum);
}

}

