#pragma once

#include "base/Object/Object.h"

E_init

namespace Epp {
namespace graphics {
E_import_class(Painter)
}
namespace gui {

class Item: extends Epp::base::Object {

E_CLASS_DEC(Item, base::Object)

protected:
	i16 x = 0;
	i16 y = 0;
	i16 w = 0;
	i16 h = 0;

protected:

protected:
	EItem parent = nullptr;

public:
	Item();
	virtual void destroy() override;

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
	EItem getParent();
	void setParent(EItem parent);

public:
	i32 getAbsX();
	i32 getAbsY();

	void getAbsPos(i32 &absX, i32 &absY);

public:
	virtual void paint(graphics::EPainter painter);

};

E_class(Item)

}
}

