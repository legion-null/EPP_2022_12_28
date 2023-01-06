#pragma once

#include "base/Object/Object.h"

#include "graphics/Size2D/Size2D.h"

namespace Epp {
namespace graphics {

class Image;

class Font: virtual public base::Object,virtual public Size2D {

EPP_CLASS_INFO

public:
	enum Type : i8 {
		SMF = 0,		// 简单矩阵字体
		CMF,			// 代码点阵字体
		BDF,			// 点阵字体
		TTF,			// TTF字体
		OTF,			// OTF字体
	};

public:
	static const c8* GetEnumName(Type e);

protected:
	// 这里放一张字体表（链表或哈希表），字体加载到字体表中才可以使用

public:
	Font();
	virtual ~Font();

public:
	Font(const base::String path);

public:
	virtual bool hasCharacter(i32 c);

public:
	virtual Image* getUnavailableCharacterImage(i32 c);
	virtual Image* getCharacterImage(i32 c);

public:
	virtual Font* clone() override;

};

}
}

#include "Bitmap/Font_Bitmap.h"
#include "Vector/Font_Vector.h"

