#include "Epp.h"

#include <ctype.h>

using namespace Epp::base;

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace base {

const Class *Char::ClassInfo = Class::Register<Char, Object>("Epp::base::Char", nullptr);

const c8* Char::GetEnumName(Type e) {
	switch (e) {
	case ASCII:
		return EPP_STR(ASCII);
	case GB18030:
		return EPP_STR(GB18030);
	case UTF8:
		return EPP_STR(UTF8);
	case UTF32:
		return EPP_STR(UTF32);
	default:
		throw new Exception("Careless forced transformation");
	}
}

Char::Type Char::DefaultCharType = Char::UTF8;

Char::Type Char::GetDefaultCharType() {
	return DefaultCharType;
}

void Char::SetDefaultCharType(Type type) {
	DefaultCharType = type;
}

const u8 Char::ASCII_PaddingMask = 0b111110;
const u8 Char::GB18030_PaddingMask = 0b111100;
const u8 Char::UTF8_PaddingMask[6] = { 0b011111, 0b001111, 0b000111, 0b000011, 0b000001, 0b000000, };
const u8 Char::UTF32_PaddingMask = 0b110000;

c64 Char::ToUTF32(c64 value, Type src) {
	//EPP_FUNC_LOCATE("0x%08X, %s", value, GetEnumName(src));

	if (src == UTF32)
		return value;

	CharData &c = (CharData&) value;
	CharData ret = { .value = 0 };

	switch (src) {
	case ASCII: {
		ret.utf32.c = (c64) ((CharData&) value).ascii.c;
		break;
	}
	case GB18030: {
		break;
	}
	case UTF8: {
		if (c.utf8.c[0] <= 0b01111111) { // 1字节长度UTF8
			// UTF8 1字节编码共有有效位 7 位
			ret.utf32.c += (c.utf8.c[0]);	// 7位有效位
		} else if (c.utf8.c[0] <= 0b11011111) { // 2字节长度UTF8
			// UTF8 2字节编码共有有效位 11 位，每字节分别为 5 6
			ret.utf32.c += (c.utf8.c[0] & 0b00011111);	// 5位有效位
			ret.utf32.c <<= 6;
			ret.utf32.c += (c.utf8.c[1] & 0b00111111);	// 6位有效位
		} else if (c.utf8.c[0] <= 0b11101111) { // 3字节长度UTF8
			// UTF8 3字节编码共有有效位 16 位，每字节分别为 4 6 6
			ret.utf32.c += (c.utf8.c[0] & 0b00001111);	// 4位有效位
			ret.utf32.c <<= 6;
			ret.utf32.c += (c.utf8.c[1] & 0b00111111);	// 6位有效位
			ret.utf32.c <<= 6;
			ret.utf32.c += (c.utf8.c[2] & 0b00111111);	// 6位有效位
		} else if (c.utf8.c[0] <= 0b11110111) { // 4字节长度UTF8
			// UTF8 4字节编码共有有效位 21 位，每字节分别为 3 6 6 6
			ret.utf32.c += (c.utf8.c[0] & 0b00000111);	// 3位有效位
			ret.utf32.c <<= 6;
			ret.utf32.c += (c.utf8.c[1] & 0b00111111);	// 6位有效位
			ret.utf32.c <<= 6;
			ret.utf32.c += (c.utf8.c[2] & 0b00111111);	// 6位有效位
			ret.utf32.c <<= 6;
			ret.utf32.c += (c.utf8.c[3] & 0b00111111);	// 6位有效位
		} else if (c.utf8.c[0] <= 0b11111011) { // 5字节长度UTF8
			// UTF8 3字节编码共有有效位 26 位，每字节分别为 2 6 6 6 6
			ret.utf32.c += (c.utf8.c[0] & 0b00000011);	// 4位有效位
			ret.utf32.c <<= 6;
			ret.utf32.c += (c.utf8.c[1] & 0b00111111);	// 6位有效位
			ret.utf32.c <<= 6;
			ret.utf32.c += (c.utf8.c[2] & 0b00111111);	// 6位有效位
			ret.utf32.c <<= 6;
			ret.utf32.c += (c.utf8.c[3] & 0b00111111);	// 6位有效位
			ret.utf32.c <<= 6;
			ret.utf32.c += (c.utf8.c[4] & 0b00111111);	// 6位有效位
		} else if (c.utf8.c[0] <= 0b11111101) { // 6字节长度UTF8
			// UTF8 3字节编码共有有效位 31 位，每字节分别为 1 6 6 6 6 6
			ret.utf32.c += (c.utf8.c[0] & 0b00000001);	// 1位有效位
			ret.utf32.c <<= 6;
			ret.utf32.c += (c.utf8.c[1] & 0b00111111);	// 6位有效位
			ret.utf32.c <<= 6;
			ret.utf32.c += (c.utf8.c[2] & 0b00111111);	// 6位有效位
			ret.utf32.c <<= 6;
			ret.utf32.c += (c.utf8.c[3] & 0b00111111);	// 6位有效位
			ret.utf32.c <<= 6;
			ret.utf32.c += (c.utf8.c[4] & 0b00111111);	// 6位有效位
			ret.utf32.c <<= 6;
			ret.utf32.c += (c.utf8.c[5] & 0b00111111);	// 6位有效位
		}
		break;
	}
	case UTF32: {
		EPP_CODE_LOCATE();
		throw new Exception("What the Fuck!");	// 正常情况下程序不会执行到这里
	}
	default:
		throw new Exception("Careless forced transformation");
	}

	return ret.value;
}

c64 Char::FromUTF32(c64 value, Type dest) {
	//EPP_FUNC_LOCATE("0x%08X, %s", value, GetEnumName(dest));

	if (dest == UTF32)
		return value;

	CharData &c = (CharData&) value;
	CharData ret = { .value = 0 };

	switch (dest) {
	case ASCII: {
		ret.ascii.c = c.utf32.c;
		break;
	}
	case GB18030: {

		break;
	}
	case UTF8: {
		if (c.utf32.c <= (u32) ((0x01 << 7) - 1)) { // 1字节长度UTF8
			//EPP_DEBUG("UTF8 1\n");
			// UTF8 1字节编码共有有效位 7 位
			ret.utf8.c[0] = 0b00000000 | (c.utf32.c);
		} else if (c.utf32.c <= (u32) (0x01 << 11) - 1) { // 2字节长度UTF8
			//EPP_DEBUG("UTF8 2\n");
			// UTF8 2字节编码共有有效位 11 位，每字节分别为 5 6
			ret.utf8.c[0] = 0b11000000 | ((c.utf32.c >> 6) & 0b00011111);
			ret.utf8.c[1] = 0b10000000 | (c.utf32.c & 0b00111111);
		} else if (c.utf32.c <= (u32) (0x01 << 16) - 1) { // 3字节长度UTF8
			//EPP_DEBUG("UTF8 3\n");
			// UTF8 3字节编码共有有效位 16 位，每字节分别为 4 6 6
			ret.utf8.c[0] = 0b11100000 | ((c.utf32.c >> 12) & 0b00001111);
			ret.utf8.c[1] = 0b10000000 | ((c.utf32.c >> 6) & 0b00111111);
			ret.utf8.c[2] = 0b10000000 | (c.utf32.c & 0b00111111);
		} else if (c.utf32.c <= (u32) (0x01 << 21) - 1) { // 4字节长度UTF8
			//EPP_DEBUG("UTF8 4\n");
			// UTF8 4字节编码共有有效位 21 位，每字节分别为 3 6 6 6
			ret.utf8.c[0] = 0b11110000 | ((c.utf32.c >> 18) & 0b00001111);
			ret.utf8.c[1] = 0b10000000 | ((c.utf32.c >> 12) & 0b00111111);
			ret.utf8.c[2] = 0b10000000 | ((c.utf32.c >> 6) & 0b00111111);
			ret.utf8.c[3] = 0b10000000 | ((c.utf32.c >> 6) & 0b00111111);
			ret.utf8.c[4] = 0b10000000 | ((c.utf32.c >> 6) & 0b00111111);
			ret.utf8.c[5] = 0b10000000 | (c.utf32.c & 0b00111111);
		} else if (c.utf32.c <= (u32) (0x01 << 26) - 1) { // 5字节长度UTF8
			//EPP_DEBUG("UTF8 5\n");
			// UTF8 3字节编码共有有效位 26 位，每字节分别为 2 6 6 6 6
			ret.utf8.c[0] = 0b11111000 | ((c.utf32.c >> 24) & 0b00000011);
			ret.utf8.c[1] = 0b10000000 | ((c.utf32.c >> 18) & 0b00111111);
			ret.utf8.c[2] = 0b10000000 | ((c.utf32.c >> 12) & 0b00111111);
			ret.utf8.c[3] = 0b10000000 | ((c.utf32.c >> 6) & 0b00111111);
			ret.utf8.c[4] = 0b10000000 | (c.utf32.c & 0b00111111);
		} else if (c.utf32.c <= (u32) (0x01 << 31) - 1) { // 6字节长度UTF8
			//EPP_DEBUG("UTF8 6\n");
			// UTF8 3字节编码共有有效位 31 位，每字节分别为 1 6 6 6 6 6
			ret.utf8.c[0] = 0b11111100 | ((c.utf32.c >> 30) & 0b00000001);
			ret.utf8.c[1] = 0b10000000 | ((c.utf32.c >> 24) & 0b00111111);
			ret.utf8.c[2] = 0b10000000 | ((c.utf32.c >> 18) & 0b00111111);
			ret.utf8.c[3] = 0b10000000 | ((c.utf32.c >> 12) & 0b00111111);
			ret.utf8.c[4] = 0b10000000 | ((c.utf32.c >> 6) & 0b00111111);
			ret.utf8.c[5] = 0b10000000 | (c.utf32.c & 0b00111111);
		}
		break;
	}
	case UTF32: {
		EPP_CODE_LOCATE();
		throw new Exception("What the Fuck!");	// 正常情况下程序不会执行到这里
	}
	default:
		throw new Exception("Careless forced transformation");
	}

	return ret.value;
}

c64 Char::ToC64(c64 value, Type src) {
	return ToUTF32(value, src);
}

c64 Char::FromC64(c64 value, Type dest) {
	return FromUTF32(value, dest);
}

c64 Char::Transform(c64 value, Type src, Type dest) {
	// EPP_CODE_LOCATE();
	return FromC64(ToC64(value, src), dest);
}

bool Char::IsLower(c64 c) {
	return ::islower(c);
}

bool Char::IsUpper(c64 c) {
	return ::isupper(c);
}

bool Char::IsAlpha(c64 c) {
	return ::isalpha(c);
}

bool Char::IsDigit(c64 c) {
	return ::isdigit(c);
}

bool Char::IsAlNum(c64 c) {
	return ::isalnum(c);
}

bool Char::IsCntrl(c64 c) {
	return ::iscntrl(c);
}

bool Char::IsGraph(c64 c) {
	return ::isgraph(c);
}

bool Char::IsPrint(c64 c) {
	return ::isprint(c);
}

bool Char::IsPunct(c64 c) {
	return ::ispunct(c);
}

bool Char::IsSpace(c64 c) {
	return ::isspace(c);
}

bool Char::IsXdigit(c64 c) {
	return ::isxdigit(c);
}

c64 Char::ToLower(c64 c) {
	return ::tolower(c);
}

c64 Char::ToUpper(c64 c) {
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
}

Char::Char(const c16 c) {
	this->value.gb18030.c[0] = (c >> 8) & 0xff;
	this->value.gb18030.c[1] = c & 0xff;
}

Char::Char(const c32 c) {
	this->value.utf32.c = c;
}

Char::Char(const c64 c) {
	this->value.value = c;
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

void Char::clearCharValueBytes(u8 bytes) {
	for (i32 i = 0; i < (i32) sizeof(union CharData); i++) {
		if (GetBit(bytes, i) == true)
			SetByte(this->value, i, 0x00);
	}
}

bool Char::checkCharValueBytes(u8 bytes) const {
	for (i32 i = 0; i < (i32) sizeof(union CharData); i++) {
		if (GetBit(bytes, i) == true)
			if (GetByte(this->value, i) != 0x00)
				return false;
	}
	return true;
}

c8 Char::getASCII() const {
	return this->value.ascii.c;
}

c16 Char::getGB18030() const {
//	const struct GB18030 &gb18030 = this->value.gb18030;
//	return gb18030.c;
	return 0;
}

const c8* Char::getUTF8() const {
	const struct UTF8 &utf8 = this->value.utf8;
	return (const c8*) utf8.c;
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

	if ((u8) (ascii.c) <= 127 and checkCharValueBytes(ASCII_PaddingMask) == true)
		return true;

	return false;
}

bool Char::isGB18030() const {
	//const struct GB18030 &gb18030 = this->value.gb18030;

	//if (gb18030.c >= 0x8140 and gb18030.c <= 0xfefe and checkCharValueBytes(GB18030_PaddingMask) == true)
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
	if (isASCII() == true) {
		return true;
	} else if (isGB18030() == true) {
		return true;
	} else if (isUTF8() == true) {
		return true;
	} else if (isUTF32() == true) {
		return true;
	} else {
		return false;
	}
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
