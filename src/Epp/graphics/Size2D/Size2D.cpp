#include "Epp.h"

using namespace Epp::graphics;

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace graphics {

const Class *Size2D::ClassInfo = Class::Register<Size2D, Interface>("Epp::graphics::Size2D", nullptr);

i32 Size2D::getW_px() const {
	return this->w_px;
}

i32 Size2D::getH_px() const {
	return this->h_px;
}

void Size2D::setW_px() {
	this->w_px = Zoom2D::getZoomX() * this->w;
}

void Size2D::setH_px() {
	this->h_px = Zoom2D::getZoomY() * this->h;
}

i32 Size2D::getW() const {
	return this->w;
}

i32 Size2D::getH() const {
	return this->h;
}

void Size2D::getSize2D(i32 &w, i32 &h) const {
	w = Size2D::getW();
	h = Size2D::getH();
}

void Size2D::setW(i32 w) {
	this->w = w;
	setW_px();
}

void Size2D::setH(i32 h) {
	this->h = h;
	setH_px();
}

void Size2D::setSize2D(i32 w, i32 h) {
	Size2D::setW(w);
	Size2D::setH(h);
}

}
}
