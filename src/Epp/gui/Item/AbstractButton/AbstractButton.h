#pragma once

#include "gui/Item/Item.h"

namespace Epp {
namespace gui {

class UI_AbstractButton;

class AbstractButton: public Item {

EPP_CLASS_INFO

protected:
	bool pressed = false;

public:
	AbstractButton();
	virtual ~AbstractButton();

public:
	virtual void doClick();

};

}
}

