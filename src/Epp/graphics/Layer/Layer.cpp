#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace graphics {

const base::Class *Layer::ClassInfo = base::Class::Register<Layer, FrameBuffer>("Epp::graphics::Layer", nullptr);

Layer::Layer() {

}

Layer::Layer(i32 w, i32 h, Color::Type colorType) :
		Layer(w, h, colorType, Rot_0) {
}

Layer::Layer(i32 w, i32 h, Color::Type colorType, Rot rot) :
		Layer(nullptr, w, h, colorType, rot) {
}

Layer::Layer(byte *fb, i32 w, i32 h, Color::Type colorType, Rot rot) :
		colorType(colorType), rot(rot), FrameBuffer(fb, w, h, Color::GetBPP(colorType)) {
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

Color* Layer::getPixel(i32 x, i32 y) {
	rMapPixel(x, y);
	return new Color(FrameBuffer::readPixel(x, y), this->colorType);
}

void Layer::setPixel(i32 x, i32 y, Color *color) {
	rMapPixel(x, y);
	return FrameBuffer::writePixel(x, y, color->getValue());
}

void Layer::drawLineH(i32 x0, i32 y0, i32 w, Color *color) {
	EPP_FUNC_LOCATE("%d, %d, %d, 0x%08X", x0, y0, w, color->getValue());
	rMapPixel(x0, y0);
	EPP_FUNC_LOCATE("%d, %d, %d, 0x%08X", x0, y0, w, color->getValue());
	switch (this->rot) {
	case Rot::Rot_0:
		return FrameBuffer::writeRow(x0, y0, w, color->getValue());
	case Rot::Rot_90:
		return FrameBuffer::writeCol(x0, y0, w, color->getValue());
	case Rot::Rot_180:
		return FrameBuffer::writeRow(x0, y0, w, color->getValue());
	case Rot::Rot_270:
		return FrameBuffer::writeCol(x0, y0, w, color->getValue());
	}
}

void Layer::drawLineV(i32 x0, i32 y0, i32 h, Color *color) {
	EPP_CODE_LOCATE();
	rMapPixel(x0, y0);
	switch (this->rot) {
	case Rot::Rot_0:
		return FrameBuffer::writeCol(x0, y0, h, color->getValue());
	case Rot::Rot_90:
		return FrameBuffer::writeRow(x0, y0, h, color->getValue());
	case Rot::Rot_180:
		return FrameBuffer::writeCol(x0, y0, h, color->getValue());
	case Rot::Rot_270:
		return FrameBuffer::writeRow(x0, y0, h, color->getValue());
	}
}

void Layer::fillRect(i32 x0, i32 y0, i32 w, i32 h, Color *color) {
	rMapPixel(x0, y0);
	return FrameBuffer::writeRect(x0, y0, w, h, color->getValue());
}

void Layer::clear(Color *color) {
	FrameBuffer::clear(color->getValue());
}

void Layer::unchecked_copyFrom(Layer *other, i32 x0, i32 y0, i32 w, i32 h, i32 x1, i32 y1) {
	if (w == this->w and h == this->h and other->w == this->w and other->h == this->h) { // 特殊情况
		return unchecked_copyFrom(other);
	}

	if (other->bpp == this->bpp) { // 如果像素位数一致
		if (other->colorType == this->colorType) { // 如果颜色类型一致，执行缓冲区复制
			EPP_DEBUG("%s", "颜色类型一致\n");
			return FrameBuffer::unchecked_copyFrom(other, x0, y0, w, h, x1, y1);
		} else { // 像素位数一致但颜色类型不一致，针对特定颜色映射，执行偏字节最速复制
			EPP_DEBUG("%s", "颜色类型不一致\n");
			if (other->colorType == Color::RGBX8888 and this->colorType == Color::XRGB8888) { // RGBX8888 -> XRGB8888
				EPP_DEBUG("%s", "使用快速复制RGBX8888->XRGB8888\n");

				i32 copySize = w * this->pixelSize - 1;
				EPP_DEBUG("每行复制字节数 %d\n", copySize);

				for (i32 i = 0; i < h; i++) { // 执行行复制，以优化复制速度
					Copy(other->fbX[i + y0] + x0 * this->pixelSize, this->fbX[y1 + i] + x1 * this->pixelSize + 1, 1, copySize);
					// 行首字节可选赋值为0，这里考虑到运行效率，弃置
				}

				return;
			} else if (other->colorType == Color::XRGB8888 and this->colorType == Color::RGBX8888) { // XRGB8888 -> RGBX8888
				EPP_DEBUG("%s", "使用快速复制XRGB8888->RGBX8888\n");

				i32 copySize = w * this->pixelSize - 1;

				for (i32 i = 0; i < h; i++) { // 执行行复制，以优化复制速度
					Copy(other->fbX[i + y0] + x0 * this->pixelSize + 1, this->fbX[y1 + i] + x1 * this->pixelSize, 1, copySize);
					// 行尾字节可选赋值为0，这里考虑到运行效率，弃置
				}

				return;
			}
		}
	}

	// 只能执行逐点复制
	EPP_DEBUG("只能逐点复制 复制区域 %dx%d\n", w, h);
	for (i32 y = 0; y < h; y++)
		for (i32 x = 0; x < w; x++) {
			FrameBuffer::unchecked_writePixel(x + x1, y + y1, Color::Transform(other->unchecked_readPixel(x + x0, y + y0), other->colorType, this->colorType));
		}
}

void Layer::unchecked_copyFrom(Layer *other) {
	if (other->bpp == this->bpp) { // 如果像素位数一致
		if (other->colorType == this->colorType) { // 如果颜色类型一致，执行缓冲区复制
			return FrameBuffer::unchecked_copyFrom(other);
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
			FrameBuffer::unchecked_writePixel(x, y, Color::Transform(other->unchecked_readPixel(x, y), other->colorType, this->colorType));
		}
}

void Layer::copyFrom(Layer *other, i32 x0, i32 y0, i32 w, i32 h, i32 x1, i32 y1) {
	EPP_FUNC_LOCATE("0x%016X, %d, %d, %d, %d, %d, %d", other, x0, y0, w, h, x1, y1);
	if (w <= 0 or h <= 0) { // 矩形区域面积必须大于0
		throw new Exception(S("Illegal Parameter: The area of the rect must be greater than 0"));
	} else if (x0 < 0 or y0 < 0 or x0 + w > other->w or y0 + h > other->h) { // 复制的矩形区域必须位于other所拥有的内存空间内
		throw new Exception(S("Illegal Parameter: Attempt to read illegal memory area"));
	} else if (x1 < 0 or y1 < 0 or x1 + w > this->w or y1 + h > this->h) { // 复制后的矩形区域必须位于本实例所拥有的内存空间内
		throw new Exception(S("Illegal Parameter: Attempt to write to illegal memory area"));
	}

	return unchecked_copyFrom(other, x0, y0, w, h, x1, y1);
}

void Layer::copyFrom(Layer *other) {
	if (other->w != this->w or other->h != this->h) { // 图层大小必须一致，否则报错
		throw new Exception(S("Inconsistent Size"));
	}

	return unchecked_copyFrom(other);
}

Painter* Layer::getPainter() {
	Painter *painter = Painter::GetDefaultIM();
	painter->setLayer(this);

	return painter;
}

}
}
