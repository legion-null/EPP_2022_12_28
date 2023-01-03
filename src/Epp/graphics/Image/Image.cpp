#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace graphics {

const base::Class *Image::ClassInfo = base::Class::Register<Image, Layer>("Epp::graphics::Image", nullptr);

Image::Image() {

}

Image::~Image() {

}

Image::Image(byte *fb, i32 w, i32 h, Color::Type colorType) :
		Layer(fb, w, h, colorType, Rot_0) {

}

}
}