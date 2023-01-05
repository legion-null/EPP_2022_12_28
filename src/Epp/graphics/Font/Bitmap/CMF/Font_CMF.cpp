#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

#include "Matrix/ASCII_3X5_1BPP.h"
#include "Matrix/ASCII_16X24_1BPP.h"
//#include "Matrix/UTF_BASE_CHINESE_24X24_4BPP.h"

namespace Epp {
namespace graphics {

const Class *Font_CMF::ClassInfo = Class::Register<Font_CMF, Font_Bitmap>("Epp::graphics::Font_CMF", &(Font_CMF::Static));

const Font_CMF *Font_CMF::ASCII_3X5_1BPP = new Font_CMF(16, 24, 1, (const i32*) MATRIX_ASCII_3X5_1BPP_CODES, 1, (const u8*) MATRIX_ASCII_3X5_1BPP_DATA);
const Font_CMF *Font_CMF::ASCII_16X24_1BPP = new Font_CMF(16, 24, 1, (const i32*) MATRIX_ASCII_16X24_1BPP_CODES, 1, (const u8*) MATRIX_ASCII_16X24_1BPP_DATA);
//const Font_CMF *Font_CMF::UTF_BASE_CHINESE_24X24_4BPP = new Font_CMF(24, 24, 4, (const i32*) MATRIX_UTF_BASE_CHINESE_24X24_4BPP_CODES, 1,
//		(const u8*) MATRIX_UTF_BASE_CHINESE_24X24_4BPP_DATA);

void Font_CMF::Static() {

}

Font_CMF::Font_CMF() {

}

Font_CMF::~Font_CMF() {

}

Font_CMF::Font_CMF(i32 w, i32 h, i32 bpp, const i32 *charsInfo, i32 charsInfoN, const u8 *matrix) {
	this->w = w;
	this->h = h;
	this->bpp = bpp;

	this->charMatrixSize = this->w * this->h * this->bpp / 8;

	this->matrixData = matrix;

	this->csil.n = charsInfoN;

	this->csil.units = new CharScopeInfoUnit[this->csil.n];

	const u8 *p = this->matrixData;
	for (i32 i = 0, j = 0; i < this->csil.n; i++) {
		this->csil.units[i].start = charsInfo[j++];
		this->csil.units[i].end = charsInfo[j++];
		this->csil.units[i].offset = p;
		p += this->charMatrixSize;
	}
}

const u8* Font_CMF::getCharMatrix(i32 c) {
	for (i32 i = 0; i < csil.n; i++) {
		if (c >= csil.units[i].start and c <= csil.units[i].end) {
			return csil.units[i].offset + this->charMatrixSize * (c - csil.units[i].start);
		}
	}

	return nullptr;
}

i32 Font_CMF::getPointInMatrix(const u8 *matrix, i32 x, i32 y) {
	// 暂时先这样，明天1.4改成Image实现方式
	i32 offsetBit = (y * this->w + x) * bpp;
	i32 offsetByte = offsetBit / 8;
	i32 bit = offsetBit % 8;

	//EPP_DEBUG("bit = %d\n", bit);

//	i32 d = (matrix[offsetByte] >> (7 - bit)) & ((0x01 << bpp) - 1);
//	EPP_DEBUG("%d ", d);
//	return d;
//	return ((matrix[offsetByte] >> (7 - bit))) & ((0x01 << bpp) - 1);
	if (bpp == 1) {
		return 0x01 & (matrix[offsetByte] >> (7 - bit));
	} else if (bpp == 2) {
		return 0x03 & (matrix[offsetByte] >> (6 - bit));
	} else if (bpp == 4) {
		return 0x0f & (matrix[offsetByte] >> (4 - bit));
	}
	return 0;
}

bool Font_CMF::hasCharacter(i32 c) {
	return (getCharMatrix(c) != nullptr);
}

Image* Font_CMF::getCharacterImage(i32 c) {
	EPP_FUNC_LOCATE("%d", c);

	const u8 *matrix = getCharMatrix(c);

	if (matrix == nullptr) {
		return getUnavailableCharacterImage(c);
	}

	// 创建一个图像
	Image *img = new Image(this->w, this->h, Color::GetDefaultColorType());
	Painter *painter = img->getPainter();
	img->clear(C(White));

	for (i32 j = 0; j < this->h; j++) {
		for (i32 i = 0; i < this->w; i++) {
			i32 temp = getPointInMatrix(matrix, i, j);

			if (temp >= 1) {
				switch (bpp) {
				case 1:
					painter->drawPixel(i, j);
					break;
				case 2:
					painter->setColor(new Color(White / 3 * (3 - temp)));
					painter->drawPixel(i, j);
					break;
				case 4:
					painter->setColor(new Color(White / 15 * (15 - temp)));
					painter->drawPixel(i, j);
					break;
				}
			}
		}
	}
	delete painter;
	return img;
}
}
}
