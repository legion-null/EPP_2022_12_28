#pragma once

#include "base/Object/Object.h"

namespace Epp {
namespace graphics {
}
namespace gui {

class Item: public Epp::base::Object {

EPP_CLASS_INFO

protected:
	i16 x = 0;
	i16 y = 0;
	i16 w = 0;
	i16 h = 0;

protected:

protected:
	Item *parent = nullptr;

public:
	Item();

public:
	i32 getX();
	i32 getY();

	void getPos(i32 &x, i32 &y);

public:
	void setX(i32 x);
	void setY(i32 y);

	void setPos(i32 x, i32 y);

public:
	i32 getWidth();
	i32 getHeight();

	void getSize(i32 &width, i32 &height);

public:
	void setWidth(i32 width);
	void setHeight(i32 height);

	void setSize(i32 width, i32 height);

public:
	Item* getParent();
	void setParent(Item *parent);

public:
	i32 getAbsX();
	i32 getAbsY();

	void getAbsPos(i32 &absX, i32 &absY);

public:
	virtual void paint(graphics::Painter *painter);

};

}
}

