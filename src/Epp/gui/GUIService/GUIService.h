#pragma once

#include "base/Object/Object.h"

E_init

namespace Epp {
namespace gui {

class GUIService: extends base::Object {

E_CLASS_DEC(GUIService,base::Object)

public:
	enum Type : i8 {
		LinuxFB = 0,	// LinuxFB
		SDL2 = 1,		// SDL2
		X11 = 2,		// X11
		Android = 3,	// Android
		Windows = 4,	// Windows
		MacOS = 5,		// MacOS
	};

public:
	GUIService();

};

E_class(GUIService)

}
}

