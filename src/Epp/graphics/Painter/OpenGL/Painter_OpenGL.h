#pragma once

#include "graphics/Painter/Painter.h"

#if EPP_MODULE_OPENGL_SUPPORT == EPP_TRUE

namespace Epp {
namespace graphics {

class Painter_OpenGL: public Painter {

EPP_CLASS_INFO

public:
	Painter_OpenGL();
	virtual ~Painter_OpenGL();

};

}
}

#endif
