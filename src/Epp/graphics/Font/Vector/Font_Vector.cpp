#include "Epp.h"

#include "About_FreeType2.h"

using namespace Epp::graphics;

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace graphics {

const Class *Font_Vector::ClassInfo = Class::Register<Font_Vector, Font>("Epp::graphics::Font_Vector", nullptr);

Font_Vector::Font_Vector() {

}

Font_Vector::~Font_Vector() {

}

}
}
