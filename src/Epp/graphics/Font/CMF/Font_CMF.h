#pragma once

#include "graphics/Font/Font.h"

namespace Epp {
namespace graphics {

class Font_CMF: extends Font {

EPP_CLASS_INFO

public:
	static Font_CMF *FNT_ASCII;

protected: // 这个类没有有效的方法，每种字体都必须拓展一个类
	Font_CMF();

};

}
}

