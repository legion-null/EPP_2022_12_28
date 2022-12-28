#pragma once

#include "graphics/Layer/Layer.h"

E_init

namespace Epp {
namespace gui {

class Screen: extends graphics::Layer {

E_CLASS_DEC(Screen,graphics::Layer)

public:
	Screen();
	virtual void destroy() override;

public:
	Screen(i32 w, i32 h, graphics::Color::Type colorType, graphics::Rot rot);

public:
	virtual void refreshRect(i32 x0, i32 y0, i32 w, i32 h) = 0;
	virtual void refresh();

public:
	virtual void test();

};

E_class(Screen)

}
}

