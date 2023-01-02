#pragma once

#include "base/Object/Object.h"

namespace Epp {
namespace gui {

class Screen;

class GUIService: extends base::Object {

EPP_CLASS_INFO

public:
	enum Type : i8 {
		Unavailable = -1, // 不可用
		Windows = 0, // Windows
		MacOS,		// MacOS
		Android,	// Android
		IOS,		// IOS
		X11,		// X11
		SDL2,		// SDL2
		LinuxFB,	// LinuxFB
	};

protected:
	static const i32 NumberOfSupportInterfaces = 7;
	static const bool ValidityOfSupportInterfaces[NumberOfSupportInterfaces];

public:
	static bool IsAvailable(Type type);

protected:
	static Type DefaultGuiServiceType;
	static Type InitDefaultGuiServiceType();

public:
	static Type GetDefaultGuiServiceType();
	static void SetDefaultGuiServiceType(Type type);

public:
	static GUIService* GetGUIService(Type type);
	static GUIService* GetDefaultGUIService();

public:
	GUIService();

public:
	virtual Screen* getDefaultScreen() const;
};

}
}

#include "SDL2/GUIService_SDL2.h"
#include "X11/GUIService_X11.h"
#include "Android/GUIService_Android.h"

