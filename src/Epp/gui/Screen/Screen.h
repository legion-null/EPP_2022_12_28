#pragma once

#include "graphics/Layer/Layer.h"

#include "graphics/Color/Color.h"

namespace Epp {
namespace gui {

class Screen: extends graphics::Layer {

EPP_CLASS_INFO

protected:
	Layer *display = nullptr;

public:
	Screen();

public:
	Screen(i32 w, i32 h, graphics::Color::Type colorType, graphics::Rot rot);

public:
	virtual void refreshRect(i32 x0, i32 y0, i32 w, i32 h);
	virtual void refresh();

public:
	virtual void test();

};

}
}

