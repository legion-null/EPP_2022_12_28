#pragma once

#include "base/Interface/Interface.h"

namespace Epp {
namespace graphics {

class Zoom2D: public base::Interface {

EPP_CLASS_INFO

private:
	f32 zoomX = 1.0;	// 横向缩放系数
	f32 zoomY = 1.0;	// 纵向缩放系数

public:
	f32 getZoomX() const;
	f32 getZoomY() const;

public:
	void setZoomX(f32 zoomX);
	void setZoomY(f32 zoomY);
};

}
}

