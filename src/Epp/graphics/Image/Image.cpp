#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace graphics {

const Class *Image::ClassInfo = Class::Register<Image, Layer>("Epp::graphics::Image", nullptr);

Image::Image() {

}

Image::~Image() {

}

Image::Image(i32 w, i32 h, Color::Type colorType) :
		Image(nullptr, w, h, colorType) {
}

Image::Image(u8 *fb, i32 w, i32 h, Color::Type colorType) :
		Layer(fb, w, h, colorType, Rot_0) {

}

}
}
