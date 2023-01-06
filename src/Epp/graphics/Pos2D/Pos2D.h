#pragma once

#include "graphics/Zoom2D/Zoom2D.h"

namespace Epp {
namespace graphics {

class Pos2D: virtual public Zoom2D {

EPP_CLASS_INFO

private:
	i32 x = 0;
	i32 y = 0;

private:
	i32 x_px = 0;
	i32 y_px = 0;

public:
	i32 getX_px() const;
	i32 getY_px() const;

private:
	void setX_px();
	void setY_px();

public:
	i32 getX() const;
	i32 getY() const;
	void getPos2D(i32 &x, i32 &y) const;

public:
	virtual void setX(i32 x);
	virtual void setY(i32 y);
	virtual void setPos2D(i32 x, i32 y);

};

}
}

