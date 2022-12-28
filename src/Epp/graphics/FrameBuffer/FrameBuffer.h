#pragma once

#include "base/Object/Object.h"

E_init

namespace Epp {
namespace graphics {

class FrameBuffer: extends base::Object {

E_CLASS_DEC(FrameBuffer,base::Object)

protected:
	i32 w = 0;
	i32 h = 0;
	u8 bpp = 0;

protected:
	i32 lineSize = 0;
	i32 fbSize = 0;

protected:
	bool ownBuf = true;
	u8 *fb = nullptr;
	u8 **fbX = nullptr;

public:
	FrameBuffer();
	virtual void destroy() override;

public:
	FrameBuffer(i32 w, i32 h, i32 bpp);

public:
	void reset(i32 w, i32 h, i32 bpp);

public:
	i32 getWidth();
	i32 getHeight();

	void getSize(i32 &w, i32 &h);

public:
	i32 getBpp();

public:
	i32 readPixel(i32 x, i32 y);
	void writePixel(i32 x, i32 y, i32 color);

public:
	void writeRow(i32 x0, i32 y0, i32 w, i32 color);
	void writeCol(i32 x0, i32 y0, i32 h, i32 color);

	void writeRect(i32 x0, i32 y0, i32 w, i32 h, i32 color);

public:
	void clear(i32 color);

};

E_class(FrameBuffer)

}
}

