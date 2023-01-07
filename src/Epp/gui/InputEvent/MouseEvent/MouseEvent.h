#pragma once

#include "gui/InputEvent/InputEvent.h"

namespace Epp {
namespace gui {

class MouseEvent: public InputEvent {

EPP_CLASS_INFO

public:
	MouseEvent();
	virtual ~MouseEvent();

};

}
}

