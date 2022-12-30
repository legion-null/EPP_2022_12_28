#include "Epp.h"

using namespace Epp;

namespace Epp {

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
