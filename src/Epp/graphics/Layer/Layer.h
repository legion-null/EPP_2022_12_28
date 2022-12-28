#pragma once

#include "graphics/graphics.hpp"
#include "graphics/FrameBuffer/FrameBuffer.h"

E_init

namespace Epp {
namespace graphics {

E_import_class(Color)

class Layer: extends FrameBuffer {

E_CLASS_DEC(Layer,FrameBuffer)

protected:
	Rot rot = Rot_0;
	Color::Type colorType = Color::ARGB8888;

public:
	Layer();
	virtual void destroy() override;

public:
	Layer(i32 w, i32 h, Color::Type colorType, Rot rot);

private:
	using FrameBuffer::readPixel;
	using FrameBuffer::writePixel;
	using FrameBuffer::writeRow;
	using FrameBuffer::writeCol;
	using FrameBuffer::writeRect;

public:
	Rot getRot();

public:
	void mapPixel(i32 &x, i32 &y);
	void rMapPixel(i32 &x, i32 &y);

public:
	EColor getPixel(i32 x, i32 y);
	void setPixel(i32 x, i32 y, EColor color);

public:
	void drawLineH(i32 x0, i32 y0, i32 w, EColor color);
	void drawLineV(i32 x0, i32 y0, i32 h, EColor color);

	void fillRect(i32 x0, i32 y0, i32 w, i32 h, EColor color);

public:
	void clear(EColor color);
};

E_class(Layer)

}
}

