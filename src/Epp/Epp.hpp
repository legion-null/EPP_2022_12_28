#pragma once

#include "defs.h"

namespace Epp {

template<typename T>
inline bool EnsureExists(T *ptr) {
	if (ptr == nullptr) {
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

inline void iSwap(byte *a, byte *b, i32 elSize) {
	for (i32 i = 0; i < elSize; i++) {
		Swap(a[i], b[i]);
	}
}

void Swap(byte *a, byte *b, i32 elSize);

inline void iCopy(const byte *src, byte *dest, i32 elSize, i32 elNum) {
	for (i32 i = 0; i < elSize * elNum; i++) {
		*dest = *src;
		src++;
		dest++;
	}
}

inline void iSafeCopy(const byte *src, byte *&dest, i32 elSize, i32 elNum) {
	if (dest == nullptr)
		SafeNew(dest, elSize * elNum);
	return iCopy(src, dest, elSize, elNum);
}

void Copy(const byte *src, byte *dest, i32 elSize, i32 elNum);

void SafeCopy(const byte *src, byte *&dest, i32 elSize, i32 elNum);

template<typename T>
inline void Copy(const T *src, T *dest, i32 elNum) {
	Copy(reinterpret_cast<const byte*>(src), reinterpret_cast<byte*>(dest), sizeof(T), elNum);
}

template<typename T>
inline void Copy(const T *src, T *dest) {
	Copy(src, dest, 1);
}

template<typename T>
inline void SafeCopy(const T *src, T *&dest, i32 elNum) {
	SafeCopy(reinterpret_cast<const byte*>(src), reinterpret_cast<byte*&>(dest), sizeof(T), elNum);
}

template<typename T>
inline void SafeCopy(const T *src, T *&dest) {
	SafeCopy(src, dest, 1);
}

inline void iMove(const byte *src, byte *dest, i32 elSize, i32 elNum) {
	iCopy(src, dest, elSize, elNum);
	delete[] src;
}

inline void iSafeMove(const byte *src, byte *&dest, i32 elSize, i32 elNum) {
	iSafeCopy(src, dest, elSize, elNum);
	SafeDelete(src);
}

void Move(const byte *src, byte *dest, i32 elSize, i32 elNum);

void SafeMove(const byte *src, byte *&dest, i32 elSize, i32 elNum);

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
	SafeMove(reinterpret_cast<const byte*>(src), reinterpret_cast<byte*&>(dest), sizeof(T), elNum);
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
inline byte GetByte(T &value, i32 i) {
	return (reinterpret_cast<byte*>(&value))[i];
}

template<typename T>
inline void SetByte(T &value, i32 i, byte b) {
	(reinterpret_cast<byte*>(&value))[i] = b;
}

}
