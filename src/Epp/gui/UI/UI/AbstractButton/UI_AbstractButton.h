#pragma once

#include "gui/UI/UI.h"

namespace Epp {
namespace gui {

class AbstractButton;

class UI_AbstractButton: public UI {

EPP_CLASS_INFO

protected:
	AbstractButton *&item = (AbstractButton*&) UI::item;

public:
	UI_AbstractButton();
	virtual ~UI_AbstractButton();

};

}
}

