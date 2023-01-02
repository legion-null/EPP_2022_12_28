#pragma once

#include "base/Object/Object.h"


namespace Epp {
namespace graphics {

class Font: extends base::Object {

EPP_CLASS_INFO

public:
	enum Type : i8 {
		SimpleMatrix = 0,	// 简单矩阵字体
		BDF = 1,			// BDF字体
		TTF = 2,			// TTF字体
		OTF = 3,			// OTF字体
	};

protected:
	// 这里放一张字体表，字体加载到字体表中才可以使用

public:
	Font();
	

public:
	virtual Font* clone() override;

};


}
}

#include "CMF/Font_CMF.h"
#include "SMF/Font_SMF.h"

