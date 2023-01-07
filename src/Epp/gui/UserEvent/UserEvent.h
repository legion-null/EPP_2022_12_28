#pragma once

#include "gui/InputEvent/InputEvent.h"

namespace Epp {
namespace gui {

class UserEvent: public InputEvent {

EPP_CLASS_INFO

public:
	UserEvent();
	virtual ~UserEvent();

};

}
}

