#pragma once

#include "base/Object/Object.h"

E_init

namespace Epp {
namespace base {

class String: extends Object {

E_CLASS_DEC(String, Object)

public:
	static const void* memchr(const void *str, i32 c, i32 n);
	static bool memcmp(const void *str1, const void *str2, i32 n);
	static void* memcpy(void *dest, const void *src, i32 n);
	static void* memmove(void *dest, const void *src, i32 n);
	static void* memset(void *str, i32 c, i32 n);
	static c8* strcat(c8 *dest, const c8 *src);
	static c8* strncat(c8 *dest, const c8 *src, i32 n);
	static const c8* strchr(const c8 *str, i32 c);
	static bool strcmp(const c8 *str1, const c8 *str2);
	static bool strncmp(const c8 *str1, const c8 *str2, i32 n);
	static c8* strcpy(c8 *dest, const c8 *src);
	static c8* strncpy(c8 *dest, const c8 *src, i32 n);
	static i32 strcspn(const c8 *str1, const c8 *str2);
	static i32 strlen(const c8 *str);
	static const c8* strpbrk(const c8 *str1, const c8 *str2);
	static const c8* strrchr(const c8 *str, i32 c);
	static i32 strspn(const c8 *str1, const c8 *str2);
	static const c8* strstr(const c8 *haystack, const c8 *needle);
	static c8* strtok(c8 *str, const c8 *delim);

public:
	static i32 CalculateHash(const c8 *str);

public:
	static EString ValueOf(bool data);
	static EString ValueOf(c8 data);
	static EString ValueOf(c8 data[]);
	static EString ValueOf(c8 data[], i32 off, i32 len);
	static EString ValueOf(c32 data);
	static EString ValueOf(i32 data);
	static EString ValueOf(i64 data);
	static EString ValueOf(f32 data);
	static EString ValueOf(f64 data);
	static EString ValueOf(EObject data);

protected:
	c8 *value = nullptr;
	i32 length = 0;

public:
	String();
	virtual void destroy() override;

public:
	String(const c8 *str);
	String(const c8 *str, i32 off, i32 len);

public:
	const c8* getValue();
	i32 getLength();

public:
	virtual EString clone() override;

public:
	virtual bool equalTo(EObject other) override;

public:
	virtual EString toString() override;

};

E_class(String)

inline EString S(const c8 *str) {
	return new String(str);
}

}
}

