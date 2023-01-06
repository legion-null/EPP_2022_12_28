#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace graphics {

const Class *Font::ClassInfo = Class::Register<Font, Object>("Epp::graphics::Font", nullptr);

const c8* Font::GetEnumName(Type e) {
	switch (e) {
	case SMF:
		return EPP_STR(SMF);
	case CMF:
		return EPP_STR(CMF);
	case BDF:
		return EPP_STR(BDF);
	case TTF:
		return EPP_STR(TTF);
	case OTF:
		return EPP_STR(OTF);
	default:
		throw new Exception("Careless forced transformation");
	}
}

Font::Font() {

}

Font::~Font() {
}

Font::Font(const base::String path) {
	(void) path;
}

bool Font::hasCharacter(i32 c) {
	(void) c;
	return false;
}

Image* Font::getUnavailableCharacterImage(i32 c) {
	EPP_FUNC_LOCATE("%d", c);

	if (getW() < 0 or getH() < 0) {
		throw new Exception();
	}

	// 创建一个图像
	Image *img = new Image(getW(), getH(), Color::GetDefaultColorType());
	Painter *painter = img->getPainter();

	// 填充白色
	painter->setColor(C(White));
	painter->fillRect(0, 0, getW(), getH());

	// 绘制边框（两层）
	painter->setColor(C(Black));

	if (getW() >= 11 and getH() >= 15) {
		painter->drawRect(0, 0, getW(), getH());
	} else {
		painter->drawRect(0, 0, getW(), getH());
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
