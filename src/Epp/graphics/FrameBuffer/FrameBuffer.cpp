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

FrameBuffer::FrameBuffer(i32 w, i32 h, i32 bpp) {
	this->w = w;
	this->h = h;
	this->bpp = bpp;

	reset(w, h, bpp);
}

void FrameBuffer::reset(i32 w, i32 h, i32 bpp) {
	if (this->lineSize == w * this->bpp / 8 and this->fbSize == this->lineSize * this->h)
		return;

	// 参数设定
	this->lineSize = w * this->bpp / 8;
	this->fbSize = this->lineSize * this->h;

	// 创建tmpfb和tmpfbX并将tmpfbX映射到tmpfb
	u8 *tmpfb = new u8[this->fbSize];
	u8 **tmpfbX = new u8*[this->h];

	for (i32 i = 0; i < this->h; i++)
		tmpfbX[i] = &(tmpfb[this->lineSize * i]);

	// 如果fb非空的话, 将其内容复制到tmpfb
	if (this->fb != nullptr)
		;

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
	switch (this->bpp) {
	case 8:
		return *(((u8*) ((this->fbX[y]))) + x);
	case 16:
		return *(((u16*) ((this->fbX[y]))) + x);
	case 24: {
		u8 *p = (((u8*) (this->fbX[y])) + 3 * x);
		return (*p << 16) | (*(p + 1) << 8) | *(p + 2);
	}
	case 32:
		return *(((u32*) ((this->fbX[y]))) + x);
	default:
		return 0;
	}
}

void FrameBuffer::writePixel(i32 x, i32 y, i32 color) {
	switch (this->bpp) {
	case 8:
		*(((u8*) ((this->fbX[y]))) + x) = (u8) (color);
		break;
	case 16:
		*(((u16*) ((this->fbX[y]))) + x) = (u16) (color);
		break;
	case 24: {
		u8 *p = (((u8*) (this->fbX[y])) + 3 * x);
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

	for (i32 x = x0; x <= x1; x++)
		writePixel(x, y0, color);
}

void FrameBuffer::writeCol(i32 x0, i32 y0, i32 h, i32 color) {
	i32 y1 = y0 + h - 1;

	for (i32 y = y0; y <= y1; y++)
		writePixel(x0, y, color);
}

void FrameBuffer::writeRect(i32 x0, i32 y0, i32 w, i32 h, i32 color) {
	i32 y1 = y0 + h - 1;

	for (i32 y = y0; y <= y1; y++)
		writeRow(x0, y, w, color);
}

void FrameBuffer::clear(i32 color) {
	writeRect(0, 0, this->w, this->h, color);
}

}
}
