#pragma once

#include "graphics/Zoom2D/Zoom2D.h"

namespace Epp {
namespace graphics {

class Size2D: virtual public Zoom2D {

EPP_CLASS_INFO

private:
	i32 w = 0;
	i32 h = 0;

private:
	i32 w_px = 0;
	i32 h_px = 0;

public:
	i32 getW_px() const;
	i32 getH_px() const;

private:
	void setW_px();
	void setH_px();

public:
	i32 getW() const;
	i32 getH() const;

	void getSize2D(i32 &w, i32 &h) const;

public:
	virtual void setW(i32 w);
	virtual void setH(i32 h);

	virtual void setSize2D(i32 w, i32 h);
};

}
}

