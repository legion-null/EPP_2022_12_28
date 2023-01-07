#pragma once

#include "base/Interface/Interface.h"

namespace Epp {
namespace gui {
class Screen;
}
namespace graphics {

class Zoom2D: public base::Interface {

EPP_CLASS_INFO

public:
	enum Type : u8 {
		Pixel,		// 像素对应模式
		Physics,	// 物理对应模式
		Visual,		// 视觉
	};

public:
	static const c8* GetEnumName(Type e);

protected:
	static f32 DefaultZoomX;
	static f32 DefaultZoomY;

public:
	static void SetDefaultZoom(f32 zoomX, f32 zoomY);
	static void SetDefaultZoom(const gui::Screen &screen, Type type);

private:
	f32 zoomX = 1.0;	// 横向缩放系数
	f32 zoomY = 1.0;	// 纵向缩放系数

	bool usingOwnZoom = false;	// 使用私有的缩放

public:
	bool isUsingOwnZoom() const;
	void setUsingOwnZoom(bool b);

public:
	f32 getZoomX() const;
	f32 getZoomY() const;

public:
	void setZoomX(f32 zoomX);
	void setZoomY(f32 zoomY);

public:
	virtual void setZoom(f32 zoomX, f32 zommY);
	virtual void setZoom(f32 zoom);
};

}
}

