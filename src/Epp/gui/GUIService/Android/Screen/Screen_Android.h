#ifdef CURRENT_OS_ANDROID

#pragma once

#include "gui/Screen/Screen.h"

E_init

namespace Epp {
namespace gui {

class Screen_Android: extends Screen {

E_CLASS_DEC(Screen_Android,Screen)

protected:
	base::EString title = nullptr;

protected:
	struct JAndroid *jandroid = nullptr;

public:
	Screen_Android();
	virtual void destroy() override;

public:
	Screen_Android(struct JAndroid *ja, base::EString title, i32 w, i32 h, graphics::Color::Type colorType,	graphics::Rot rot);

public:
	virtual void refreshRect(i32 x0, i32 y0, i32 w, i32 h) override;
	virtual void refresh() override;

};

E_class(Screen_Android)

}
}

#endif
