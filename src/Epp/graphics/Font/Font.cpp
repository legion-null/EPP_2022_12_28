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
	if (this->w < 0 or this->h < 0) {
		EPP_CODE_LOCATE();
		EPP_DEBUG("w = %d, h = %d\n", w, h);
		throw new Exception();
	}

	// 创建一个图像
	Image *img = new Image(this->w, this->h, Color::GetDefaultColorType());
	Painter *painter = img->getPainter();

	EPP_CODE_LOCATE();
	EPP_DEBUG("XXX%d\n", 1);
	// 填充白色
	painter->setColor(C(White));
	EPP_DEBUG("XXX%d\n", 2);
	painter->fillRect(0, 0, this->w, this->h);
	EPP_DEBUG("XXX%d\n", 3);

	// 绘制边框（两层）
	painter->setColor(C(Black));

	if (this->w >= 16 and this->h >= 16) {
		painter->drawRect(0, 0, this->w, this->h);
		painter->drawRect(2, 2, this->w - 4, this->h - 4);
	}

	EPP_CODE_LOCATE();

	delete painter;

	return img;
}

Image* Font::getCharacterImage(i32 c) {
	if (hasCharacter(c) == false) {
		EPP_CODE_LOCATE();
		return getUnavailableCharacterImage(c);
	}

	return nullptr;
}

Font* Font::clone() {
	return new Font();
}

}
}
