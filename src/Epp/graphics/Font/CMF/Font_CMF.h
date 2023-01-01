#pragma once

#include "graphics/Font/Font.h"

E_init

namespace Epp {
namespace graphics {

class Font_CMF: extends Font {

E_CLASS_DEC(Font_CMF,Font)

public:
	static EFont_CMF FNT_ASCII;

protected: // 这个类没有有效的方法，每种字体都必须拓展一个类
	Font_CMF();
	virtual void destroy() override;

};

E_class(Font_CMF)

}
}

