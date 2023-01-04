#include "Epp.h"

#if EPP_MODULE_OPENGL_SUPPORT == EPP_TRUE

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace graphics {

const Class *Painter_OpenGL::ClassInfo = Class::Register<Painter_OpenGL, Object>("Epp::graphics::Painter_OpenGL", nullptr);

Painter_OpenGL::Painter_OpenGL() {

}

Painter_OpenGL::~Painter_OpenGL() {

}

}
}

#endif
