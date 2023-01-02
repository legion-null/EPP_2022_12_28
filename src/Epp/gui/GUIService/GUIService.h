#pragma once

#include "base/Object/Object.h"

namespace Epp {
namespace gui {

class GUIService: extends base::Object {

EPP_CLASS_INFO

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

}
}

#include "SDL2/GUIService_SDL2.h"
//#include "X11/GUIService_X11.h"
#include "Android/GUIService_Android.h"

