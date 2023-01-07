#include "Epp.h"

using namespace Epp::graphics;

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace graphics {

const Class *Rect2D::ClassInfo = Class::Register<Rect2D, Object>("Epp::graphics::Rect2D", nullptr);

void Rect2D::getRect2D(i32 &x, i32 &y, i32 &w, i32 &h) const {
	Pos2D::getPos2D(x, y);
	Size2D::getSize2D(w, h);
}

void Rect2D::setRect2D(i32 x, i32 y, i32 w, i32 h) {
	Pos2D::setPos2D(x, y);
	Size2D::setSize2D(w, h);
}

}
}
