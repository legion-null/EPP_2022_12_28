#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

#include <string.h>

namespace Epp {
namespace base {

const Class *String::ClassInfo = Class::Register<String, Object>("Epp::base::String", nullptr);

const c8* String::ToUTF32(const c8 *str, Char::Type src) {
	(void) str;
	(void) src;

	return nullptr;
}

const c8* String::FromUTF32(const c8 *str, Char::Type dest) {
	(void) str;
	(void) dest;

	return nullptr;
}

const void* String::memchr(const void *str, i32 c, i32 n) {
	return ::memchr(str, c, n);
}

bool String::memcmp(const void *str1, const void *str2, i32 n) {
	return ::memcmp(str1, str2, n) == 0;
}

void* String::memcpy(void *dest, const void *src, i32 n) {
	return ::memcpy(dest, src, n);
}

void* String::memmove(void *dest, const void *src, i32 n) {
	return ::memmove(dest, src, n);
}

void* String::memset(void *str, i32 c, i32 n) {
	return ::memset(str, c, n);
}

c8* String::strcat(c8 *dest, const c8 *src) {
	return ::strcat(dest, src);
}

c8* String::strncat(c8 *dest, const c8 *src, i32 n) {
	return ::strncat(dest, src, n);
}

const c8* String::strchr(const c8 *str, i32 c) {
	return ::strchr(str, c);
}

bool String::strcmp(const c8 *str1, const c8 *str2) {
	return ::strcmp(str1, str2) == 0;
}

bool String::strncmp(const c8 *str1, const c8 *str2, i32 n) {
	return ::strncmp(str1, str2, n) == 0;
}

c8* String::strcpy(c8 *dest, const c8 *src) {
	return ::strcpy(dest, src);
}

c8* String::strncpy(c8 *dest, const c8 *src, i32 n) {
	return ::strncpy(dest, src, n);
}

i32 String::strcspn(const c8 *str1, const c8 *str2) {
	return ::strcspn(str1, str2);
}

i32 String::strlen(const c8 *str) {
	return ::strlen(str);
}

const c8* String::strpbrk(const c8 *str1, const c8 *str2) {
	return ::strpbrk(str1, str2);
}

const c8* String::strrchr(const c8 *str, i32 c) {
	return ::strchr(str, c);
}

i32 String::strspn(const c8 *str1, const c8 *str2) {
	return ::strspn(str1, str2);
}

const c8* String::strstr(const c8 *haystack, const c8 *needle) {
	return ::strstr(haystack, needle);
}

c8* String::strtok(c8 *str, const c8 *delim) {
	return ::strtok(str, delim);
}

i32 String::CalculateHash(const c8 *str) {
	i32 hash = 0;
	for (i32 i = 0; str[i] != 0; i++) {
		hash = 31 * hash + (str[i] & 0xff);
	}
	return hash;
}

String* String::ValueOf(bool data) {
	return new String(data ? "true" : "false");
}

String* String::ValueOf(c8 data) {
	c8 str[2] = { data, 0 };
	return new String(str);
}

String* String::ValueOf(c8 data[]) {
	return ValueOf(data, 0, strlen(data));
}

String* String::ValueOf(c8 data[], i32 off, i32 len) {
	return new String(data, off, len);
}

String* String::ValueOf(c32 data) {
	(void) data;
	return new String("Char.ToString(data)");
}

String* String::ValueOf(i32 data) {
	(void) data;
	return new String("Integer.ToString(data)");
}

String* String::ValueOf(i64 data) {
	(void) data;
	return new String("Integer.ToString(data)");
}

String* String::ValueOf(f32 data) {
	(void) data;
	return new String("Float.ToString(data)");
}

String* String::ValueOf(f64 data) {
	(void) data;
	return new String("Float.ToString(data)");
}

String* String::ValueOf(Object *data) {
	return data->toString();
}

String::String() {

}

String::String(const c8 *str) :
		String(str, 0, strlen(str)) {

}

String::String(const c8 *str, i32 off, i32 len) {
	SafeCopy(str + off, this->value, len + 1);

	/*
	 if (strlen(str + off) < len) {
	 throw new Exception("NullPointerException");
	 } else {
	 this->value = str + off;
	 this->length = len;
	 }
	 */
}

const c8* String::getValue() {
	return this->value;
}

i32 String::getLength() {
	return strlen(this->value);
}

String* String::clone() {
	return new String(this->value);
}

bool String::equalTo(const Object &other) {
	Object::equalTo(other);
	return true;
}

String* String::toString() {
	return this;
}



}
}
