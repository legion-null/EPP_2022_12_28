#pragma once

#include "base/Object/Object.h"
#include "graphics/Color/Color.h"

namespace Epp {
namespace graphics {

class Palette: public base::Object {

EPP_CLASS_INFO

public:
	enum Type : i32 {
		Bit1 = 2,		// 1位调色板
		Bit2 = 4,		// 2位调色板
		Bit4 = 16,		// 4位调色板
		Bit8 = 256,		// 8位调色板
	};

protected:
	Type type = Bit8;
	color_t *colorList = nullptr;

public:
	Palette();
	virtual ~Palette();

public:
	Palette(Type type);

public:
	Color* getColor(u8 index) const;
};

}
}

