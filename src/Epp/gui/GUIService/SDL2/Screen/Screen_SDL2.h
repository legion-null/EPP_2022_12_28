#pragma once

#include "gui/Screen/Screen.h"

#if EPP_MODULE_SDL2_SUPPORT == EPP_TRUE

namespace Epp {
namespace gui {

class Screen_SDL2: public Screen {

EPP_CLASS_INFO

protected:
	base::String *title = nullptr;

protected:
	struct CSDL2 *csdl2 = nullptr;

public:
	Screen_SDL2();

public:
	Screen_SDL2(i32 w, i32 h, graphics::Color::Type colorType, graphics::Rot rot);
	Screen_SDL2(base::String *title, i32 w, i32 h, graphics::Color::Type colorType, graphics::Rot rot);

public:
	virtual void refreshRect(i32 x0, i32 y0, i32 w, i32 h) override;
	virtual void refresh() override;

};

}
}

#endif
