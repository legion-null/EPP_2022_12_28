#pragma once

#include "gui/InputEvent/InputEvent.h"

namespace Epp {
namespace gui {

class TouchPadEvent: public InputEvent {

EPP_CLASS_INFO

public:
	TouchPadEvent();
	virtual ~TouchPadEvent();

};

}
}

