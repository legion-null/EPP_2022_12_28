#pragma once

#include "graphics/Size2D/Size2D.h"

namespace Epp {
namespace graphics {

class Rect2D: virtual public Pos2D, virtual public Size2D {

EPP_CLASS_INFO

public:
	virtual void getRect2D(i32 &x, i32 &y, i32 &w, i32 &h) const;

	virtual void setRect2D(i32 x, i32 y, i32 w, i32 h);

};

}
}

