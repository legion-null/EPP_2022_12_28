#pragma once

#include "gui/Item/Item.h"

namespace Epp {
namespace gui {

class UI_AbstractButton;

class AbstractPushButton: public Item {

EPP_CLASS_INFO

protected:
	UI_AbstractButton *&ui = (UI_AbstractButton*&) Item::ui;

public:
	AbstractPushButton();
	virtual ~AbstractPushButton();

};

}
}

