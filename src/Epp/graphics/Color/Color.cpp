#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace graphics {

E_CLASS_DEF(Epp::graphics::Color)

void Color::Static() { // 静态块，类初始化时将会执行块内代码，为了防止Epp类型构建系统出错，静态块内的代码必须与类型加载顺序无关

}

i32 Color::GetBPP(Type type) {
	if (type == RGB565) {
		return 16;
	} else if (type == RGB888) {
		return 24;
	} else if (type == XRGB8888 or type == ARGB8888 or type == RGBX8888 or type == RGBA8888) {
		return 32;
	}

	return 0;
}

i32 Color::ToARGB8888(i32 value, Type src) {
	if (src == ARGB8888)
		return value;

	ColorValue &color = (ColorValue&) value;
	ColorValue ret;

	if (src == RGB565) {
		ret.argb8888.a = 0;
		ret.argb8888.r = color.rgb565.r << 3;
		ret.argb8888.g = color.rgb565.g << 2;
		ret.argb8888.b = color.rgb565.b << 3;
	} else if (src == RGB888) {
		ret.argb8888.a = 0;
		ret.argb8888.r = color.rgb888.r;
		ret.argb8888.g = color.rgb888.g;
		ret.argb8888.b = color.rgb888.b;
	} else if (src == XRGB8888) {
		ret.argb8888.a = 0;
		ret.argb8888.r = color.xrgb8888.r;
		ret.argb8888.g = color.xrgb8888.g;
		ret.argb8888.b = color.xrgb8888.b;
	} else if (src == RGBX8888) {
		ret.argb8888.a = 0;
		ret.argb8888.r = color.rgbx8888.r;
		ret.argb8888.g = color.rgbx8888.g;
		ret.argb8888.b = color.rgbx8888.b;
	} else if (src == RGBA8888) {
		ret.argb8888.a = color.rgba8888.a;
		ret.argb8888.r = color.rgba8888.r;
		ret.argb8888.g = color.rgba8888.g;
		ret.argb8888.b = color.rgba8888.b;
	}

	return ret.value;
}

i32 Color::FormARGB8888(i32 value, Type dest) { // 如果目标格式没有透明度通道，将损失透明度通道
	if (dest == ARGB8888)
		return value;

	ColorValue &color = (ColorValue&) value;
	ColorValue ret;
	if (dest == RGB565) {
		ret.rgb565.r = color.argb8888.r >> 3;
		ret.rgb565.g = color.argb8888.g >> 2;
		ret.rgb565.b = color.argb8888.b >> 3;
	} else if (dest == RGB888) {
		ret.rgb888.r = color.argb8888.r;
		ret.rgb888.g = color.argb8888.g;
		ret.rgb888.b = color.argb8888.b;
	} else if (dest == XRGB8888) {
		ret.xrgb8888.r = color.argb8888.r;
		ret.xrgb8888.g = color.argb8888.g;
		ret.xrgb8888.b = color.argb8888.b;
	} else if (dest == RGBX8888) {
		ret.rgbx8888.r = color.argb8888.r;
		ret.rgbx8888.g = color.argb8888.g;
		ret.rgbx8888.b = color.argb8888.b;
	} else if (dest == RGBA8888) {
		ret.rgba8888.a = color.argb8888.a;
		ret.rgba8888.r = color.argb8888.r;
		ret.rgba8888.g = color.argb8888.g;
		ret.rgba8888.b = color.argb8888.b;
	}

	return ret.value;
}

i32 Color::Transform(i32 value, Type src, Type dest) {
	if (src == dest)
		return value;

	return FormARGB8888(ToARGB8888(value, src), dest);
}

Color::Color() {

}

void Color::destroy() {
	delete this;
}

Color::Color(i32 value) {
	this->value.value = value;
}

Color::Color(i32 R, i32 G, i32 B) :
		Color(((R & 0xff) << 16) | ((G & 0xff) << 8) | ((B & 0xff) << 0)) {
}

Color::Color(i32 A, i32 R, i32 G, i32 B) :
		Color(((A & 0xff) << 24) | ((R & 0xff) << 16) | ((G & 0xff) << 8) | ((B & 0xff) << 0)) {
}

Color::Color(f32 r, f32 g, f32 b) :
		Color((i32) (255 * r), (i32) (255 * g), (i32) (255 * b)) {
}

Color::Color(f32 a, f32 r, f32 g, f32 b) :
		Color((i32) (255 * a), (i32) (255 * r), (i32) (255 * g), (i32) (255 * b)) {
}

Color::Color(i32 value, Type src) :
		Color(ToARGB8888(value, src)) {
}

i32 Color::getValue() {
	return this->value.value;
}

i32 Color::getA() {
	return this->value.argb8888.a;
}

i32 Color::getR() {
	return this->value.argb8888.r;
}

i32 Color::getG() {
	return this->value.argb8888.g;
}

i32 Color::getB() {
	return this->value.argb8888.b;
}

void Color::getARGB(i32 &A, i32 &R, i32 &G, i32 &B) {
	A = getA();
	R = getR();
	G = getG();
	B = getB();
}

void Color::getRGB(i32 &A, i32 &G, i32 &B) {
	A = getR();
	G = getG();
	B = getB();
}

f32 Color::getAF() {
	return getA() / 255.0;
}

f32 Color::getRF() {
	return getR() / 255.0;
}

f32 Color::getGF() {
	return getG() / 255.0;
}

f32 Color::getBF() {
	return getB() / 255.0;
}

void Color::getARGBF(f32 &a, f32 &r, f32 &g, f32 &b) {
	a = getAF();
	r = getRF();
	g = getGF();
	b = getBF();
}

void Color::getRGBF(f32 &r, f32 &g, f32 &b) {
	r = getRF();
	g = getGF();
	b = getBF();
}

Color::EColor Color::clone() {
	return new Color(this->value.value);
}

}
}
