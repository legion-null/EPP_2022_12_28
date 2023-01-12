#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace graphics {

const Class *Painter::ClassInfo = Class::Register<Painter, Object>("Epp::graphics::Painter", nullptr);

const c8* Painter::GetEnumType(IMType e) {
	switch (e) {
	case OpenGL:
		return EPP_STR(OpenGL);
	case Software:
		return EPP_STR(Software);
	default:
		throw new Exception("Careless forced transformation");
	}
}

const bool Painter::ValidityOfIM[NumberOfIM] = { //
		(EPP_MODULE_OPENGL_SUPPORT == EPP_TRUE),	// OpenGL渲染为可选模块
				true,	// 软件渲染永远可用
		};

bool Painter::IsAvailable(IMType type) {
	return ValidityOfIM[type];
}

Painter::IMType Painter::DefaultIMType = Painter::InitDefaultIMType();

Painter::IMType Painter::InitDefaultIMType() {
	for (i32 i = 0; i < NumberOfIM; i++) {
		if (ValidityOfIM[i] == true)
			return (IMType) i;
	}

	return IMType::Software;
}

Painter::IMType Painter::GetDefaultIMType() {
	return DefaultIMType;
}

void Painter::SetDefaultIMType(IMType type) {
	if (IsAvailable(type) == false) {
		throw new Exception();
	}

	DefaultIMType = type;
}

Painter* Painter::GetIM(IMType type) {
	EPP_CODE_LOCATE();

	if (IsAvailable(type) == false) {
		throw new Exception();
	}

	switch (type) {
	case OpenGL:
#if EPP_MODULE_OPENGL_SUPPORT == EPP_TRUE
		//return new Painter_OpenGL();
#endif
		break;
	case Software:
		return new Painter_Software();
	}

	throw new Exception();
}

Painter* Painter::GetDefaultIM() {
	return GetIM(GetDefaultIMType());
}

Painter::Painter() {

}

Painter::Painter(const Layer *layer) {
	setLayer(layer);
}

const Layer* Painter::getLayer() const {
	return this->layer;
}

void Painter::setLayer(const Layer *layer) {
	this->layer = (Layer*) layer;
}

const Color& Painter::getColor() {
	return *(this->color);
}

void Painter::setColor(const Color &color) {
	SafeDelete(this->color);
	this->color = new Color(color);
}

const Font& Painter::getFont() {
	return *(this->font);
}

void Painter::setFont(const Font &font) {
	SafeDelete(this->font);
	this->font = new Font(font);
}

void Painter::drawPixel(i32 x, i32 y) {
	// EPP_FUNC_LOCATE("%d, %d", x, y);
	return this->layer->setPixel(x, y, this->color);
}

Color* Painter::getPixel(i32 x, i32 y) {
	return this->layer->getPixel(x, y);
}

void Painter::drawCharacter(i32 x, i32 y, i32 w, i32 h, i32 c) {
	EPP_FUNC_LOCATE("%d, %d, %d, %d, %d", x, y, w, h, c);

	Image *charImage = this->font->getCharacterImage(c);

	return drawImage(x, y, Min(w, this->font->getW()), Min(h, this->font->getH()), charImage);
}

void Painter::drawString(i32 x, i32 y, i32 w, i32 h, String *str) {
	EPP_FUNC_LOCATE("%d, %d, %d, %d, %s", x, y, w, h, str->getValue());

	for (u64 i = 0; i < str->getLength(); i++) {
		drawCharacter(x, y, w, h, str->getValue()[i]);
		x = x + this->font->getW();
		if (x + this->font->getW() > w)
			return;
	}
}

void Painter::drawImage(i32 x, i32 y, i32 w, i32 h, Image *img) {
	// EPP_FUNC_LOCATE("%d, %d, %d, %d, 0x%016x", x, y, w, h, img);

	EnsureExists(img);

	this->layer->copyFrom(img, 0, 0, w, h, x, y);
}

}
}
