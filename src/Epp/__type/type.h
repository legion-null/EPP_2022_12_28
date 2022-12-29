#pragma once

// 类型长度规范化代码，更换编译平台可能需要修改

// 整数类型
#define d8		char
#define d16		short
#define d32		int
#define d64		long int

// 有符号整数类型
typedef signed d8 i8;
typedef signed d16 i16;
typedef signed d32 i32;
typedef signed d64 i64;

// 无符号整数类型
typedef unsigned d8 u8;
typedef unsigned d16 u16;
typedef unsigned d32 u32;
typedef unsigned d64 u64;

// CPU架构相关类型 长度和指针类型长度相等的整数类型
//typedef i64 iSize;
//typedef u64 uSize;

// 浮点数类型
typedef float f32;
typedef double f64;
typedef long double f128;

// 字符类型
typedef char c8;
typedef char16_t c16;
typedef char32_t c32;

typedef u8 byte;

// 类型测试
inline bool type_check() {
	if (sizeof(d8) != 1)
		return false;
	if (sizeof(d16) != 2)
		return false;
	if (sizeof(d32) != 4)
		return false;
	if (sizeof(d64) != 8)
		return false;

	if (sizeof(f32) != 4)
		return false;
	if (sizeof(f64) != 8)
		return false;
	if (sizeof(f128) != 16)
		return false;

	if (sizeof(c8) != 1)
		return false;
	if (sizeof(c16) != 2)
		return false;
	if (sizeof(c32) != 4)
		return false;
/*
	if (sizeof(void*) != sizeof(iSize))
		return false;
	if (sizeof(void*) != sizeof(uSize))
		return false;
*/
	return true;
}

// CPU大小端测试
inline bool check_little_endian() {
	union w {
		i32 a;
		c8 b;
	} c;
	c.a = 1;

	return c.b == 1 ? true : false;
}
