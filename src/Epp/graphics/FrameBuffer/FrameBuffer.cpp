#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace graphics {

const Class *FrameBuffer::ClassInfo = Class::Register<FrameBuffer, Object>("Epp::graphics::FrameBuffer", nullptr);

FrameBuffer::FrameBuffer() {

}

FrameBuffer::FrameBuffer(i32 w, i32 h, i32 bpp) :
		FrameBuffer(nullptr, w, h, bpp) {

}

FrameBuffer::FrameBuffer(u8 *fb, i32 w, i32 h, i32 bpp) {
	// 设置基本成员信息
	this->w = w;
	this->h = h;
	this->bpp = bpp;

	// 计算成员信息
	this->pixelSize = this->bpp / 8;
	this->lineSize = this->w * this->pixelSize;
	this->fbSize = this->lineSize * this->h;

	if (fb != nullptr) { // 如果传入非空指针，认为是从外界获取了了一块内存空间作为缓冲区，将指针直接传给this->fb
		this->fb = fb;
	} else { // 否则，自行申请一块内存空间作为缓冲区
		this->fb = new u8[this->fbSize];
	}

	// 创建和进行二级映射
	this->fbX = new u8*[this->h];
	for (i32 i = 0; i < this->h; i++) {
		this->fbX[i] = &(this->fb[this->lineSize * i]);
	}
}

i32 FrameBuffer::getWidth() {
	return this->w;
}

i32 FrameBuffer::getHeight() {
	return this->h;
}

void FrameBuffer::getSize(i32 &w, i32 &h) {
	w = this->w;
	h = this->h;
}

i32 FrameBuffer::getBpp() {
	return this->bpp;
}

const u8* FrameBuffer::getFb() {
	return this->fb;
}

bool FrameBuffer::check_off(i32 off) {
	if (off < 0 or off >= this->fbSize) {
		return false;
	} else {
		return true;
	}
}

bool FrameBuffer::check_lineOff(i32 lineOff) {
	if (lineOff < 0 or lineOff >= this->lineSize) {
		return false;
	} else {
		return true;
	}
}

bool FrameBuffer::check_x(i32 x) {
	if (x < 0 or x >= this->w) {
		return false;
	} else {
		return true;
	}
}

bool FrameBuffer::check_y(i32 y) {
	if (y < 0 or y >= this->h) {
		return false;
	} else {
		return true;
	}
}

u8* FrameBuffer::unchecked_getOff(i32 off) {
	return this->fbX[off % this->lineSize] + (off / this->lineSize);
}

u8* FrameBuffer::getOff(i32 off) {
	if (check_off(off) == false) {
		throw new Exception();
	}

	return unchecked_getOff(off);
}

u8 FrameBuffer::unchecked_readByte(i32 off) {
	return this->fb[off];
}

void FrameBuffer::unchecked_writeByte(i32 off, u8 value) {
	this->fb[off] = value;
}

u8 FrameBuffer::readByte(i32 off) {
	if (check_off(off) == false) {
		throw new Exception();
	}

	if (this->fb != nullptr) {
		return unchecked_readByte(off);
	} else {
		return unchecked_readByte(off % this->lineSize, off / this->lineSize);
	}
}

void FrameBuffer::writeByte(i32 off, u8 value) {
	if (check_off(off) == false) {
		throw new Exception();
	}

	if (this->fb != nullptr) {
		return unchecked_writeByte(off, value);
	} else {
		return unchecked_writeByte(off % this->lineSize, off / this->lineSize, value);
	}
}

u8 FrameBuffer::unchecked_readByte(i32 lineOff, i32 y) {
	return this->fbX[y][lineOff];
}

void FrameBuffer::unchecked_writeByte(i32 lineOff, i32 y, u8 value) {
	this->fbX[y][lineOff] = value;
}

u8 FrameBuffer::readByte(i32 lineOff, i32 y) {
	if (check_lineOff(lineOff) == false or check_y(y) == false) {
		throw new Exception();
	}

	return unchecked_readByte(lineOff, y);
}

void FrameBuffer::writeByte(i32 lineOff, i32 y, u8 value) {
	if (check_lineOff(lineOff) == false or check_y(y) == false) {
		throw new Exception();
	}

	return unchecked_writeByte(lineOff, y, value);
}

color_t FrameBuffer::unchecked_readPixel(i32 x, i32 y) {
	color_t color = 0;

	switch (this->bpp) {
	case 8: {
		color = ((u8*) (this->fbX[y]))[x];
		break;
	}
	case 16: {
		color = ((u16*) (this->fbX[y]))[x];
		break;
	}
	case 24: {
		u8 *p = (((u8*) (this->fbX[y])) + 3 * x);
		color = (*p << 16) | (*(p + 1) << 8) | *(p + 2);
		break;
	}
	case 32: {
		color = ((color_t*) (this->fbX[y]))[x];
		break;
	}
	}

	return color;
}

