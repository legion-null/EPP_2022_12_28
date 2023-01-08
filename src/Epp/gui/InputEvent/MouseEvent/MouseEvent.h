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

public:
	class State {
	public:
		graphics::Pos2D pos;
		bool leftButtonPressed = false;
		bool middleButtonPressed = false;
		bool rightButtonPressed = false;
		Type type = Type::NoAction;
	};
protected:
	State currentState;

public:
	MouseEvent();
	virtual ~MouseEvent();

public:
	i32 getX() const;
	i32 getY() const;
	void getPos(i32 &x, i32 &y) const;
	const graphics::Pos2D& 获取位置() const;

public:
	bool isLeftButtonPressed() const;
	bool isMiddleButtonPressed() const;
	bool isRightButtonPressed() const;

public:
	Type getEventType() const;
};

}
}

