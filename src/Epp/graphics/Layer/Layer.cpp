#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace graphics {

E_CLASS_DEF(Epp::graphics::Layer)

void Layer::Static() { // 静态块，类初始化时将会执行块内代码，为了防止Epp类型构建系统出错，静态块内的代码必须与类型加载顺序无关

}

Layer::Layer() {

}

void Layer::destroy() {
	delete this;
}

Layer::Layer(i32 w, i32 h, Color::Type colorType) :
		This(w, h, colorType, Rot_0) {
}

Layer::Layer(i32 w, i32 h, Color::Type colorType, Rot rot) :
		This(nullptr, w, h, colorType, rot) {
}

Layer::Layer(byte *fb, i32 w, i32 h, Color::Type colorType, Rot rot) :
		Base(fb, w, h, Color::GetBPP(colorType)) {
	this->rot = rot;

}

Rot Layer::getRot() {
	return this->rot;
}

void Layer::mapPixel(i32 &x, i32 &y) {
	return MapPixel(x, y, this->w, this->h, this->rot);
}

void Layer::rMapPixel(i32 &x, i32 &y) {
	return RMapPixel(x, y, this->w, this->h, this->rot);
}

EColor Layer::getPixel(i32 x, i32 y) {
	rMapPixel(x, y);
	return new Color(Base::readPixel(x, y), this->colorType);
}

void Layer::setPixel(i32 x, i32 y, EColor color) {
	rMapPixel(x, y);
	return Base::writePixel(x, y, color->getValue());
}

void Layer::drawLineH(i32 x0, i32 y0, i32 w, EColor color) {
	rMapPixel(x0, y0);
	switch (this->rot) {
	case Rot::Rot_0:
		return Base::writeRow(x0, y0, w, color->getValue());
	case Rot::Rot_90:
		return Base::writeCol(x0, y0, w, color->getValue());
	case Rot::Rot_180:
		return Base::writeRow(x0, y0, w, color->getValue());
	case Rot::Rot_270:
		return Base::writeCol(x0, y0, w, color->getValue());
	}
}

void Layer::drawLineV(i32 x0, i32 y0, i32 h, EColor color) {
	rMapPixel(x0, y0);
	switch (this->rot) {
	case Rot::Rot_0:
		return Base::writeCol(x0, y0, h, color->getValue());
	case Rot::Rot_90:
		return Base::writeRow(x0, y0, h, color->getValue());
	case Rot::Rot_180:
		return Base::writeCol(x0, y0, h, color->getValue());
	case Rot::Rot_270:
		return Base::writeRow(x0, y0, h, color->getValue());
	}
}

void Layer::fillRect(i32 x0, i32 y0, i32 w, i32 h, EColor color) {
	rMapPixel(x0, y0);
	return Base::writeRect(x0, y0, w, h, color->getValue());
}

void Layer::clear(EColor color) {
	Base::clear(color->getValue());
}

void Layer::unchecked_copyFrom(ELayer other, i32 x0, i32 y0, i32 w, i32 h, i32 x1, i32 y1) {
	if (w == this->w and h == this->h and other->w == this->w and other->h == this->h) { // 特殊情况
		return unchecked_copyFrom(other);
	}

	if (other->bpp == this->bpp) { // 如果像素位数一致
		if (other->colorType == this->colorType) { // 如果颜色类型一致，执行缓冲区复制
			return Base::unchecked_copyFrom(other, x0, y0, w, h, x1, y1);
		} else { // 像素位数一致但颜色类型不一致，针对特定颜色映射，执行偏字节最速复制
			if (other->colorType == Color::RGBX8888 and this->colorType == Color::XRGB8888) { // RGBX8888 -> XRGB8888

				i32 copySize = w * this->pixelSize - 1;
				for (i32 i = 0; i < h; i++) { // 执行行复制，以优化复制速度
					Copy(other->fbX[y0 + i] + x0 * this->pixelSize, this->fbX[y1 + i] + x1 * this->pixelSize + 1, 1, copySize);
					// 行首字节可选赋值为0，这里考虑到运行效率，弃置
				}

				return;
			} else if (other->colorType == Color::XRGB8888 and this->colorType == Color::RGBX8888) { // XRGB8888 -> RGBX8888

				i32 copySize = w * this->pixelSize - 1;

				for (i32 i = 0; i < h; i++) { // 执行行复制，以优化复制速度
					Copy(other->fbX[y0 + i] + x0 * this->pixelSize + 1, this->fbX[y1 + i] + x1 * this->pixelSize, 1, copySize);
					// 行尾字节可选赋值为0，这里考虑到运行效率，弃置
				}

				return;
			}
		}
	}

	// 像素位数不一致，只能执行逐点复制
	for (i32 y = 0; y < h; y++)
		for (i32 x = 0; x < w; x++) {
			Base::unchecked_writePixel(x, y, Color::Transform(other->unchecked_readPixel(x, y), other->colorType, this->colorType));
		}
}

