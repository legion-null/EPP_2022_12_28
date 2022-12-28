#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace graphics {

void MapPixel(i32 &x, i32 &y, i32 &w, i32 &h, Rot rot){
	return iMapPixel(x, y, w, h, rot);
}

void RMapPixel(i32 &x, i32 &y, i32 &w, i32 &h, Rot rot){
	return iRMapPixel(x, y, w, h, rot);
}

}
}
