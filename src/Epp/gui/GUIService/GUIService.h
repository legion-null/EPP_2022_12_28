#pragma once

#include "base/Object/Object.h"

namespace Epp {
namespace gui {

class Screen;

class GUIService: public Epp::base::Object {

EPP_CLASS_INFO

public:
	enum IMType : i8 {
		Windows = 0, // Windows
		MacOS,		// MacOS
		Android,	// Android
		IOS,		// IOS
		X11,		// X11
		SDL2,		// SDL2
		LinuxFB,	// LinuxFB
	};

public:
	static const c8* GetEnumName(IMType type);

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
	Screen* getScreen(i32 index) const;
	virtual Screen* getScreen() const;
};

}
}

#include "SDL2/GUIService_SDL2.h"
#include "X11/GUIService_X11.h"
#include "Android/GUIService_Android.h"
#include "Windows/GUIService_Windows.h"

