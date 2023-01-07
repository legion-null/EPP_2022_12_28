#pragma once

#include "base/Event/Event.h"

namespace Epp {
namespace gui {

class InputEvent: public base::Event {

EPP_CLASS_INFO

};

}
}

#include "KeyBoardEvent/KeyBoardEvent.h"
#include "MouseEvent/MouseEvent.h"
#include "TouchPadEvent/TouchPadEvent.h"
