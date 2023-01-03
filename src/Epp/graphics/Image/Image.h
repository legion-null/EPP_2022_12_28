#pragma once

#include "graphics/Layer/Layer.h"

namespace Epp {
namespace graphics {

class Image: extends Layer {

EPP_CLASS_INFO

public:
	Image();
	~Image();

public:
	Image(i32 w, i32 h, Color::Type colorType);
	Image(byte *fb, i32 w, i32 h, Color::Type colorType);

private:
	using Layer::rot;
	using Layer::mapPixel;
	using Layer::rMapPixel;
	using Layer::getRot;

};

}
}

