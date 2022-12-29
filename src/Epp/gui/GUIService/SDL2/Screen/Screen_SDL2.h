#pragma once

#include "gui/Screen/Screen.h"

#ifdef USE_LIB_SDL2

E_init

namespace Epp {
namespace gui {

class Screen_SDL2: extends Screen {

E_CLASS_DEC(Screen_SDL2,Screen)

protected:
	base::EString title = nullptr;

protected:
	struct CSDL2 *csdl2 = nullptr;

public:
	Screen_SDL2();
	virtual void destroy() override;

public:
	Screen_SDL2(i32 w, i32 h, graphics::Color::Type colorType, graphics::Rot rot);
	Screen_SDL2(base::EString title, i32 w, i32 h, graphics::Color::Type colorType, graphics::Rot rot);

public:
	virtual void refreshRect(i32 x0, i32 y0, i32 w, i32 h) override;
	virtual void refresh() override;

};

E_class(Screen_SDL2)

}
}

#endif
