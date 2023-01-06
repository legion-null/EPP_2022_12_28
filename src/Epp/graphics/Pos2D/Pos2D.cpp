#include "Epp.h"

using namespace Epp::graphics;

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace graphics {

const Class *Pos2D::ClassInfo = Class::Register<Pos2D, Interface>("Epp::graphics::Pos2D", nullptr);

i32 Pos2D::getX_px() const {
	return this->x_px;
}

i32 Pos2D::getY_px() const {
	return this->y_px;
}

void Pos2D::setX_px() {
	this->x_px = Zoom2D::getZoomX() * this->x;
}

void Pos2D::setY_px() {
	this->y_px = Zoom2D::getZoomY() * this->y;
}

i32 Pos2D::getX() const {
	return this->x;
}

i32 Pos2D::getY() const {
	return this->y;
}

void Pos2D::getPos2D(i32 &x, i32 &y) const {
	x = Pos2D::getX();
	y = Pos2D::getY();
}

void Pos2D::setX(i32 x) {
	this->x = x;
	setX_px();
}

void Pos2D::setY(i32 y) {
	this->y = y;
	setY_px();
}

void Pos2D::setPos2D(i32 x, i32 y) {
	Pos2D::setX(x);
	Pos2D::setY(y);
}

}
}
