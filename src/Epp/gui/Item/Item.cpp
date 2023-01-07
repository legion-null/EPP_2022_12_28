#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

using namespace Epp::graphics;

namespace Epp {
namespace gui {

const Class *Item::ClassInfo = Class::Register<Item, Object>("Epp::gui::Item", nullptr);

Item::Item() {

}

Item::~Item() {
}

Item::Item(i32 x, i32 y, i32 w, i32 h) {
	setRect2D(x, y, w, h);
}

void Item::setX(i32 x) {
	Rect2D::setX(x);
}

void Item::setY(i32 y) {
	Rect2D::setY(y);
}

void Item::setPos2D(i32 x, i32 y) {
	Rect2D::setPos2D(x, y);
}

void Item::setW(i32 w) {
	Rect2D::setW(w);
}

void Item::setH(i32 h) {
	Rect2D::setH(h);
}

void Item::setSize2D(i32 w, i32 h) {
	Rect2D::setSize2D(w, h);
}

Item* Item::getParent() {
	return this->parent;
}

void Item::setParent(Item *parent) {
	this->parent = parent;
}

i32 Item::getAbsX() {
	i32 absX = 0;
	for (Item *item = this; item != nullptr;) {
		absX = absX + getX();
		item = item->parent;
	}
	return absX;
}

i32 Item::getAbsY() {
	i32 absY = 0;
	for (Item *item = this; item != nullptr;) {
		absY = absY + getY();
		item = item->parent;
	}
	return absY;
}

void Item::getAbsPos(i32 &absX, i32 &absY) {
	absX = 0;
	absY = 0;
	for (Item *item = this; item != nullptr;) {
		absX = absX + getX();
		absY = absY + getY();
		item = item->parent;
	}
}

void Item::paint(Painter *painter) {
	(void) painter;
}

}
}
