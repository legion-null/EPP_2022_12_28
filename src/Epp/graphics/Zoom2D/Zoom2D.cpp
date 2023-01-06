#include "Epp.h"

using namespace Epp::graphics;

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace graphics {

const Class *Zoom2D::ClassInfo = Class::Register<Zoom2D, Interface>("Epp::graphics::Zoom2D", nullptr);

f32 Zoom2D::getZoomX() const {
	return this->zoomX;
}

f32 Zoom2D::getZoomY() const {
	return this->zoomY;
}

void Zoom2D::setZoomX(f32 zoomX) {
	this->zoomX = zoomX;
}

void Zoom2D::setZoomY(f32 zoomY) {
	this->zoomY = zoomY;
}

}
}
