#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace graphics {

const base::Class *Painter::ClassInfo = base::Class::Register<Painter, base::Object>("Epp::graphics::Painter", nullptr);

Painter::Painter() {
	this->color = new Color();
	this->font = new Font();
}

Painter::Painter(Layer *layer) {
	this->layer = layer;
}

const Layer* Painter::getLayer() const {
	return this->layer;
}

void Painter::setLayer(Layer *layer) {
	this->layer = layer;
}

Color* Painter::getColor() {
	return this->color->clone();
}

void Painter::setColor(Color *color) {
	SafeDestroy(this->color);
	this->color = color->clone();
}

Font* Painter::getFont() {
	return this->font->clone();
}

void Painter::setFont(Font *font) {
	SafeDestroy(this->font);
	this->font = font->clone();
}

void Painter::drawPixel(i32 x, i32 y) {
	return this->layer->setPixel(x, y, this->color);
}

Color* Painter::getPixel(i32 x, i32 y) {
	return this->layer->getPixel(x, y);
}

void Painter::drawCharacter(i32 x, i32 y, i32 w, i32 h, i32 c) {
}

void Painter::drawCharacter(Rect2D *limitBox, i32 c) {
}

void Painter::drawString(i32 x, i32 y, i32 w, i32 h, base::String *str) {
}

void Painter::drawString(Rect2D *limitBox, base::String *str) {
}

void Painter::drawImage(i32 x, i32 y, i32 w, i32 h, Image *img) {
}

void Painter::drawImage(Rect2D *limitBox, Image *img) {
}

}
}
