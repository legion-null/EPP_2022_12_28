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

template<typename T>
inline bool SafeDelete(T *&ptr) {
	if (ptr == nullptr)
		return false;

	delete[] ptr;
	return true;
}

template<typename T>
inline bool SafeNew(T *&ptr) {
	bool constructed = SafeDelete(ptr);
	ptr = new T;
	return constructed;
}

template<typename T>
inline bool SafeNew(T *&ptr, i32 len) {
	bool constructed = SafeDelete(ptr);
	ptr = new T[len];
	return constructed;
}

template<typename T>
inline void Swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

inline void iSwap(u8 *a, u8 *b, i32 elSize) {
	for (i32 i = 0; i < elSize; i++) {
		Swap(a[i], b[i]);
	}
}

void Swap(u8 *a, u8 *b, i32 elSize);

template<typename T>
T GetMemory(void *mem) {
	return *((T*) mem);
}

template<typename T>
void SetMemory(T *mem, T value, i32 elNum) {
	for (; elNum > 0; elNum--) {
		*mem = value;
		mem++;
	}
}

inline void iSetMemory(u8 *mem, u8 *value, i32 elSize, i32 elNum) {
	for (; elNum > 0; elNum--) {
		for (i32 i = 0; i < elSize; i++) {
			*mem = value[i];
			mem++;
		}
	}
}

void SetMemory(u8 *mem, u8 *value, i32 elSize, i32 elNum);

inline void iCopy(const u8 *src, u8 *dest, i32 elSize, i32 elNum) {
	for (u64 i = 0; i < (u64) (elSize * elNum); i++) {
		*dest = *src;
		src++;
		dest++;
	}
}

inline void iSafeCopy(const u8 *src, u8 *&dest, i32 elSize, i32 elNum) {
	if (dest == nullptr)
		SafeNew(dest, elSize * elNum);
	return iCopy(src, dest, elSize, elNum);
}

void Copy(const u8 *src, u8 *dest, i32 elSize, i32 elNum);

void SafeCopy(const u8 *src, u8 *&dest, i32 elSize, i32 elNum);

template<typename T>
inline void Copy(const T *src, T *dest, i32 elNum) {
	Copy((const u8*) (src), (u8*) (dest), sizeof(T), elNum);
}

template<typename T>
inline void Copy(const T *src, T *dest) {
	Copy(src, dest, 1);
}

template<typename T>
inline void SafeCopy(const T *src, T *&dest, i32 elNum) {
	SafeCopy((const u8*) (src), (u8*&) (dest), sizeof(T), elNum);
}

template<typename T>
inline void SafeCopy(const T *src, T *&dest) {
	SafeCopy(src, dest, 1);
}

inline void iMove(const u8 *src, u8 *dest, i32 elSize, i32 elNum) {
	iCopy(src, dest, elSize, elNum);
	delete[] src;
}

inline void iSafeMove(const u8 *src, u8 *&dest, i32 elSize, i32 elNum) {
	iSafeCopy(src, dest, elSize, elNum);
	SafeDelete(src);
}

void Move(const u8 *src, u8 *dest, i32 elSize, i32 elNum);

void SafeMove(const u8 *src, u8 *&dest, i32 elSize, i32 elNum);

template<typename T>
inline void Move(const T *src, T *dest, i32 elNum) {
	Move(src, dest, sizeof(T), elNum);
}

template<typename T>
inline void Move(const T *src, T *dest) {
	Move(src, dest, 1);
}

template<typename T>
inline void SafeMove(const T *src, T *&dest, i32 elNum) {
	SafeMove((const u8*) (src), (u8*&) (dest), sizeof(T), elNum);
}

template<typename T>
inline void SafeMove(const T *src, T *&dest) {
	SafeMove(src, dest, 1);
}

template<typename T>
inline bool GetBit(T &value, i32 i) {
	return ((value >> i) & 0x01) == 1 ? true : false;
}

template<typename T>
inline void SetBit(T &value, i32 i) {
	value |= (0x01 << i);
}

template<typename T>
inline void ResetBit(T &value, i32 i) {
	value &= (~(0x01 << i));
}

template<typename T>
inline void ReverseBit(T &value, i32 i) {
	value ^= (0x01 << i);
}

template<typename T>
inline u8 GetByte(T &value, i32 i) {
	return ((u8*) (&value))[i];
}

template<typename T>
inline void SetByte(T &value, i32 i, u8 b) {
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
