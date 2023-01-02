#pragma once

#include "Epp.hpp"

namespace Epp {
namespace graphics {

struct CFont_SMF {
	// 文件头
	u8 magic[4];		// 4位魔数，用来判断文件格式，ASCII"SMFF"
	c8 name[64];		// 字体名称，最多64字节，末尾无需补0
	u8 encoding;		// 编码格式，ASCII、GBK、UniCode等（只支持等宽编码，如在GBK编码，字母也占两字节）
	u8 w;				// 宽度（比例）
	u8 h;				// 高度（比例）
	u8 unit;			// 字号对应的像素，默认为1
	u8 fonts;			// 支持的字号总数
	u8 size[16];		// 支持的字号8-136，如果支持，对应的位为1，否则为0，除非特殊说明，字号默认和像素1比1
	// 地址表
	u32 p1;				// 指向字符范围信息列表，文件中所有指针都是绝对指针
	// 包含字符段
	struct unicode {	// 以unicode为例
		u8 size;		// 字号
		u8 n;			// 有多少段 最大支持256段 段必须正向顺序排列 如 21-90 1312-21412等
		struct __area {
			u32 start;	// 开始编码
			u32 end;	// 结束编码
			u32 p;		// 指向对应的字模数据段
		} area[size];
	};
	// 字模数据段
};

}
}

