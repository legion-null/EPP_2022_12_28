#pragma once

#include "graphics/Font/Font.h"

namespace Epp {
namespace graphics {

class Font_Vector: public Font {

EPP_CLASS_INFO

public:
	Font_Vector();
	virtual ~Font_Vector();

};

}
}

#include "TTF/Font_TTF.h"

