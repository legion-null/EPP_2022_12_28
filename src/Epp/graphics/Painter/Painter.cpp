#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace graphics {

E_CLASS_DEF(Epp::graphics::Painter)

void Painter::Static() { // 静态块，类初始化时将会执行块内代码，为了防止Epp类型构建系统出错，静态块内的代码必须与类型加载顺序无关

}

Painter::Painter() {
	this->color = new Color();
	this->font = new Font();
}

void Painter::destroy() {
	SafeDestroy(this->color);
	SafeDestroy(this->font);

	delete this;
}

Painter::Painter(ELayer layer) {
	this->layer = layer;
}

const ELayer Painter::getLayer() const {
	return this->layer;
}

void Painter::setLayer(ELayer layer) {
	this->layer = layer;
}

EColor Painter::getColor() {
	return this->color->clone();
}

void Painter::setColor(EColor color) {
	SafeDestroy(this->color);
	this->color = color->clone();
}

EFont Painter::getFont() {
	return this->font->clone();
}

void Painter::setFont(EFont font) {
	SafeDestroy(this->font);
	this->font = font->clone();
}

void Painter::drawPixel(i32 x, i32 y) {
	return this->layer->setPixel(x, y, this->color);
}

EColor Painter::getPixel(i32 x, i32 y) {
	return this->layer->getPixel(x, y);
}

void Painter::drawCharacter(i32 x, i32 y, i32 w, i32 h, i32 c) {
}

void Painter::drawCharacter(ERect2D limitBox, i32 c) {
}

void Painter::drawString(i32 x, i32 y, i32 w, i32 h, base::EString str) {
}

void Painter::drawString(ERect2D limitBox, base::EString str) {
}

void Painter::drawImage(i32 x, i32 y, i32 w, i32 h, EImage img) {
}

void Painter::drawImage(ERect2D limitBox, EImage img) {
}

}
}
