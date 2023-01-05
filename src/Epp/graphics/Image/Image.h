#pragma once

#include "graphics/Layer/Layer.h"

namespace Epp {
namespace graphics {

class Image: public Layer {

EPP_CLASS_INFO

public:
	Image();
	~Image();

public:
	Image(i32 w, i32 h, Color::Type colorType);
	Image(u8 *fb, i32 w, i32 h, Color::Type colorType);

private:
	using Layer::rot;
	using Layer::mapPixel;
	using Layer::rMapPixel;
	using Layer::getRot;

};

}
}

