#pragma once

#include "graphics/Font/Bitmap/Font_Bitmap.h"

namespace Epp {
namespace graphics {

/*
 * CMF字体对象只支持一种大小的矩阵字体，且所支持字体只能由库的开发者提供并创建（废弃，通过读取特定格式的注册数据，允许用户创建）
 */
class Font_CMF: public Font_Bitmap {

EPP_CLASS_INFO

public:
	static const Font_CMF *ASCII_3X5_1BPP;
	static const Font_CMF *ASCII_16X24_1BPP;
//	static const Font_CMF *UTF_BASE_CHINESE_24X24_4BPP;

protected:
	static void Static();

protected:
	struct CharScopeInfoUnit { //字符范围信息单元
		i32 start;	// 开始字符代码
		i32 end; // 结束字符代码
		const u8 *offset;
	} __attribute__((packed));

	struct CharScopeInfoList { //字符范围信息表
		i32 n;
		struct CharScopeInfoUnit *units;
	} __attribute__((packed));

protected:
	struct CharScopeInfoList csil;

protected:
	i32 bpp = 1;
	i32 charMatrixSize = 0;
	const u8 *matrixData = nullptr;

public:
	Font_CMF();
	~Font_CMF();

public:
	Font_CMF(i32 w, i32 h, i32 bpp, const i32 *charsInfo, i32 charsInfoN, const u8 *matrix);

protected:
	const u8* getCharMatrix(i32 c);
	i32 getPointInMatrix(const u8 *matrix, i32 x, i32 y);

public:
	virtual bool hasCharacter(i32 c) override;

public:
	virtual Image* getCharacterImage(i32 c) override;

};

}
}

