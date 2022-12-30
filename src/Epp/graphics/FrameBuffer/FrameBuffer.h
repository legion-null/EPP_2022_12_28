#pragma once

#include "base/Object/Object.h"

E_init

namespace Epp {
namespace graphics {

/*
 * 考虑到FrameBuffer的运行效率在图像显示方面有着重要意义，FrameBuffer类对象的一些成员方法没有对输入进行校验，在继承FrameBuffer时需要
 */

class FrameBuffer: extends base::Object {

E_CLASS_DEC(FrameBuffer,base::Object)

protected:
	i32 w = 0;
	i32 h = 0;
	i8 bpp = 0;

protected:
	i32 pixelSize = 0;
	i32 lineSize = 0;
	i32 fbSize = 0;

protected:
	byte *fb = nullptr;
	byte **fbX = nullptr;

public:
	FrameBuffer();
	virtual void destroy() override;

public:
	FrameBuffer(i32 w, i32 h, i32 bpp);
	FrameBuffer(byte *fb, i32 w, i32 h, i32 bpp);

public:
	i32 getWidth();
	i32 getHeight();

	void getSize(i32 &w, i32 &h);

public:
	i32 getBpp();

public:
	const byte* getFb();

public:
	bool check_off(i32 off);
	bool check_lineOff(i32 lineOff);
	bool check_x(i32 x);
	bool check_y(i32 y);

protected:
	byte* unchecked_getOff(i32 off);

public:
	byte* getOff(i32 off);

protected:
	byte unchecked_readByte(i32 off);
	void unchecked_writeByte(i32 off, byte value);

public:
	byte readByte(i32 off);
	void writeByte(i32 off, byte value);

protected:
	byte unchecked_readByte(i32 lineOff, i32 y);
	void unchecked_writeByte(i32 lineOff, i32 y, byte value);

public:
	byte readByte(i32 lineOff, i32 y);
	void writeByte(i32 lineOff, i32 y, byte value);

protected:
	i32 unchecked_readPixel(i32 x, i32 y);
	void unchecked_writePixel(i32 x, i32 y, i32 value);

public:
	i32 readPixel(i32 x, i32 y);
	void writePixel(i32 x, i32 y, i32 value);

protected:
	void unchecked_writeRow(i32 x0, i32 y0, i32 w, i32 value);
	void unchecked_writeCol(i32 x0, i32 y0, i32 h, i32 value);
	void unchecked_writeRect(i32 x0, i32 y0, i32 w, i32 h, i32 value);

public:
	void writeRow(i32 x0, i32 y0, i32 w, i32 value);
	void writeCol(i32 x0, i32 y0, i32 h, i32 value);
	void writeRect(i32 x0, i32 y0, i32 w, i32 h, i32 value);

public:
	void clear(i32 value);

protected:
	void unchecked_copyFrom(EFrameBuffer other, i32 x0, i32 y0, i32 w, i32 h, i32 x1, i32 y1);
	void unchecked_copyFrom(EFrameBuffer other);

public:
	void copyFrom(EFrameBuffer other, i32 x0, i32 y0, i32 w, i32 h, i32 x1, i32 y1);
	void copyFrom(EFrameBuffer other);

};

E_class(FrameBuffer)

}
}

