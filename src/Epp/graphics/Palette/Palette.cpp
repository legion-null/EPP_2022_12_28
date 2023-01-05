#include "Epp.h"

using namespace Epp::graphics;

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace graphics {

const Class *Palette::ClassInfo = Class::Register<Palette, Object>("Epp::graphics::Palette", nullptr);

Palette::Palette() {

}

Palette::~Palette() {

}

Palette::Palette(Type type) {
	this->type = type;
	this->colorList = nullptr;
}

Color* Palette::getColor(u8 index) const {
	return new Color((color_t) index);
}

}
}
