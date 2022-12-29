#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace base {

E_CLASS_DEF(Epp::base::String)

void String::Static() { // 静态块，类初始化时将会执行块内代码，为了防止Epp类型构建系统出错，静态块内的代码必须与类型加载顺序无关

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

EString String::ValueOf(bool data) {
	return new String(data ? "true" : "false");
}

EString String::ValueOf(c8 data) {
	c8 str[2] = { data, 0 };
	return new String(str);
}

EString String::ValueOf(c8 data[]) {
	return ValueOf(data, 0, strlen(data));
}

EString String::ValueOf(c8 data[], i32 off, i32 len) {
	return new String("");
}

EString String::ValueOf(c32 data) {
	return new String("Char.ToString(data)");
}

EString String::ValueOf(i32 data) {
	return new String("Integer.ToString(data)");
}

EString String::ValueOf(i64 data) {
	return new String("Integer.ToString(data)");
}

EString String::ValueOf(f32 data) {
	return new String("Float.ToString(data)");
}

EString String::ValueOf(f64 data) {
	return new String("Float.ToString(data)");
}

EString String::ValueOf(EObject data) {
	return data->toString();
}

String::String() {

}

void String::destroy() {
	SafeDelete(this->value);
}

String::String(const c8 *str) :
		This(str, 0, strlen(str)) {

}

String::String(const c8 *str, i32 off, i32 len) {
	SafeCopy(str + off, this->value, len);
}

const c8* String::getValue() {
	return this->value;
}

i32 String::getLength() {
	return strlen(this->value);
}

EString String::clone() {
	return new String(this->value);
}

bool String::equalTo(EObject other) {
	Base::equalTo(other);
	return true;
}

EString String::toString() {
	return this;
}

}
}
