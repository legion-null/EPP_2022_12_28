#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace graphics {

E_CLASS_DEF(Epp::graphics::Layer)

void Layer::Static() { // 静态块，类初始化时将会执行块内代码，为了防止Epp类型构建系统出错，静态块内的代码必须与类型加载顺序无关

}

Layer::Layer() {

}

void Layer::destroy() {
	delete this;
}

Layer::Layer(i32 w, i32 h, Color::Type colorType, Rot rot) :
		Base(w, h, Color::GetBPP(colorType)) {
	this->rot = rot;
}

Rot Layer::getRot() {
	return this->rot;
}

void Layer::mapPixel(i32 &x, i32 &y) {
	return MapPixel(x, y, this->w, this->h, this->rot);
}

void Layer::rMapPixel(i32 &x, i32 &y) {
	return RMapPixel(x, y, this->w, this->h, this->rot);
}

EColor Layer::getPixel(i32 x, i32 y) {
	rMapPixel(x, y);
	return new Color(Base::readPixel(x, y), this->colorType);
}

void Layer::setPixel(i32 x, i32 y, EColor color) {
	rMapPixel(x, y);
	return Base::writePixel(x, y, color->getValue());
}

void Layer::drawLineH(i32 x0, i32 y0, i32 w, EColor color) {
	rMapPixel(x0, y0);
	switch (this->rot) {
	case Rot::Rot_0:
		return Base::writeRow(x0, y0, w, color->getValue());
	case Rot::Rot_90:
		return Base::writeCol(x0, y0, w, color->getValue());
	case Rot::Rot_180:
		return Base::writeRow(x0, y0, w, color->getValue());
	case Rot::Rot_270:
		return Base::writeCol(x0, y0, w, color->getValue());
	}
}

void Layer::drawLineV(i32 x0, i32 y0, i32 h, EColor color) {
	rMapPixel(x0, y0);
	switch (this->rot) {
	case Rot::Rot_0:
		return Base::writeCol(x0, y0, h, color->getValue());
	case Rot::Rot_90:
		return Base::writeRow(x0, y0, h, color->getValue());
	case Rot::Rot_180:
		return Base::writeCol(x0, y0, h, color->getValue());
	case Rot::Rot_270:
		return Base::writeRow(x0, y0, h, color->getValue());
	}
}

void Layer::fillRect(i32 x0, i32 y0, i32 w, i32 h, EColor color) {
	rMapPixel(x0, y0);
	return Base::writeRect(x0, y0, w, h, color->getValue());
}

void Layer::clear(EColor color) {
	return Base::clear(color->getValue());
}

}
}
