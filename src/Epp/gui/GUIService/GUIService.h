#pragma once

#include "base/Object/Object.h"

E_init

namespace Epp {
namespace gui {

class GUIService: extends base::Object {

E_CLASS_DEC(GUIService,base::Object)

public:
	enum Type : i8 {
		LinuxFB,	// LinuxFB
		SDL2,		// SDL2
		X11,		// X11
		Windows,	// Windows
		MacOS,		// MacOS
		Android,	// Android
		IOS,		// IOS
	};

public:
	GUIService();

};

E_class(GUIService)

}
}

#include "SDL2/GUIService_SDL2.h"

#include "Android/GUIService_Android.h"

