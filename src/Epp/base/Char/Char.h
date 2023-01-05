#pragma once

#include "base/Object/Object.h"

namespace Epp {
namespace base {

using c64 = u64;

class Char: public Epp::base::Object {

EPP_CLASS_INFO

public:
	enum Type : u8 {
		ASCII,		// ASCII
		GB18030,	// GB18030（2022，随版本更新），向下兼容GB18030，GB2312
		UTF8,		// UTF8（随版本更新）
		UTF32,		// UTF32（随版本更新）
	};

public:
	static const c8* GetEnumName(Type e);

protected:
	static Type DefaultCharType;

public:
	static Type GetDefaultCharType();
	static void SetDefaultCharType(Type type);

protected:
	struct ASCII {
		/* ASCII编码格式
		 * 0x00 - 0xAF
		 */
#if EPP_CURRENT_ENDIAN == EPP_ENDIAN_LITTLE
		u8 c;
		u64 __padding :56;
#else
		u64 __padding :56;
		u8 c;
#endif
	};

	struct GB18030 {
		/* GB18030编码格式
		 *
		 *
		 */
#if EPP_CURRENT_ENDIAN == EPP_ENDIAN_LITTLE
		u8 c[4];
		u64 __padding :32;
#else
		u64 __padding :32;
		u8 c[4];
#endif
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
#if EPP_CURRENT_ENDIAN == EPP_ENDIAN_LITTLE
		u8 c[6];
		u64 __padding :16;
#else
		u64 __padding :16;
		u8 c [6];
#endif
	};

	struct UTF32 {
		/*	UTF32编码格式
		 *
		 */
#if EPP_CURRENT_ENDIAN == EPP_ENDIAN_LITTLE
		u32 c;
		u64 __padding :32;
#else
		u64 __padding :32;
		u32 c;
#endif
	};

	// 空置位掩码
	static const u8 ASCII_PaddingMask;
	static const u8 GB18030_PaddingMask;
	static const u8 UTF8_PaddingMask[6];
	static const u8 UTF32_PaddingMask;

protected:
	union CharData {
		struct ASCII ascii;
		struct GB18030 gb18030;
		struct UTF8 utf8;
		struct UTF32 utf32;
		c64 value; 		// 使用UTF32编码
	};

public:
	static c64 ToUTF32(c64 value, Type src);
	static c64 FromUTF32(c64 value, Type dest);

	static c64 ToC64(c64 value, Type src);
	static c64 FromC64(c64 value, Type dest);

	static c64 Transform(c64 value, Type src, Type dest);

public:
	static bool IsLower(c64 c);
	static bool IsUpper(c64 c);
	static bool IsAlpha(c64 c);
	static bool IsDigit(c64 c);
	static bool IsAlNum(c64 c);
	static bool IsCntrl(c64 c);
	static bool IsGraph(c64 c);
	static bool IsPrint(c64 c);
	static bool IsPunct(c64 c);
	static bool IsSpace(c64 c);
	static bool IsXdigit(c64 c);

	static c64 ToLower(c64 c);
	static c64 ToUpper(c64 c);

public:
	static bool IsCJKCharacter(c32 c);

	static bool IsBaseChineseCharacter(c32 c);

	static bool IsChineseLowerDight(c32 c);
	static bool IsChineseUpperDight(c32 c);
	static bool IsChineseDight(c32 c);

	static c32 ToChineseLowerDigit(c32 c);
	static c32 ToChineseUpperDigit(c32 c);

protected:
	union CharData value = {
		.value = 0,
	};

public:
	Char();
	virtual ~Char();

public:
	Char(const c8 c);
	Char(const c16 c);
	Char(const c32 c);
	Char(const c64 c);
	Char(const c8 *c);

private:
	void clearCharValueBytes(u8 bytes);
	bool checkCharValueBytes(u8 bytes) const;

public:
	c8 getASCII() const;
	c16 getGB18030() const;
	const c8* getUTF8() const;
	c32 getUTF32() const;

	c32 getValue() const;

public:
	bool isASCII() const;
	bool isGB18030() const;
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

	}
	;

	}
}

