#pragma once

#include "Epp.hpp"

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

namespace math {

}
}

