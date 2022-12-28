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

ELayer Painter::getLayer() {
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
}

EColor Painter::getPixel(i32 x, i32 y) {
	return new Color();
}

void Painter::drawLine(i32 x0, i32 y0, i32 x1, i32 y1) {
}

void Painter::drawRect(i32 x0, i32 y0, i32 w, i32 h) {
}

void Painter::drawTriangle(i32 x0, i32 y0, i32 x1, i32 y1, i32 x2, i32 y2) {
}

void Painter::drawPolyline(i32 *x, i32 *y, i32 n) {
}

void Painter::drawPolygon(i32 *x, i32 *y, i32 n) {
}

void Painter::drawArc(i32 x, i32 y, i32 w, i32 h, i32 startAngle, i32 endAngle) {
}

void Painter::drawArc(i32 x, i32 y, i32 r, i32 startAngle, i32 endAngle) {
}

void Painter::drawSector(i32 x, i32 y, i32 w, i32 h, i32 startAngle, i32 endAngle) {
}

void Painter::drawSector(i32 x, i32 y, i32 r, i32 startAngle, i32 endAngle) {
}

void Painter::drawOval(i32 x, i32 y, i32 w, i32 h) {
}

void Painter::drawCircle(i32 x, i32 y, i32 r) {
}

void Painter::drawRoundedRect(i32 x, i32 y, i32 w, i32 h, i32 r) {
}

void Painter::fillRect(i32 x, i32 y, i32 w, i32 h) {
}

void Painter::fillTriangle(i32 x0, i32 y0, i32 x1, i32 y1, i32 x2, i32 y2) {
}

void Painter::fillPolygon(i32 *x, i32 *y, i32 n) {
}

void Painter::fillSector(i32 x, i32 y, i32 w, i32 h, f64 startAngle, f64 endAngle) {
}

void Painter::fillOval(i32 x, i32 y, i32 w, i32 h) {
}

void Painter::fillCircle(i32 x, i32 y, i32 r) {
}

void Painter::fillRoundedRect(i32 x, i32 y, i32 w, i32 h, i32 r) {
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