void FrameBuffer::unchecked_writePixel(i32 x, i32 y, color_t color) {
	//EPP_FUNC_LOCATE("%d, %d, 0x%08X", x, y, color);
	switch (this->bpp) {
	case 8: {
		*(((u8*) ((this->fbX[y]))) + x) = (u8) (color);
		break;
	}
	case 16: {
		*(((u16*) ((this->fbX[y]))) + x) = (u16) (color);
		break;
	}
	case 24: {
		u8 *p = (((u8*) (this->fbX[y])) + 3 * x);
		*(p + 0) = 0xff & (color >> 16);
		*(p + 1) = 0xff & (color >> 8);
		*(p + 2) = 0xff & (color >> 0);
		break;
	}
	case 32:
		*(((color_t*) ((this->fbX[y]))) + x) = color;
		break;
	}
}

color_t FrameBuffer::readPixel(i32 x, i32 y) {
	if (x < 0 or x >= this->w or y < 0 or y >= this->h) {
		throw new Exception();
	}

	return unchecked_readPixel(x, y);
}

void FrameBuffer::writePixel(i32 x, i32 y, color_t color) {
	if (x < 0 or x >= this->w or y < 0 or y >= this->h) {
		throw new Exception();
	}

	return unchecked_writePixel(x, y, color);
}

void FrameBuffer::unchecked_writeRow(i32 x0, i32 y0, i32 w, color_t color) {
	i32 x1 = x0 + w - 1;
	for (i32 x = x0; x <= x1; x++) {
		unchecked_writePixel(x, y0, color);
	}
}

void FrameBuffer::unchecked_writeCol(i32 x0, i32 y0, i32 h, color_t color) {
	i32 y1 = y0 + h - 1;
	for (i32 y = y0; y <= y1; y++) {
		unchecked_writePixel(x0, y, color);
	}
}

void FrameBuffer::unchecked_writeRect(i32 x0, i32 y0, i32 w, i32 h, color_t color) {
	i32 y1 = y0 + h - 1;
	for (i32 y = y0; y <= y1; y++) {
		unchecked_writeRow(x0, y, w, color);
	}
}

void FrameBuffer::writeRow(i32 x0, i32 y0, i32 w, color_t color) {
	//EPP_FUNC_LOCATE("%d, %d, %d, %d", x0, y0, w, color);
	if (check_y(y0) == false or x0 < 0 or w <= 0 or x0 + w > this->w) {
		throw new Exception();
	}

	return unchecked_writeRow(x0, y0, w, color);
}

void FrameBuffer::writeCol(i32 x0, i32 y0, i32 h, color_t color) {
	if (check_x(x0) == false or y0 < 0 or h <= 0 or y0 + h > this->h) {
		throw new Exception();
	}

	return unchecked_writeCol(x0, y0, h, color);
}

void FrameBuffer::writeRect(i32 x0, i32 y0, i32 w, i32 h, color_t color) {
	if (x0 < 0 or w <= 0 or x0 + w > this->w or y0 < 0 or h < 0 or y0 + h > this->h) {
		throw new Exception();
	}

	return unchecked_writeRect(x0, y0, w, h, color);
}

void FrameBuffer::writeAll(color_t color) {
	if (this->fb != nullptr) {
		SetMemory(this->fb, (u8*) &color, 4, this->w * this->h);
	} else {
		unchecked_writeRect(0, 0, this->w, this->h, color);
	}
}

void FrameBuffer::unchecked_copyFrom(FrameBuffer *other, i32 x0, i32 y0, i32 w, i32 h, i32 x1, i32 y1) {
	i32 copySize = this->pixelSize * w;

	for (i32 i = 0; i < h; i++) { // 执行行复制，以优化复制速度
		Copy(other->fbX[y0 + i] + x0 * this->pixelSize, this->fbX[y1 + i] + x1 * this->pixelSize, 1, copySize);
	}
}

void FrameBuffer::unchecked_copyFrom(FrameBuffer *other) {
	if (this->fb == nullptr or other->fb == nullptr) { // 任意一个对象不具有实际缓冲区空间，通过fbX进行复制

		for (i32 i = 0; i < h; i++) {
			Copy(other->fbX[i], this->fbX[i], 1, this->lineSize);
		}

	} else { // 两个对象都具有实际缓冲区空间，执行最速复制
		Copy(other->fb, this->fb, 1, this->fbSize);
	}
}

void FrameBuffer::copyFrom(FrameBuffer *other, i32 x0, i32 y0, i32 w, i32 h, i32 x1, i32 y1) {
	if (other->bpp != this->bpp) { // 像素位数必须一致，否则报错
		throw new Exception("Inconsistent bpp");
	} else if (w <= 0 or h <= 0) { // 矩形区域面积必须大于0
		throw new Exception("Illegal Parameter: The area of the rect must be greater than 0");
	} else if (x0 < 0 or y0 < 0 or x0 + w > other->w or y0 + h > other->h) { // 复制的矩形区域必须位于other所拥有的内存空间内
		throw new Exception("Illegal Parameter: Attempt to read illegal memory area");
	} else if (x1 < 0 or y1 < 0 or x1 + w > this->w or y1 + h > this->h) { // 复制后的矩形区域必须位于本实例所拥有的内存空间内
		throw new Exception("Illegal Parameter: Attempt to write to illegal memory area");
	}

	return unchecked_copyFrom(other, x0, y0, w, h, x1, y1);
}

void FrameBuffer::copyFrom(FrameBuffer *other) {
	if (other->fbSize != this->fbSize) { // 缓冲区大小必须一致，否则报错
		throw new Exception("Inconsistent fbSize");
	}

	return unchecked_copyFrom(other);
}

}
}
