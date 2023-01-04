#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

#include <ctype.h>

namespace Epp {
namespace base {

const Class *Char::ClassInfo = Class::Register<Char, Object>("Epp::base::Char", nullptr);

const u8 Char::ASCII_PaddingMask = 0b111110;
const u8 Char::GBK_PaddingMask = 0b111100;
const u8 Char::UTF8_PaddingMask[6] = { 0b011111, 0b001111, 0b000111, 0b000011, 0b000001, 0b000000, };
const u8 Char::UTF32_PaddingMask = 0b110000;

bool Char::IsLower(c32 c) {
	return ::islower(c);
}

bool Char::IsUpper(c32 c) {
	return ::isupper(c);
}

bool Char::IsAlpha(c32 c) {
	return ::isalpha(c);
}

bool Char::IsDigit(c32 c) {
	return ::isdigit(c);
}

bool Char::IsAlNum(c32 c) {
	return ::isalnum(c);
}

bool Char::IsCntrl(c32 c) {
	return ::iscntrl(c);
}

bool Char::IsGraph(c32 c) {
	return ::isgraph(c);
}

bool Char::IsPrint(c32 c) {
	return ::isprint(c);
}

bool Char::IsPunct(c32 c) {
	return ::ispunct(c);
}

bool Char::IsSpace(c32 c) {
	return ::isspace(c);
}

bool Char::IsXdigit(c32 c) {
	return ::isxdigit(c);
}

c32 Char::ToLower(c32 c) {
	return ::tolower(c);
}

c32 Char::ToUpper(c32 c) {
	return ::toupper(c);
}

bool Char::IsCJKCharacter(c32 c) {
	if (c >= 0x3000 and c <= 0x9fff)
		return true;
	return false;
}

bool Char::IsBaseChineseCharacter(c32 c) {
	if (c >= 0x4e00 or c <= 0x9fa5)
		return true;
	return false;
}

bool Char::IsChineseLowerDight(c32 c) {
	static const c32 chineseLowerDigit[10] = { 0 };
	/*static const c32 chineseLowerDigit[] = { '〇', '一', '二', '三', '四', '五', '六', '七', '八', '九', //
	 '个', '十', '百', '千', '万', '亿' };*/
	for (i32 i = 0; i < 10; i++)
		if (c == chineseLowerDigit[i])
			return true;
	return false;
}

bool Char::IsChineseUpperDight(c32 c) {
	static const c32 chineseUpperDigit[10] = { 0 };
	/*static const c32 chineseUpperDigit[] = { '零', '壹', '贰', '叁', '肆', '伍', '陆', '柒', '捌', '玖', //
	 '个', '拾', '佰', '仟', '萬', '亿' };*/

	for (i32 i = 0; i < 10; i++)
		if (c == chineseUpperDigit[i])
			return true;
	return false;
}

bool Char::IsChineseDight(c32 c) {
	return IsChineseLowerDight(c) or IsChineseUpperDight(c);
}

c32 Char::ToChineseLowerDigit(c32 c) {
	if (IsChineseUpperDight(c)) {

	}
	return c;
}

c32 Char::ToChineseUpperDigit(c32 c) {
	if (IsChineseLowerDight(c)) {

	}
	return c;
}

Char::Char() {

}

Char::~Char() {

}

Char::Char(const c8 c) {
	this->value.ascii.c = c;
	clearCharValueBytes(ASCII_PaddingMask);
}

Char::Char(const c16 c) {
	struct GBK &gbk = this->value.gbk;
	gbk.c = c;
	clearCharValueBytes(GBK_PaddingMask);

	if (gbk.c < 0x8140 or gbk.c > 0xfefe) {
		throw Exception("Warning: The memory allocation has been completed, "
				"but the parameter does not conform to the GBK encoding rules!\n");
	}
}

Char::Char(const c8 *c) {
	// 内存复制
	this->value.utf8 = *((struct UTF8*) c);

	i32 length = getUTF8Length();

	if (length == 0) {
		throw Exception("Warning: The memory allocation has been completed, "
				"but the parameter does not conform to the UTF8 encoding rules!\n");
	} else {
		clearCharValueBytes(UTF8_PaddingMask[length - 1]);
	}
}

Char::Char(const c32 c) {
	struct UTF32 &utf32 = this->value.utf32;
	utf32.c = c;
	clearCharValueBytes(UTF32_PaddingMask);
}

void Char::clearCharValueBytes(u8 bytes) {
	for (i32 i = 0; i < (i32) sizeof(union CharValue); i++) {
		if (GetBit(bytes, i) == true)
			SetByte(this->value, i, 0x00);
	}
}

bool Char::checkCharValueBytes(u8 bytes) const {
	for (i32 i = 0; i < (i32) sizeof(union CharValue); i++) {
		if (GetBit(bytes, i) == true)
			if (GetByte(this->value, i) != 0x00)
				return false;
	}
	return true;
}

c8 Char::getASCII() const {
	return this->value.ascii.c;
}

c16 Char::getGBK() const {
	const struct GBK &gbk = this->value.gbk;
	return gbk.c;
}

const c8* Char::getUTF8() const {
	const struct UTF8 &utf8 = this->value.utf8;
	return utf8.c;
}

c32 Char::getUTF32() const {
	const struct UTF32 &utf32 = this->value.utf32;
	return utf32.c;
}

c32 Char::getValue() const {
	return getUTF32();
}

bool Char::isASCII() const {
	const struct ASCII &ascii = this->value.ascii;

	if ((u8)(ascii.c) <= 127 and checkCharValueBytes(ASCII_PaddingMask) == true)
		return true;

	return false;
}

bool Char::isGBK() const {
	const struct GBK &gbk = this->value.gbk;

	if (gbk.c >= 0x8140 and gbk.c <= 0xfefe and checkCharValueBytes(GBK_PaddingMask) == true)
		return true;

	return false;
}

bool Char::isUTF8() const {
	i32 length = getUTF8Length();

	if (length == 0) {
		return false;
	} else {
		return checkCharValueBytes(UTF8_PaddingMask[length - 1]);
	}
}

bool Char::isUTF32() const {
	return checkCharValueBytes(UTF32_PaddingMask);
}

bool Char::isSupportedEncoding() const {
	if (isASCII() == true)
		return true;
	if (isGBK() == true)
		return true;
	if (isUTF8() == true)
		return true;
	if (isUTF32() == true)
		return true;
	return false;
}

i32 Char::getUTF8Length() const {
	const struct UTF8 &utf8 = this->value.utf8;

	i32 length = 0;

	if ((u8) utf8.c[0] <= 0b01111111) {
		return 1;
	} else if ((u8) utf8.c[0] <= 0b11011111) {
		length = 2;
	} else if ((u8) utf8.c[0] <= 0b11101111) {
		length = 3;
	} else if ((u8) utf8.c[0] <= 0b11110111) {
		length = 4;
	} else if ((u8) utf8.c[0] <= 0b11111011) {
		length = 5;
	} else if ((u8) utf8.c[0] <= 0b11111101) {
		length = 6;
	}

	for (i32 i = 1; i < length; i++) {
		if ((u8) utf8.c[i] > 0b10111111)
			return 0;
	}

	if (utf8.c[length] != 0) // 截断
		return 0;

	return length;
}

bool Char::isLower() const {
	return IsLower(getValue());
}

bool Char::isUpper() const {
	return IsUpper(getValue());
}

bool Char::isAlpha() const {
	return IsAlpha(getValue());
}

bool Char::isDigit() const {
	return IsDigit(getValue());
}

bool Char::isAlNum() const {
	return IsAlNum(getValue());
}

bool Char::isCntrl() const {
	return IsCntrl(getValue());
}

bool Char::isGraph() const {
	return IsGraph(getValue());
}

bool Char::isPrint() const {
	return IsPrint(getValue());
}

bool Char::isPunct() const {
	return IsPunct(getValue());
}

bool Char::isSpace() const {
	return IsSpace(getValue());
}

bool Char::isXdigit() const {
	return IsXdigit(getValue());
}

Char* Char::toLower() {
	return new Char(ToLower(getValue()));
}

Char* Char::toUpper() {
	return new Char(ToUpper(getValue()));
}

bool Char::isCJKCharacter() const {
	return IsCJKCharacter(getValue());
}

bool Char::isBaseChineseCharacter() const {
	return IsBaseChineseCharacter(getValue());
}

bool Char::isChineseLowerDight() const {
	return IsChineseLowerDight(getValue());
}

bool Char::isChineseUpperDight() const {
	return IsChineseUpperDight(getValue());
}

bool Char::isChineseDight() const {
	return IsChineseDight(getValue());
}

Char* Char::toChineseLowerDigit() {
	return new Char(ToChineseLowerDigit(getValue()));
}

Char* Char::toChineseUpperDigit() {
	return new Char(ToChineseLowerDigit(getValue()));
}

}
}
