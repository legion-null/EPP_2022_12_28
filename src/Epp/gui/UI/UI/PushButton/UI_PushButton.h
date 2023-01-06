#pragma once

#include "gui/UI/UI/AbstractButton/UI_AbstractButton.h"

namespace Epp {
namespace gui {

class PushButton;

class UI_PushButton: public UI_AbstractButton {

EPP_CLASS_INFO

protected:
	PushButton *&item = (PushButton*&) UI_AbstractButton::item;

public:
	UI_PushButton();
	virtual ~UI_PushButton();

};

}
}

