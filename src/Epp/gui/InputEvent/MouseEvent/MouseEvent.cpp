#include "Epp.h"

using namespace Epp::gui;

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace gui {

const Class *MouseEvent::ClassInfo = Class::Register<MouseEvent, InputEvent>("Epp::gui::MouseEvent", nullptr);

const c8* MouseEvent::GetEnumName(Type e) {
	switch (e) {
	case NoAction:
		return EPP_STR(NoAction);
	case Move:
		return EPP_STR(Move);
	case Press:
		return EPP_STR(Press);
	case Release:
		return EPP_STR(Release);
	case Click:
		return EPP_STR(Click);
	case Drag:
		return EPP_STR(Drag);
	case Scroll:
		return EPP_STR(Scroll);
	default:
		throw new Exception("Careless forced transformation");
	}
}

MouseEvent::MouseEvent() {

}

MouseEvent::~MouseEvent() {

}

i32 MouseEvent::getX() const {
	return this->x;
}

i32 MouseEvent::getY() const {
	return this->y;
}

void MouseEvent::getPos(i32 &x, i32 &y) const {
	x = getX();
	y = getY();
}

bool MouseEvent::isLeftButtonPressed() const {
	return this->leftButtonPressed;
}

bool MouseEvent::isMiddleButtonPressed() const {
	return this->middleButtonPressed;
}

bool MouseEvent::isRightButtonPressed() const {
	return this->rightButtonPressed;
}

MouseEvent::Type MouseEvent::getEventType() const {
	return this->type;
}

}
}
