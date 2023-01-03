#pragma once

#include "base/Object/Object.h"

namespace Epp {
namespace gui {

class Screen;

class GUIService: extends base::Object {

EPP_CLASS_INFO

public:
	enum IMType : i8 {
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
	static const i32 NumberOfIM = 7;
	static const bool ValidityOfIM[NumberOfIM];

public:
	static bool IsAvailable(IMType type);

protected:
	static IMType DefaultIMType;
	static IMType InitDefaultIMType();

public:
	static IMType GetDefaultIMType();
	static void SetDefaultIMType(IMType type);

public:
	static GUIService* GetIM(IMType type);
	static GUIService* GetDefaultIM();

protected:
	Screen **screenList = nullptr;

public:
	GUIService();

public:
	virtual Screen* getScreen(i32 index) const;
	virtual Screen* getScreen() const;
};

}
}

#include "SDL2/GUIService_SDL2.h"
#include "X11/GUIService_X11.h"
#include "Android/GUIService_Android.h"

