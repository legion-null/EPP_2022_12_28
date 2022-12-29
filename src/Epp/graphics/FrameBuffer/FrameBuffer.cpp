#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace graphics {

E_CLASS_DEF(Epp::graphics::FrameBuffer)

void FrameBuffer::Static() { // 静态块，类初始化时将会执行块内代码，为了防止Epp类型构建系统出错，静态块内的代码必须与类型加载顺序无关

}

FrameBuffer::FrameBuffer() {

}

void FrameBuffer::destroy() {
	if (ownBuf == true)
		SafeDelete(this->fb);
	SafeDelete(this->fbX);

	delete this;
}

FrameBuffer::FrameBuffer(i32 w, i32 h, i32 bpp) :
		This(nullptr, w, h, bpp) {

}

FrameBuffer::FrameBuffer(byte *fb, i32 w, i32 h, i32 bpp) {
	reset(fb, w, h, bpp);
}

void FrameBuffer::reset(byte *fb, i32 w, i32 h, i32 bpp) {
	// 更新基本成员信息
	this->w = w;
	this->h = h;
	this->bpp = bpp;

	// 更新成员lineSize
	this->lineSize = w * this->bpp / 8;

	if (this->fbSize == w * h * bpp / 8) { // this->fbSize
		if (fb == nullptr and this->fb != nullptr)
			return;
	} else { // 更新成员fbSize
		this->fbSize = this->lineSize * this->h;
	}

	byte *tmpfb = nullptr;
	byte **tmpfbX = nullptr;

	if (fb == nullptr) { // 新建this->fb
		tmpfb = new byte[this->fbSize];
	} else {
		tmpfb = fb;
	}

	{ // tmpfbX的创建与映射
		tmpfbX = new byte*[this->h];
		for (i32 i = 0; i < this->h; i++) {
			tmpfbX[i] = &(tmpfb[this->lineSize * i]);
		}
	}

	// 交换缓冲区指针
	// 上锁
	Swap(this->fb, tmpfb);
	Swap(this->fbX, tmpfbX);
	// 解锁

	// 安全删除临时变量
	SafeDelete(tmpfb);
	SafeDelete(tmpfbX);
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

i32 FrameBuffer::readPixel(i32 x, i32 y) {
	i32 color = 0;

	switch (this->bpp) {
	case 8: {
		color = *(((u8*) ((this->fbX[y]))) + x);
		break;
	}
	case 16: {
		color = *(((u16*) ((this->fbX[y]))) + x);
		break;
	}
	case 24: {
		byte *p = (((u8*) (this->fbX[y])) + 3 * x);
		color = (*p << 16) | (*(p + 1) << 8) | *(p + 2);
		break;
	}
	case 32: {
		color = *(((u32*) ((this->fbX[y]))) + x);
		break;
	}
	}

	return color;
}

void FrameBuffer::writePixel(i32 x, i32 y, i32 color) {
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
		byte *p = (((u8*) (this->fbX[y])) + 3 * x);
		*(p + 0) = 0xff & (color >> 16);
		*(p + 1) = 0xff & (color >> 8);
		*(p + 2) = 0xff & (color >> 0);
		break;
	}
	case 32:
		*(((u32*) ((this->fbX[y]))) + x) = (u32) (color);
		break;
	}
}

void FrameBuffer::writeRow(i32 x0, i32 y0, i32 w, i32 color) {
	i32 x1 = x0 + w - 1;

	for (i32 x = x0; x <= x1; x++) {
		writePixel(x, y0, color);
	}
}

void FrameBuffer::writeCol(i32 x0, i32 y0, i32 h, i32 color) {
	i32 y1 = y0 + h - 1;

	for (i32 y = y0; y <= y1; y++) {
		writePixel(x0, y, color);
	}
}

void FrameBuffer::writeRect(i32 x0, i32 y0, i32 w, i32 h, i32 color) {
	i32 y1 = y0 + h - 1;

	for (i32 y = y0; y <= y1; y++) {
		writeRow(x0, y, w, color);
	}
}

void FrameBuffer::clear(i32 color) {
	writeRect(0, 0, this->w, this->h, color);
}

void FrameBuffer::copyFrom(EFrameBuffer other, i32 x0, i32 y0, i32 w, i32 h, i32 x1, i32 y1) {
	if (other->bpp != this->bpp) { // 像素位数必须一致，否则报错
		throw new Error(S("Inconsistent bpp"));
	} else if (w <= 0 or h <= 0) { // 矩形区域面积必须大于0
		throw new Error(S("Illegal Parameter: The area of the rect must be greater than 0"));
	} else if (x0 < 0 or y0 < 0 or x0 + w > other->w or y0 + h > other->h) { // 复制的矩形区域必须位于other所拥有的内存空间内
		throw new Error(S("Illegal Parameter: Attempt to read illegal memory area"));
	} else if (x1 < 0 or y1 < 0 or x1 + w > this->w or y1 + h > this->h) { // 复制后的矩形区域必须位于本实例所拥有的内存空间内
		throw new Error(S("Illegal Parameter: Attempt to write to illegal memory area"));
	} else {
		i32 lineSize = w * this->bpp / 8;
		for (i32 i = 0; i < h; i++) {
			Copy(other->fbX[y0 + i] + x0, this->fbX[y1 + i] + x1, 1, lineSize);
		}
	}
}

void FrameBuffer::copyFrom(EFrameBuffer other) {
	if (other->fbSize != this->fbSize) { // 缓冲区大小必须一致，否则报错
		throw new Error(S("Inconsistent fbSize"));
	} else {
		if (this->ownBuf == false or other->ownBuf == false) {
			for (i32 i = 0; i < h; i++) {
				Copy(other->fbX[i], this->fbX[i], 1, this->lineSize);
			}
		} else {
			Copy(other->fb, this->fb, 1, this->fbSize);
		}
	}
}

}
}
