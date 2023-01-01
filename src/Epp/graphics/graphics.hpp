#pragma once

#include "Epp.hpp"

namespace Epp {
namespace graphics {

enum Rot : i16 {
	Rot_0 = 0,		// 顺时针旋转 0 度
	Rot_90 = 90,	// 顺时针旋转 90 度
	Rot_180 = 180,	// 顺时针旋转 180 度
	Rot_270 = 270,	// 顺时针旋转 270 度
};

inline void iMapPixel(i32 &x, i32 &y, i32 &w, i32 &h, Rot rot) {
	i32 x0 = x;
	i32 y0 = y;

	switch (rot) {
	case Rot::Rot_0:
		break;
	case Rot::Rot_90:
		x = y0;
		y = h - 1 - x0;
		break;
	case Rot::Rot_180:
		x = w - 1 - x0;
		y = h - 1 - y0;
		break;
	case Rot::Rot_270:
		x = w - 1 - y0;
		y = x0;
		break;
	}
}

inline void iRMapPixel(i32 &x, i32 &y, i32 &w, i32 &h, Rot rot) {
	i32 x0 = x;
	i32 y0 = y;

	switch (rot) {
	case Rot::Rot_0:
		break;
	case Rot::Rot_90:
		x = h - 1 - y0;
		y = x0;
		break;
	case Rot::Rot_180:
		x = w - 1 - x0;
		y = h - 1 - y0;
		break;
	case Rot::Rot_270:
		x = y0;
		y = w - 1 - x0;
		break;
	}
}

void MapPixel(i32 &x, i32 &y, i32 &w, i32 &h, Rot rot);
void RMapPixel(i32 &x, i32 &y, i32 &w, i32 &h, Rot rot);

}
}

