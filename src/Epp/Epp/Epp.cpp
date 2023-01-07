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
	va_list args;
	va_start(args, fmt);
#if EPP_CURRENT_OS == EPP_OS_ANDROID
	__android_log_vprint(3, "EPP", fmt, args);
#else
	::vprintf(fmt, args);
#endif
	va_end(args);
}

void* Malloc(u64 size){
	// 记录指针到堆区指针分配表
	return ::malloc(size);
}

void Free(void * ptr){
	// 从堆区指针分配表删除指针
	::free(ptr);
}

void* origin(uSize size) {
	void *ptr = Malloc(size); // ::calloc(1,size)
	//EPP_DEBUG("EPP operator new 0x%016x\n", ptr);
	return ptr;
}

void finality(void *ptr) {
	//EPP_DEBUG("EPP operator delete 0x%016x\n", ptr);
	Free(ptr);
}

void Swap(u8 *a, u8 *b, u64 elSize) {
	return iSwap(a, b, elSize);
}

void SetMemory(u8 *mem, u8 *value, u64 elSize, u64 elNum) {
	return iSetMemory(mem, value, elSize, elNum);
}

void Copy(const u8 *src, u8 *dest, u64 elSize, u64 elNum) {
	return iCopy(src, dest, elSize, elNum);
}

void SafeCopy(const u8 *src, u8 *&dest, u64 elSize, u64 elNum) {
	return iSafeCopy(src, dest, elSize, elNum);
}

void Move(const u8 *src, u8 *dest, u64 elSize, u64 elNum) {
	return iMove(src, dest, elSize, elNum);
}

void SafeMove(const u8 *src, u8 *&dest, u64 elSize, u64 elNum) {
	return iSafeMove(src, dest, elSize, elNum);
}

}

