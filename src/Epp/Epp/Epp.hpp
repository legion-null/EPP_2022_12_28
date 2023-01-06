#pragma once

#include "defs.h"

namespace Epp {
void __Debug(const c8 *fmt, ...);

template<typename T>
inline bool EnsureExists(T *ptr) {
	if (ptr == nullptr) {
		throw 0;
		return false;
	}
	return true;
}

void* SafeMalloc(u64 size);
void SafeFree(void *ptr);

template<typename T>
inline bool Delete(T *ptr, bool freeOnly = false) {
	if (ptr == nullptr) {
		return false;
	}

	if (freeOnly == false) {
		delete[] ptr;
	} else {
		SafeFree((void*) ptr);
	}

	return true;
}

template<typename T>
inline bool SafeDelete(T *&ptr, bool freeOnly = false) {
	bool ret = Delete(ptr, freeOnly);
	//ptr = nullptr;

	return ret;
}

template<typename T>
inline bool SafeNew(T *&ptr, bool mallocOnly = false) {
	bool constructed = SafeDelete(ptr);

	if (mallocOnly == false) {
		ptr = new T;
	} else {
		ptr = SafeMalloc(sizeof(T));
	}

	return constructed;
}

template<typename T>
inline bool SafeNew(T *&ptr, u64 len, bool mallocOnly = false) {
	bool constructed = SafeDelete(ptr);
	if (mallocOnly == false) {
		ptr = new T[len];
	} else {
		ptr = (T*) SafeMalloc(sizeof(T) * len);
	}
	return constructed;
}

template<typename T>
inline void Swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

inline void iSwap(u8 *a, u8 *b, u64 elSize) {
	for (u64 i = 0; i < elSize; i++) {
		Swap(a[i], b[i]);
	}
}

void Swap(u8 *a, u8 *b, u64 elSize);

template<typename T>
T GetMemory(void *mem) {
	return *((T*) mem);
}

template<typename T>
void SetMemory(T *mem, T value, u64 elNum) {
	for (; elNum > 0; elNum--) {
		*mem = value;
		mem++;
	}
}

inline void iSetMemory(u8 *mem, u8 *value, u64 elSize, u64 elNum) {
	for (; elNum > 0; elNum--) {
		for (u64 i = 0; i < elSize; i++) {
			*mem = value[i];
			mem++;
		}
	}
}

void SetMemory(u8 *mem, u8 *value, u64 elSize, u64 elNum);

inline void iCopy(const u8 *src, u8 *dest, u64 elSize, u64 elNum) {
	for (u64 i = 0; i < (u64) (elSize * elNum); i++) {
		*dest = *src;
		src++;
		dest++;
	}
}

inline void iSafeCopy(const u8 *src, u8 *&dest, u64 elSize, u64 elNum) {
	if (dest == nullptr)
		SafeNew(dest, elSize * elNum);
	return iCopy(src, dest, elSize, elNum);
}

void Copy(const u8 *src, u8 *dest, u64 elSize, u64 elNum);

void SafeCopy(const u8 *src, u8 *&dest, u64 elSize, u64 elNum);

template<typename T>
inline void Copy(const T *src, T *dest, u64 elNum) {
	Copy((const u8*) (src), (u8*) (dest), sizeof(T), elNum);
}

template<typename T>
inline void Copy(const T *src, T *dest) {
	Copy(src, dest, 1);
}

template<typename T>
inline void SafeCopy(const T *src, T *&dest, u64 elNum) {
	SafeCopy((const u8*) (src), (u8*&) (dest), sizeof(T), elNum);
}

template<typename T>
inline void SafeCopy(const T *src, T *&dest) {
	SafeCopy(src, dest, 1);
}

inline void iMove(const u8 *src, u8 *dest, u64 elSize, u64 elNum) {
	iCopy(src, dest, elSize, elNum);
	delete[] src;
}

inline void iSafeMove(const u8 *src, u8 *&dest, u64 elSize, u64 elNum) {
	iSafeCopy(src, dest, elSize, elNum);
	SafeDelete(src);
}

void Move(const u8 *src, u8 *dest, u64 elSize, u64 elNum);

void SafeMove(const u8 *src, u8 *&dest, u64 elSize, u64 elNum);

template<typename T>
inline void Move(const T *src, T *dest, u64 elNum) {
	Move(src, dest, sizeof(T), elNum);
}

template<typename T>
inline void Move(const T *src, T *dest) {
	Move(src, dest, 1);
}

template<typename T>
inline void SafeMove(const T *src, T *&dest, u64 elNum) {
	SafeMove((const u8*) (src), (u8*&) (dest), sizeof(T), elNum);
}

template<typename T>
inline void SafeMove(const T *src, T *&dest) {
	SafeMove(src, dest, 1);
}

template<typename T>
inline bool GetBit(T &value, u64 i) {
	return ((value >> i) & 0x01) == 1 ? true : false;
}

template<typename T>
inline void SetBit(T &value, u64 i) {
	value |= (0x01 << i);
}

template<typename T>
inline void ResetBit(T &value, u64 i) {
	value &= (~(0x01 << i));
}

template<typename T>
inline void ReverseBit(T &value, u64 i) {
	value ^= (0x01 << i);
}

template<typename T>
inline u8 GetByte(T &value, u64 i) {
	return ((u8*) (&value))[i];
}

template<typename T>
inline void SetByte(T &value, u64 i, u8 b) {
	((u8*) (&value))[i] = b;
}

template<bool, typename T = void>
struct EnableType {
};

template<typename T>
struct EnableType<true, T> {
	using type = T;
};

}
