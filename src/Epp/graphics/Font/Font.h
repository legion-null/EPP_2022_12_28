#pragma once

#include "base/Object/Object.h"

E_init

namespace Epp {
namespace graphics {

class Font: extends base::Object {

E_CLASS_DEC(Font,base::Object)

public:
	enum Type : i8 {
		SimpleMatrix = 0,	// 简单矩阵字体
		BDF = 1,			// BDF字体
		TTF = 2,			// TTF字体
		OTF = 3,			// OTF字体
	};

private:
	EFont real = nullptr;

public:
	Font();
	virtual void destroy() override;

public:
	virtual EFont clone() override;

};

E_class(Font)

}
}

