#pragma once

#include "base/Object/Object.h"

namespace Epp {
namespace graphics {

class Image;

class Font: extends base::Object {

EPP_CLASS_INFO

public:
	enum Type : i8 {
		SDF = 0,		// 简单矩阵字体
		CDF,			// 代码点阵字体
		BDF,			// 点阵字体
		TTF,			// TTF字体
		OTF,			// OTF字体
	};

protected:
	// 这里放一张字体表，字体加载到字体表中才可以使用

protected:
	bool bitmapFont = true; // 点阵字体

public:
	Font();

public:
	virtual Image* getCharacterImage(i32 c);

public:
	virtual Font* clone() override;

};

}
}

