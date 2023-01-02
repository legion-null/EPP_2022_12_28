#pragma once

#include "gui/Screen/Screen.h"

#if EPP_MODULE_X11_SUPPORT == EPP_TRUE

namespace Epp {
namespace gui {

class Screen_X11: extends Screen {

EPP_CLASS_INFO

protected:
	base::String *title = nullptr;

protected:
	struct CX11 *cx11 = nullptr;

public:
	Screen_X11();

public:
	Screen_X11(i32 w, i32 h, graphics::Color::Type colorType, graphics::Rot rot);
	Screen_X11(base::String *title, i32 w, i32 h, graphics::Color::Type colorType, graphics::Rot rot);

public:
	virtual void setTitle(base::String *title);

public:
	virtual void refresh() override;
	virtual void refreshRect(i32 x0, i32 y0, i32 w, i32 h) override;

};

}
}

#endif