void Layer::unchecked_copyFrom(ELayer other) {
	if (other->bpp == this->bpp) { // 如果像素位数一致
		if (other->colorType == this->colorType) { // 如果颜色类型一致，执行缓冲区复制
			return Base::unchecked_copyFrom(other);
		} else { // 像素位数一致但颜色类型不一致，针对特定颜色映射，执行最速复制
			if (other->fb == nullptr or this->fb == nullptr) { // 任意一个对象不具有实际缓冲区空间，通过fbX进行复制
				if (other->colorType == Color::RGBX8888 and this->colorType == Color::XRGB8888) { // RGBX8888 -> XRGB8888

					i32 copySize = this->lineSize - 1;

					for (i32 i = 0; i < this->h; i++) { // 执行行复制，以优化复制速度
						Copy(other->fbX[i], this->fbX[i] + 1, 1, copySize);
						// 行首字节可选赋值为0，这里考虑到运行效率，弃置
					}

					return;
				} else if (other->colorType == Color::XRGB8888 and this->colorType == Color::RGBX8888) { // XRGB8888 -> RGBX8888

					i32 copySize = this->lineSize - 1;

					for (i32 i = 0; i < this->h; i++) { // 执行行复制，以优化复制速度
						Copy(other->fbX[i] + 1, this->fbX[i], 1, copySize);
						// 行尾字节可选赋值为0，这里考虑到运行效率，弃置
					}

					return;
				}
			} else { // 两个对象都具有实际缓冲区空间，执行最速复制
				if (other->colorType == Color::RGBX8888 and this->colorType == Color::XRGB8888) { // RGBX8888 -> XRGB8888

					Copy(other->fb, this->fb + 1, 1, this->fbSize - 1);
					// 缓冲区首字节可选赋值为0，这里考虑到运行效率，弃置

					return;
				} else if (other->colorType == Color::XRGB8888 and this->colorType == Color::RGBX8888) { // XRGB8888 -> RGBX8888

					Copy(other->fb + 1, this->fb, 1, this->fbSize - 1);
					// 缓冲区尾字节可选赋值为0，这里考虑到运行效率，弃置

					return;
				}
			}
		}
	}

	// 像素位数不一致，只能执行逐点复制
	for (i32 y = 0; y < this->h; y++)
		for (i32 x = 0; x < this->w; x++) {
			Base::unchecked_writePixel(x, y, Color::Transform(other->unchecked_readPixel(x, y), other->colorType, this->colorType));
		}
}

void Layer::copyFrom(ELayer other, i32 x0, i32 y0, i32 w, i32 h, i32 x1, i32 y1) {
	if (w <= 0 or h <= 0) { // 矩形区域面积必须大于0
		throw new Exception(S("Illegal Parameter: The area of the rect must be greater than 0"));
	} else if (x0 < 0 or y0 < 0 or x0 + w > other->w or y0 + h > other->h) { // 复制的矩形区域必须位于other所拥有的内存空间内
		throw new Exception(S("Illegal Parameter: Attempt to read illegal memory area"));
	} else if (x1 < 0 or y1 < 0 or x1 + w > this->w or y1 + h > this->h) { // 复制后的矩形区域必须位于本实例所拥有的内存空间内
		throw new Exception(S("Illegal Parameter: Attempt to write to illegal memory area"));
	}

	return unchecked_copyFrom(other, x0, y0, w, h, x1, y1);
}

void Layer::copyFrom(ELayer other) {
	if (other->w != this->w or other->h != this->h) { // 图层大小必须一致，否则报错
		throw new Exception(S("Inconsistent Size"));
	}

	return unchecked_copyFrom(other);
}

}
}
