#pragma once

#include "gui/GUIService/GUIService.h"

namespace Epp {
namespace gui {

class GUIService_X11: extends GUIService {

EPP_CLASS_INFO

public:
	GUIService_X11();

};

}
}

#include "Screen/Screen_X11.h"
