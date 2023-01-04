#pragma once

#include "graphics/graphics/graphics.hpp"

#include "graphics/FrameBuffer/FrameBuffer.h"

#include "graphics/Color/Color.h"

namespace Epp {
namespace graphics {

class Painter;

class Layer: public FrameBuffer {

EPP_CLASS_INFO

protected:
	Color::Type colorType = Color::XRGB8888;
	Rot rot = Rot_0;

public:
	Layer();

public:
	Layer(i32 w, i32 h, Color::Type colorType);
	Layer(i32 w, i32 h, Color::Type colorType, Rot rot);
	Layer(byte *fb, i32 w, i32 h, Color::Type colorType, Rot rot);

private:
	using FrameBuffer::readPixel;
	using FrameBuffer::writePixel;
	using FrameBuffer::writeRow;
	using FrameBuffer::writeCol;
	using FrameBuffer::writeRect;
	using FrameBuffer::clear;

public:
	Rot getRot();

public:
	void mapPixel(i32 &x, i32 &y);
	void rMapPixel(i32 &x, i32 &y);

public:
	Color* getPixel(i32 x, i32 y);
	void setPixel(i32 x, i32 y, Color *color);

public:
	void drawLineH(i32 x0, i32 y0, i32 w, Color *color);
	void drawLineV(i32 x0, i32 y0, i32 h, Color *color);

	void fillRect(i32 x0, i32 y0, i32 w, i32 h, Color *color);

public:
	void clear(Color *color);

protected:
	void unchecked_copyFrom(Layer *other, i32 x0, i32 y0, i32 w, i32 h, i32 x1, i32 y1);
	void unchecked_copyFrom(Layer *other);

public:
	void copyFrom(Layer *other, i32 x0, i32 y0, i32 w, i32 h, i32 x1, i32 y1);
	void copyFrom(Layer *other);

public:
	Painter* getPainter();
};

}
}

