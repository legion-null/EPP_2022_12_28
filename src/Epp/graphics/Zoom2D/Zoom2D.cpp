#include "Epp.h"

using namespace Epp::graphics;

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace graphics {

const Class *Zoom2D::ClassInfo = Class::Register<Zoom2D, Interface>("Epp::graphics::Zoom2D", nullptr);

const c8* Zoom2D::GetEnumName(Type e) {
	switch (e) {
	case Pixel:
		return EPP_STR(Pixel);
	case Physics:
		return EPP_STR(Physics);
	case Visual:
		return EPP_STR(Visual);
	default:
		return "Null";
	}
}

f32 Zoom2D::DefaultZoomX = 1.0;
f32 Zoom2D::DefaultZoomY = 1.0;

void Zoom2D::SetDefaultZoom(f32 zoomX, f32 zoomY) {
	DefaultZoomX = zoomX;
	DefaultZoomY = zoomY;
}

void Zoom2D::SetDefaultZoom(const gui::Screen &screen, Type type) {
	switch (type) {
	case Pixel: {
		return SetDefaultZoom(1.0, 1.0);
	}
	case Physics: {
		f32 hppm = screen.getHPPM();	// 横向每毫米像素数量
		f32 vppm = screen.getVPPM();	// 纵向每毫米像素数量

		return SetDefaultZoom(hppm, vppm);
	}
	case Visual: {
		f32 hppm = screen.getHPPM();	// 横向每毫米像素数量
		f32 vppm = screen.getVPPM();	// 纵向每毫米像素数量
		f32 slightDistance = screen.getSlightDistance();	// 人眼视距

		// 默认定义视效尺寸为相当于人眼55cm外的物理尺寸
		return SetDefaultZoom(hppm / (slightDistance / 550), hppm / (slightDistance / 550));
	}
	}
}

bool Zoom2D::isUsingOwnZoom() const {
	return this->usingOwnZoom;
}

void Zoom2D::setUsingOwnZoom(bool b) {
	this->usingOwnZoom = b;
}

f32 Zoom2D::getZoomX() const {
	if (Zoom2D::isUsingOwnZoom() == false) {
		return DefaultZoomX;
	} else {
		return this->zoomX;
	}
}

f32 Zoom2D::getZoomY() const {
	if (Zoom2D::isUsingOwnZoom() == false) {
		return DefaultZoomY;
	} else {
		return this->zoomY;
	}
}

void Zoom2D::setZoomX(f32 zoomX) {
	this->zoomX = zoomX;
}

void Zoom2D::setZoomY(f32 zoomY) {
	this->zoomY = zoomY;
}

void Zoom2D::setZoom(f32 zoomX, f32 zommY) {
	Zoom2D::setZoomX(zoomX);
	Zoom2D::setZoomY(zoomY);
}

void Zoom2D::setZoom(f32 zoom) {
	Zoom2D::setZoomX(zoom);
	Zoom2D::setZoomY(zoom);
}

}
}
