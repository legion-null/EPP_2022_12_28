#if 0

#pragma once

#include "defs.h"

#if EPP_MODULE_FREETYPE2_SUPPORT == EPP_TRUE

#include <freetype2/ft2build.h>

#include <freetype/freetype.h>

#include <freetype/ftcache.h>
#include <freetype/ftglyph.h>
#include <freetype/ftstroke.h>
#include <freetype/ftbitmap.h>
#include <freetype/fttypes.h>

namespace Epp{
namespace graphics{

struct CFT2{
	FT_Library library;
	FT_Face face;
};

}
}

#endif

#endif
