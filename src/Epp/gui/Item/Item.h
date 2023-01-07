#pragma once

#include "base/Object/Object.h"
#include "graphics/Rect2D/Rect2D.h"

namespace Epp {
namespace graphics {
}
namespace gui {

class UI;

class Item: virtual public Epp::base::Object, virtual public graphics::Rect2D {

EPP_CLASS_INFO

protected:
	Item *parent = nullptr;

protected:
	UI *ui = nullptr;

public:
	Item();
	virtual ~Item();

public:
	Item(i32 x, i32 y, i32 w, i32 h);

public:
	virtual void setX(i32 x) override;
	virtual void setY(i32 y) override;
	virtual void setPos2D(i32 x, i32 y) override;

public:
	virtual void setW(i32 w) override;
	virtual void setH(i32 h) override;
	virtual void setSize2D(i32 w, i32 h) override;

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

#include "AbstractButton/AbstractButton.h"
#include "PushButton/PushButton.h"
