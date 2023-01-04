#pragma once

#include "base/Object/Object.h"

namespace Epp {
namespace base {



class Char: public Epp::base::Object {

EPP_CLASS_INFO

public:
	static bool IsLower(c32 c);
	static bool IsUpper(c32 c);
	static bool IsAlpha(c32 c);
	static bool IsDigit(c32 c);
	static bool IsAlNum(c32 c);
	static bool IsCntrl(c32 c);
	static bool IsGraph(c32 c);
	static bool IsPrint(c32 c);
	static bool IsPunct(c32 c);
	static bool IsSpace(c32 c);
	static bool IsXdigit(c32 c);

	static c32 ToLower(c32 c);
	static c32 ToUpper(c32 c);

public:
	static bool IsCJKCharacter(c32 c);

	static bool IsBaseChineseCharacter(c32 c);

	static bool IsChineseLowerDight(c32 c);
	static bool IsChineseUpperDight(c32 c);
	static bool IsChineseDight(c32 c);

	static c32 ToChineseLowerDigit(c32 c);
	static c32 ToChineseUpperDigit(c32 c);

protected:
	struct ASCII {
		/* ASCII编码格式
		 * 0x00 - 0xAF
		 */
		c8 __padding[5];
		c8 c;
	};

	struct GBK {
		/* GBK编码格式
		 *
		 *
		 */
		c8 __padding[4];
		c16 c;
	};

	struct UTF8 {
		/*	UTF8编码格式
		 *
		 *	码点的位数	码点起值	 	码点终值 		字节序列 		Byte 1 		Byte 2 		Byte 3 		Byte 4 		Byte 5 		Byte 6
		 *	7			U+0000 		U+007F 		1 			0xxxxxxx
		 *	11 			U+0080 		U+07FF 		2 			110xxxxx 	10xxxxxx
		 *	16 			U+0800 		U+FFFF 		3 			1110xxxx 	10xxxxxx 	10xxxxxx
		 *	21 			U+10000 	U+1FFFFF 	4 			11110xxx 	10xxxxxx 	10xxxxxx 	10xxxxxx
		 *	26 			U+200000 	U+3FFFFFF 	5 			111110xx 	10xxxxxx 	10xxxxxx 	10xxxxxx 	10xxxxxx
		 *	31  		U+4000000 	U+7FFFFFFF 	6 			1111110x 	10xxxxxx 	10xxxxxx 	10xxxxxx 	10xxxxxx 	10xxxxxx
		 */
		c8 c[6];
	};

	struct UTF32 {
		/*	UTF32编码格式
		 *
		 */
		c8 __padding[2];
		c32 c;
	};

	// 空置位掩码
	static const u8 ASCII_PaddingMask;
	static const u8 GBK_PaddingMask;
	static const u8 UTF8_PaddingMask[6];
	static const u8 UTF32_PaddingMask;

protected:
	union CharValue {
		struct ASCII ascii;
		struct GBK gbk;
		struct UTF8 utf8;
		struct UTF32 utf32;
	};

protected:
	union CharValue value;

public:
	Char();
	virtual ~Char();

public:
	Char(const c8 c);
	Char(const c16 c);
	Char(const c8 *c);
	Char(const c32 c);

private:
	void clearCharValueBytes(u8 bytes);
	bool checkCharValueBytes(u8 bytes) const;

public:
	c8 getASCII() const;
	c16 getGBK() const;
	const c8* getUTF8() const;
	c32 getUTF32() const;

	c32 getValue() const;

public:
	bool isASCII() const;
	bool isGBK() const;
	bool isUTF8() const;
	bool isUTF32() const;

	bool isSupportedEncoding() const;

	i32 getUTF8Length() const;

public:
	bool isLower() const;
	bool isUpper() const;
	bool isAlpha() const;
	bool isDigit() const;
	bool isAlNum() const;
	bool isCntrl() const;
	bool isGraph() const;
	bool isPrint() const;
	bool isPunct() const;
	bool isSpace() const;
	bool isXdigit() const;

	Char* toLower();
	Char* toUpper();

public:
	bool isCJKCharacter() const;

	bool isBaseChineseCharacter() const;

	bool isChineseLowerDight() const;
	bool isChineseUpperDight() const;
	bool isChineseDight() const;

	Char* toChineseLowerDigit();
	Char* toChineseUpperDigit();

};

}
}

