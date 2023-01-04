#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace graphics {

const base::Class *Font::ClassInfo = base::Class::Register<Font, base::Object>("Epp::graphics::Font", nullptr);

Font::Font() {

}

Font::~Font() {
}

i32 Font::getWidth() const {
	return this->w;
}

i32 Font::getHeight() const {
	return this->h;
}

bool Font::hasCharacter(i32 c) {
	return false;
}

Image* Font::getUnavailableCharacterImage(i32 c) {
	EPP_FUNC_LOCATE("%d", c);

	if (this->w < 0 or this->h < 0) {
		throw new Exception();
	}

	// 创建一个图像
	Image *img = new Image(this->w, this->h, Color::GetDefaultColorType());
	Painter *painter = img->getPainter();

	// 填充白色
	painter->setColor(C(White));
	painter->fillRect(0, 0, this->w, this->h);

	// 绘制边框（两层）
	painter->setColor(C(Black));

	if (this->w >= 11 and this->h >= 15) {
		painter->drawRect(0, 0, this->w, this->h);
	} else {
		painter->drawRect(0, 0, this->w, this->h);
//		painter->drawRect(2, 2, this->w - 4, this->h - 4);
//		painter->drawLine(2, 2, this->w - 3, this->h - 3);
//		painter->drawLine(2, this->h - 3, this->w - 3, 2);
	}

	delete painter;

	return img;
}

Image* Font::getCharacterImage(i32 c) {
	EPP_FUNC_LOCATE("%d", c);
	if (hasCharacter(c) == false) {
		return getUnavailableCharacterImage(c);
	}

	return nullptr;
}

Font* Font::clone() {
	return new Font();
}

}
}
