#pragma once

#include "gui/InputEvent/InputEvent.h"

namespace Epp {
namespace gui {

class KeyBoardEvent: public InputEvent {

EPP_CLASS_INFO

public:
	KeyBoardEvent();
	virtual ~KeyBoardEvent();

};

}
}

