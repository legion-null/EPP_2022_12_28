#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

using namespace Epp::graphics;

namespace Epp {
namespace gui {

const Class *Item::ClassInfo = Class::Register<Item, Object>("Epp::gui::Item", nullptr);

Item::Item() {

}

i32 Item::getX() {
	return this->x;
}

i32 Item::getY() {
	return this->y;
}

void Item::getPos(i32 &x, i32 &y) {
	x = this->x;
	y = this->y;
}

void Item::setX(i32 x) {
	this->x = x;
}

void Item::setY(i32 y) {
	this->y = y;
}

void Item::setPos(i32 x, i32 y) {
	this->x = x;
	this->y = y;
}

i32 Item::getWidth() {
	return this->w;
}

i32 Item::getHeight() {
	return this->h;
}

void Item::getSize(i32 &w, i32 &h) {
	w = this->w;
	h = this->h;
}

void Item::setWidth(i32 w) {
	this->w = w;
}

void Item::setHeight(i32 h) {
	this->h = h;
}

void Item::setSize(i32 w, i32 h) {
	this->w = w;
	this->h = h;
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
		absX = absX + item->x;
		item = item->parent;
	}
	return absX;
}

i32 Item::getAbsY() {
	i32 absY = 0;
	for (Item *item = this; item != nullptr;) {
		absY = absY + item->y;
		item = item->parent;
	}
	return absY;
}

void Item::getAbsPos(i32 &absX, i32 &absY) {
	absX = 0;
	absY = 0;
	for (Item *item = this; item != nullptr;) {
		absX = absX + item->x;
		absY = absY + item->y;
		item = item->parent;
	}
}

void Item::paint(Painter *painter) {
	(void) painter;
}

}
}
