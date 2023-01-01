#pragma once

#include "graphics/Font/Font.h"

E_init

namespace Epp {
namespace graphics {

class Font_SMF: extends Font {

E_CLASS_DEC(Font_SMF,Font)

public:
	Font_SMF();
	virtual void destroy() override;

};

E_class(Font_SMF)

}
}

