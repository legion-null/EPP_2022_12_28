#pragma once

#include "base/Object/Object.h"

#include "base/Char/Char.h"

namespace Epp {
namespace base {

class String: public Epp::base::Object {

EPP_CLASS_INFO

public:
	static const c8* ToUTF32(const c8 *str, Char::Type src);
	static const c8* FromUTF32(const c8 *str, Char::Type dest);

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
	static String* ValueOf(bool data);
	static String* ValueOf(c8 data);
	static String* ValueOf(c8 data[]);
	static String* ValueOf(c8 data[], i32 off, i32 len);
	static String* ValueOf(c32 data);
	static String* ValueOf(i32 data);
	static String* ValueOf(i64 data);
	static String* ValueOf(f32 data);
	static String* ValueOf(f64 data);
	static String* ValueOf(Object *data);

protected:
	c8 *value = nullptr;
	i32 length = 0;

public:
	String();

public:
	String(const c8 *str);
	String(const c8 *str, i32 off, i32 len);

public:
	const c8* getValue();
	i32 getLength();

public:
	virtual String* clone() override;

public:
	virtual bool equalTo(const Object &other) override;

public:
	virtual String* toString() override;

};

inline String* S(const c8 *str) {
	return new String(str);
}

}
}

