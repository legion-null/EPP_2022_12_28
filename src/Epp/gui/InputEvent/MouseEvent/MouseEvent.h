#pragma once

#include "gui/InputEvent/InputEvent.h"

namespace Epp {
namespace gui {

class MouseEvent: public InputEvent {

EPP_CLASS_INFO

public:
	enum Type : u8 {
		NoAction,	//
		Move,
		Press,
		Release,
		Click,
		Drag,
		Scroll
	};

public:
	static const c8* GetEnumName(Type e);

protected:
	i32 x = 0;
	i32 y = 0;

	bool leftButtonPressed = false;
	bool middleButtonPressed = false;
	bool rightButtonPressed = false;

	Type type = Type::NoAction;

public:
	MouseEvent();
	virtual ~MouseEvent();

public:
	i32 getX() const;
	i32 getY() const;
	void getPos(i32 &x, i32 &y) const;

public:
	bool isLeftButtonPressed() const;
	bool isMiddleButtonPressed() const;
	bool isRightButtonPressed() const;

public:
	Type getEventType() const;
};

}
}

