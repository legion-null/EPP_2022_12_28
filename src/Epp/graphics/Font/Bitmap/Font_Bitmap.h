#pragma once

#include "graphics/Font/Font.h"

namespace Epp {
namespace graphics {

class Font_Bitmap: public Font {

EPP_CLASS_INFO

public:
	Font_Bitmap();
	~Font_Bitmap();

};

}
}

#include "CMF/Font_CMF.h"
