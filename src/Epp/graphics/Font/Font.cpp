#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace graphics {

const base::Class *Font::ClassInfo = base::Class::Register<Font, base::Object>("Epp::graphics::Font", nullptr);

Font::Font() {

}

Font* Font::clone() {
	return new Font();
}

}
}
