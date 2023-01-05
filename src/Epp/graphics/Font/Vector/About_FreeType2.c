#include <freetype2/ft2build.h>
#include FT_FREETYPE_H

#include FT_CACHE_H
#include FT_CACHE_MANAGER_H

#include FT_GLYPH_H
#include FT_STROKER_H
#include FT_BITMAP_H

#include "Epp.h"

void mainnn() {
	FT_Library library;
	FT_Face face;
	FT_Error error;
	FT_UInt charIdx;
	wchar_t wch = 'a';
	char *buffer;		// 用户申请的显示区域空间
	int startX, startY;	// 字符图像开始装入的位置

	(void) error;
	(void) buffer;
	(void) startX;
	(void) startY;

	// 1. 初始化freetype2库
	error = FT_Init_FreeType(&library);

	// 2. 创建一个face
	error = FT_New_Face(library, "C:\\windows\\font\\SURSONG.TTF", 0, &face);

	// 3. 设置字体尺寸
	error = FT_Set_Char_Size(face, 16 * 64, 16 * 64, 96, 96);

	// 4. 获取字符图像索引
	charIdx = FT_Get_Char_Index(face, wch);

	// 5. 加载字符图像
	FT_Load_Glyph(face, charIdx, FT_LOAD_DEFAULT);
	if (face->glyph->format == FT_GLYPH_FORMAT_OUTLINE) {
		FT_Outline_Embolden(&(face->glyph->outline), 16);	// 加粗轮廓线
	}

	// 6. 获取字符位图
	if (face->glyph->format != FT_GLYPH_FORMAT_BITMAP) {
		FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL);
	}

	// 7. 拷贝字符位图到用户的buffer中(用户私人函数)
	// 注意左边的计算方法
}

