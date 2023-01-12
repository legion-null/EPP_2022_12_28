#pragma once

#include "defs.h"

namespace Epp {

template<typename T>
inline T Abs(T a) {
	return a >= 0 ? a : -a;
}

template<typename T>
inline T Diff(T &a, T &b) {
	return Abs(a - b);
}

template<typename T>
inline T Min(T a, T b) {
	return a <= b ? a : b;
}

template<typename T>
inline T Max(T a, T b) {
	return a >= b ? a : b;
}

template<typename T>
inline T Normalized(T &a, T min, T max) {
	if (a <= min) {
		a = min;
	} else if (a >= max) {
		a = max;
	}

	return a;
}

namespace math {

}
}

