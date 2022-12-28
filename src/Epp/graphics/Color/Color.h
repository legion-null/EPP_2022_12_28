#pragma once

#include "base/Object/Object.h"

E_init

namespace Epp {
namespace graphics {

class Color: extends base::Object {

E_CLASS_DEC(Color,base::Object)

public:
	enum TypicalColor : i32 {
		BLACK = 0x000000,	// 黑色
		WHITE = 0xFFFFFF,	// 白色
		RED = 0xFF0000,		// 红色
		GREEN = 0x00FF00,	// 绿色
		BLUE = 0x0000FF,	// 蓝色
		CYAN = 0x00FFFF,	// 青色
		FUCHSIA = 0xFF00FF,	// 紫红色
		YELLOW = 0xFFFF00,	// 黄色
	};

public:
	enum Type : i8 {
		RGB565 = 0,		// RGB565
		RGB888 = 1,		// RGB888
		ARGB8888 = 2,	// ARGB8888
	};

public:
	static i32 GetBPP(Type type);

protected:
	struct RGB565 {
		u16 __padding;
		u32 r :5;
		u32 g :6;
		u32 b :5;
	};

	struct RGB888 {
		u8 __padding;
		u8 r;
		u8 g;
		u8 b;
	};

	struct ARGB8888 {
		u8 a;
		u8 r;
		u8 g;
		u8 b;
	};

protected:
	union ColorValue {
		i32 value;
		struct RGB565 rgb565;
		struct RGB888 rgb888;
		struct ARGB8888 argb8888;
	};

public:
	static i32 ToARGB8888(i32 , Type src);
	static i32 FormARGB8888(i32 , Type dest);
	static i32 Transform(i32 , Type src, Type dest);

protected:
	union ColorValue value;

public:
	Color();
	virtual void destroy() override;

public:
	Color(i32 value);
	Color(i32 R, i32 G, i32 B);
	Color(i32 A, i32 R, i32 G, i32 B);
	Color(f32 r, f32 g, f32 b);
	Color(f32 a, f32 r, f32 g, f32 b);

	Color(i32 value,Type src);

public:
	i32 getValue();

public:
	i32 getA();
	i32 getR();
	i32 getG();
	i32 getB();

	void getARGB(i32 &A, i32 &R, i32 &G, i32 &B);
	void getRGB(i32 &R, i32 &G, i32 &B);

public:
	f32 getAF();
	f32 getRF();
	f32 getGF();
	f32 getBF();

	void getARGBF(f32 &a, f32 &r, f32 &g, f32 &b);
	void getRGBF(f32 &r, f32 &g, f32 &b);

public:
	virtual EColor clone() override;
};

E_class(Color)

}
}

