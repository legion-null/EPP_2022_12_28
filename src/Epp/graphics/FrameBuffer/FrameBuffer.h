#pragma once

#include "base/Object/Object.h"

namespace Epp {
namespace graphics {

/*
 * 考虑到FrameBuffer的运行效率在图像显示方面有着重要意义，FrameBuffer类对象的一些成员方法没有对输入进行校验，需要谨慎的继承FrameBuffer
 */

class FrameBuffer: public Epp::base::Object {

EPP_CLASS_INFO

protected:
	i32 w = 0;
	i32 h = 0;
	i8 bpp = 0;

protected:
	i32 pixelSize = 0;
	i32 lineSize = 0;
	i32 fbSize = 0;

protected:
	u8 *fb = nullptr;
	u8 **fbX = nullptr;

public:
	FrameBuffer();

public:
	FrameBuffer(i32 w, i32 h, i32 bpp);
	FrameBuffer(u8 *fb, i32 w, i32 h, i32 bpp);

public:
	i32 getWidth();
	i32 getHeight();

	void getSize(i32 &w, i32 &h);

public:
	i32 getBpp();

public:
	const u8* getFb();

public:
	bool check_off(i32 off);
	bool check_lineOff(i32 lineOff);
	bool check_x(i32 x);
	bool check_y(i32 y);

protected:
	u8* unchecked_getOff(i32 off);

public:
	u8* getOff(i32 off);

protected:
	u8 unchecked_readByte(i32 off);
	void unchecked_writeByte(i32 off, u8 value);

public:
	u8 readByte(i32 off);
	void writeByte(i32 off, u8 value);

protected:
	u8 unchecked_readByte(i32 lineOff, i32 y);
	void unchecked_writeByte(i32 lineOff, i32 y, u8 value);

public:
	u8 readByte(i32 lineOff, i32 y);
	void writeByte(i32 lineOff, i32 y, u8 value);

protected:
	color_t unchecked_readPixel(i32 x, i32 y);
	void unchecked_writePixel(i32 x, i32 y, color_t color);

public:
	color_t readPixel(i32 x, i32 y);
	void writePixel(i32 x, i32 y, color_t color);

protected:
	void unchecked_writeRow(i32 x0, i32 y0, i32 w, color_t color);
	void unchecked_writeCol(i32 x0, i32 y0, i32 h, color_t color);
	void unchecked_writeRect(i32 x0, i32 y0, i32 w, i32 h, color_t color);

public:
	void writeRow(i32 x0, i32 y0, i32 w, color_t color);
	void writeCol(i32 x0, i32 y0, i32 h, color_t color);
	void writeRect(i32 x0, i32 y0, i32 w, i32 h, color_t color);

public:
	void clear(color_t color);

protected:
	void unchecked_copyFrom(FrameBuffer *other, i32 x0, i32 y0, i32 w, i32 h, i32 x1, i32 y1);
	void unchecked_copyFrom(FrameBuffer *other);

public:
	void copyFrom(FrameBuffer *other, i32 x0, i32 y0, i32 w, i32 h, i32 x1, i32 y1);
	void copyFrom(FrameBuffer *other);

};

}
}

