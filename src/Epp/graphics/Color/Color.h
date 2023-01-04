#pragma once

#include "base/Object/Object.h"

namespace Epp {
namespace graphics {

// 声明一个新的类型
using color_t = u32;

class Palette;

class Color: public Epp::base::Object {

EPP_CLASS_INFO

public:
	friend class Palette;

public:
	enum Type : i8 {
		// 灰度颜色模式
		Bit1Gray,		// 1位灰度
		Bit2Gray,		// 2位灰度
		Bit4Gray,		// 4位灰度
		Bit8Gray,		// 8位灰度
		// 调色板颜色模式
		Bit1Palette,	// 1位调色板颜色
		Bit2Palette,	// 2位调色板颜色
		Bit3Palette,	// 4位调色板颜色
		Bit4Palette,	// 8位调色板颜色
		// RGB颜色格式
		RGB232,		// RGB232
		RGB555,		// RGB555
		RGB565,		// RGB565
		RGB888,		// RGB888
		XRGB8888,	// XRGB8888
		RGBX8888,	// RGBX8888
		// 具有透明度分量的颜色格式
		ARGB1555,	// ARGB1555
		ARGB8888,	// ARGB8888
		RGBA8888,	// RGBA8888
	};

protected:
	static Type DefaultColorType;

public:
	static Type GetDefaultColorType();
	static void SetDefaultColorType(Type type);

public:
	static const c8* GetEnumName(Type type);

public:
	static i32 GetBPP(Type type);

protected:
	struct RGB565 {
#ifdef EPP_TARGET_ENDIAN_LITTLE
		color_t b :5;
		color_t g :6;
		color_t r :5;
		color_t x :16;
#else
		color_t x:16;
		color_t r :5;
		color_t g :6;
		color_t b :5;
#endif
	} __attribute__((packed));

	struct RGB888 {
#ifdef EPP_TARGET_ENDIAN_LITTLE
		color_t b :8;
		color_t g :8;
		color_t r :8;
		color_t x :8;
#else
		color_t x:8;
		color_t r :8;
		color_t g :8;
		color_t b :8;
#endif
	} __attribute__((packed));

	struct XRGB8888 {
#ifdef EPP_TARGET_ENDIAN_LITTLE
		color_t b :8;
		color_t g :8;
		color_t r :8;
		color_t x :8;
#else
		color_t x:8;
		color_t r :8;
		color_t g :8;
		color_t b :8;
#endif
	} __attribute__((packed));

	struct ARGB8888 {
#ifdef EPP_TARGET_ENDIAN_LITTLE
		color_t b :8;
		color_t g :8;
		color_t r :8;
		color_t a :8;
#else
		color_t a :8;
		color_t r :8;
		color_t g :8;
		color_t b :8;
#endif
	} __attribute__((packed));

	struct RGBX8888 {
#ifdef EPP_TARGET_ENDIAN_LITTLE
		color_t x :8;
		color_t b :8;
		color_t g :8;
		color_t r :8;
#else
		color_t r :8;
		color_t g :8;
		color_t b :8;
		color_t x :8;
#endif
	} __attribute__((packed));

	struct RGBA8888 {
#ifdef EPP_TARGET_ENDIAN_LITTLE
		color_t a :8;
		color_t b :8;
		color_t g :8;
		color_t r :8;
#else
		color_t r :8;
		color_t g :8;
		color_t b :8;
		color_t a :8;
#endif
	} __attribute__((packed));

protected:
	union ColorData {
		struct RGB565 rgb565;
		struct RGB888 rgb888;
		struct XRGB8888 xrgb8888;
		struct RGBX8888 rgbx8888;
		struct ARGB8888 argb8888;
		struct RGBA8888 rgba8888;
		color_t value;
	} __attribute__((packed));

public:
	static color_t ToARGB8888(color_t value, Type src);
	static color_t FormARGB8888(color_t valie, Type dest);
	static color_t Transform(color_t value, Type src, Type dest);

protected:
	union ColorData value;

public:
	Color();

public:
	Color(i32 value);
	Color(i32 R, i32 G, i32 B);
	Color(i32 A, i32 R, i32 G, i32 B);
	Color(f32 r, f32 g, f32 b);
	Color(f32 a, f32 r, f32 g, f32 b);

	Color(i32 value, Type src);

public:
	color_t getValue();

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
	virtual Color* clone() override;
};

enum TypicalColor : color_t {
	Black = 0x00000000,		// 黑色
	NavyBlue = 0x00000080,		// 藏青色
	DarkBlue = 0x0000008B,		// 暗蓝色
	MediumBlue = 0x000000CD,		// 中蓝色
	Blue = 0x000000FF,		// 蓝色
	InternationalKleinBlue = 0x00002FA7,		// 国际奇连蓝色
	Prussianblue = 0x00003153,		// 普鲁士蓝色
	DarkPowderBlue = 0x00003399,		// 暗粉蓝色
	Ultramarine = 0x000033FF,		// 极浓海蓝色
	MarineBlue = 0x0000477D,		// 水手蓝色
	CobaltBlue = 0x000047AB,		// 钴蓝色
	MineralBlue = 0x00004D99,		// 矿蓝色
	StrongBlue = 0x00006374,		// 浓蓝色
	DarkGreen = 0x00006400,		// 暗绿色
	Azure = 0x00007FFF,		// 湛蓝色
	Green = 0x00008000,		// 绿色
	Teal = 0x00008080,		// 凫绿色
	PeacockBlue = 0x0000808C,		// 孔雀蓝色
	DarkCyan = 0x00008B8B,		// 暗青色
	PeacockGreen = 0x0000A15C,		// 孔雀绿色
	DeepSkyBlue = 0x0000BFFF,		// 深天蓝色
	DarkTurquoise = 0x0000CED1,		// 暗绿松石色
	MediumSpringGreen = 0x0000FA9A,		// 中春绿色
	Lime = 0x0000FF00,		// 鲜绿色
	SpringGreen = 0x0000FF80,		// 春绿色
	TurquoiseBlue = 0x0000FFEF,		// 土耳其蓝色
	Cyan = 0x0000FFFF,		// 青色
	Sapphire = 0x00082567,		// 蓝宝石色
	CyanBlue = 0x000DBF8C,		// 青蓝色
	Viridian = 0x00127436,		// 铬绿色
	Mint = 0x0016982B,		// 薄荷绿色
	MidnightBlue = 0x00191970,		// 午夜蓝色
	DodgerBlue = 0x001E90FF,		// 道奇蓝色
	LightSeaGreen = 0x0020B2AA,		// 亮海绿色
	ForestGreen = 0x00228B22,		// 森林绿色
	Malachite = 0x0022C32E,		// 孔雀石绿色
	DarkMineralBlue = 0x0024367D,		// 暗矿蓝色
	LapisLazuli = 0x0026619C,		// 天青石蓝色
	Ceruleanblue = 0x002A52BE,		// 蔚蓝色
	SeaGreen = 0x002E8B57,		// 海绿色
	DarkSlateGray = 0x002F4F4F,		// 暗岩灰色
	LimeGreen = 0x0032CD32,		// 柠檬绿色
	IvyGreen = 0x0036BF36,		// 常春藤绿色
	MediumSeaGreen = 0x003CB371,		// 中海绿色
	Turquoise = 0x0040E0D0,		// 绿松石色
	RoyalBlue = 0x004169E1,		// 品蓝色
	SteelBlue = 0x004682B4,		// 钢青色
	SaxeBlue = 0x004798B3,		// 萨克斯蓝色
	DarkSlateBlue = 0x00483D8B,		// 暗岩蓝色
	MediumTurquoise = 0x0048D1CC,		// 中绿松石色
	Indigo = 0x004B0080,		// 靛色
	CoconutBrown = 0x004D1F00,		// 椰褐色
	Coffee = 0x004D3900,		// 咖啡色
	SalviaBlue = 0x004D80E6,		// 鼠尾草蓝色
	TurquoiseGreen = 0x004DE680,		// 绿松石绿色
	Emerald = 0x0050C878,		// 碧绿色
	DarkOliveGreen = 0x00556B2F,		// 暗橄榄绿色
	WedgwoodBlue = 0x005686BF,		// 韦奇伍德瓷蓝色
	PaleDenim = 0x005E86C1,		// 灰丁宁蓝色
	CadetBlue = 0x005F9EA0,		// 军服蓝色
	IronGray = 0x00625B57,		// 铁灰色
	CornflowerBlue = 0x006495ED,		// 矢车菊蓝色
	MediumAquamarine = 0x0066CDAA,		// 中碧蓝色
	BrightGreen = 0x0066FF00,		// 明绿色
	CobaltGreen = 0x0066FF59,		// 钴绿色
	AquaBlue = 0x0066FFE6,		// 水蓝色
	DimGray = 0x00696969,		// 昏灰色
	MossGreen = 0x00697723,		// 苔藓绿色
	Purple = 0x006A0DAD,		// 紫色
	SlateBlue = 0x006A5ACD,		// 岩蓝色
	OliveDrab = 0x006B8E23,		// 橄榄军服绿色
	Sepia = 0x00704214,		// 乌贼墨色
	SlateGray = 0x00708090,		// 岩灰色
	FoliageGreen = 0x0073B839,		// 叶绿色
	VeryLightMalachiteGreen = 0x0073E68C,		// 浅孔雀石绿色
	Pansy = 0x007400A1,		// 三色堇紫色
	LightSlateGray = 0x00778899,		// 亮岩灰色
	MediumSlateBlue = 0x007B68EE,		// 中岩蓝色
	LawnGreen = 0x007CFC00,		// 草坪绿色
	Chartreuse = 0x007FFF00,		// 查特酒绿色
	Aquamarine = 0x007FFFD4,		// 碧蓝色
	Maroon = 0x00800000,		// 栗色
	Burgundy = 0x00800020,		// 勃艮第酒红色
	Patriarch = 0x00800080,		// 宗主教色
	Violet = 0x008000FF,		// 紫罗兰色
	Olive = 0x00808000,		// 橄榄色
	Gray = 0x00808080,		// 灰色
	GrayishPurple = 0x008674A1,		// 浅灰紫红色
	SkyBlue = 0x0087CEEB,		// 天空蓝色
	LightSkyBlue = 0x0087CEFA,		// 浅天蓝色
	BabyBlue = 0x0089CFF0,		// 浅蓝色
	BlueViolet = 0x008A2BE2,		// 蓝紫色
	DarkRed = 0x008B0000,		// 暗红色
	DarkMagenta = 0x008B008B,		// 暗洋红色
	SaddleBrown = 0x008B4513,		// 鞍褐色
	AppleGreen = 0x008CE600,		// 苹果绿色
	Plum = 0x008E4585,		// 李红色
	DarkSeaGreen = 0x008FBC8F,		// 暗海绿色
	LightGreen = 0x0090EE90,		// 亮绿色
	MediumPurple = 0x009370DB,		// 中紫红色
	DarkViolet = 0x009400D3,		// 暗紫色
	PaleGreen = 0x0098FB98,		// 灰绿色
	CardinalRed = 0x00990036,		// 枢机红色
	DarkOrchid = 0x009932CC,		// 暗兰紫色
	Amethyst = 0x009966CC,		// 紫水晶色
	Khaki = 0x00996B1F,		// 卡其色
	GrassGreen = 0x0099E64D,		// 草绿色
	FreshLeaves = 0x0099FF4D,		// 嫩绿色
	YellowGreen = 0x009ACD32,		// 黄绿色
	Sienna = 0x00A0522D,		// 赭黄色
	Camel = 0x00A16B47,		// 驼色
	MineralViolet = 0x00A39DAE,		// 矿紫色
	Brown = 0x00A52A2A,		// 褐色
	DarkGray = 0x00A9A9A9,		// 暗灰色
	Celadon = 0x00ACE1AF,		// 青瓷绿色
	LightBlue = 0x00ADD8E6,		// 亮蓝色
	GreenYellow = 0x00ADFF2F,		// 绿黄色
	Aqua = 0x00AFDFE4,		// 水色
	PaleTurquoise = 0x00AFEEEE,		// 灰绿松石色
	LightViolet = 0x00B09DB9,		// 亮紫色
	LightSteelBlue = 0x00B0C4DE,		// 亮钢蓝色
	PowderBlue = 0x00B0E0E6,		// 粉蓝色
	FireBrick = 0x00B22222,		// 砖红色
	Lavender = 0x00B57EDC,		// 薰衣草紫色
	OperaMauve = 0x00B784A7,		// 优品紫红色
	DarkGoldenrod = 0x00B8860B,		// 暗金菊色
	HorizonBlue = 0x00B8DDC8,		// 苍色
	MediumOrchid = 0x00BA55D3,		// 中兰紫色
	RosyBrown = 0x00BC8F8F,		// 玫瑰褐色
	DarkKhaki = 0x00BDB76B,		// 暗卡其色
	OldRose = 0x00C08081,		// 陈玫红色
	Silver = 0x00C0C0C0,		// 银色
	Periwinkle = 0x00C3CDE6,		// 长春花色
	MediumVioletRed = 0x00C71585,		// 中青紫红色
	Lilac = 0x00C8A2C8,		// 紫丁香色
	Wisteria = 0x00C9A0DC,		// 紫藤色
	Ruby = 0x00CC0080,		// 红宝石色
	BurntOrange = 0x00CC5500,		// 燃橙色
	Ocher = 0x00CC7722,		// 赭色
	Clematis = 0x00CCA3CC,		// 铁线莲紫色
	PaleOcre = 0x00CCB38C,		// 灰土色
	Mustard = 0x00CCCC4D,		// 芥末黄色
	LavenderBlue = 0x00CCCCFF,		// 薰衣草蓝色
	LightLime = 0x00CCFF00,		// 亮柠檬绿色
	IndianRed = 0x00CD5C5C,		// 印度红色
	Bronze = 0x00CD7F32,		// 铜色
	Peru = 0x00CD853F,		// 秘鲁色
	PaleBlue = 0x00D1EDF2,		// 灰蓝色
	Chocolate = 0x00D2691E,		// 巧克力色
	Tan = 0x00D2B48C,		// 日晒色
	LightGray = 0x00D3D3D3,		// 亮灰色
	Thistle = 0x00D8BFD8,		// 蓟紫色
	Mallow = 0x00D94DFF,		// 锦葵紫色
	Orchid = 0x00DA70D6,		// 兰紫色
	Goldenrod = 0x00DAA520,		// 金菊色
	PaleVioletRed = 0x00DB7093,		// 灰紫红色
	Crimson = 0x00DC143C,		// 绯红色
	Gainsboro = 0x00DCDCDC,		// 庚斯博罗灰色
	MediumLavenderMagenta = 0x00DDA0DD,		// 梅红色
	Cerise = 0x00DE3163,		// 樱桃红色
	BurlyWood = 0x00DEB887,		// 硬木色
	Heliotrope = 0x00DF73FF,		// 缬草紫色
	Mauve = 0x00E0B0FF,		// 木槿紫色
	LightCyan = 0x00E0FFFF,		// 亮青色
	AlizarinCrimson = 0x00E32636,		// 茜红色
	StrongRed = 0x00E60000,		// 鲜红色
	Carmine = 0x00E6005C,		// 胭脂红色
	Camellia = 0x00E63995,		// 山茶红色
	Flamingo = 0x00E68AB8,		// 火鹤红色
	Apricot = 0x00E69966,		// 杏黄色
	ChromeYellow = 0x00E6B800,		// 铬黄色
	Jasmine = 0x00E6C35C,		// 茉莉黄色
	SandBeige = 0x00E6C3C3,		// 沙棕色
	PailLilac = 0x00E6CFE6,		// 淡紫丁香色
	Mimosa = 0x00E6D933,		// 含羞草黄色
	LavenderMist = 0x00E6E6FA,		// 薰衣草雾色
	DarkSalmon = 0x00E9967A,		// 暗鲑红色
	LavenderMagenta = 0x00EE82EE,		// 薰衣草紫红色
	PaleGoldenrod = 0x00EEE8AA,		// 灰金菊色
	LightCoral = 0x00F08080,		// 亮珊瑚色
	LightKhaki = 0x00F0E68C,		// 亮卡其色
	AliceBlue = 0x00F0F8FF,		// 爱丽丝蓝色
	Honeydew = 0x00F0FFF0,		// 蜜瓜绿色
	Tangerine = 0x00F28500,		// 橘色
	Fuchsia = 0x00F400A1,		// 品红色
	SandBrown = 0x00F4A460,		// 沙褐色
	Wheat = 0x00F5DEB3,		// 小麦色
	Beige = 0x00F5F5DC,		// 米色
	WhiteSmoke = 0x00F5F5F5,		// 白烟色
	MintCream = 0x00F5FFFA,		// 薄荷奶油色
	GhostWhite = 0x00F8F8FF,		// 幽灵白色
	Salmon = 0x00FA8072,		// 鲑红色
	AntiqueWhite = 0x00FAEBD7,		// 古董白色
	Linen = 0x00FAF0E6,		// 亚麻色
	LightGoldenrodYellow = 0x00FAFAD2,		// 亮金菊黄色
	OldLace = 0x00FDF5E6,		// 旧蕾丝色
	Red = 0x00FF0000,		// 红色
	Rose = 0x00FF007F,		// 玫瑰红色
	Magenta = 0x00FF00FF,		// 洋红色
	MagentaRose = 0x00FF0DA6,		// 洋玫瑰红色
	DeepPink = 0x00FF1493,		// 深粉红色
	Scarlet = 0x00FF2400,		// 腥红色
	OrangeRed = 0x00FF4500,		// 橙红色
	Vermilion = 0x00FF4D00,		// 朱红色
	Persimmon = 0x00FF4D40,		// 柿子橙色
	Tomato = 0x00FF6347,		// 蕃茄红色
	RosePink = 0x00FF66CC,		// 浅玫瑰红色
	HotPink = 0x00FF69B4,		// 暖粉红色
	SunOrange = 0x00FF7300,		// 阳橙色
	SpinelRed = 0x00FF73B3,		// 尖晶石红色
	Coral = 0x00FF7F50,		// 珊瑚红色
	TropicalOrange = 0x00FF8033,		// 热带橙色
	SalmonPink = 0x00FF8099,		// 浅鲑红色
	CoralPink = 0x00FF80BF,		// 浅珊瑚红色
	DarkOrange = 0x00FF8C00,		// 暗橙色
	Marigold = 0x00FF9900,		// 万寿菊黄色
	LightSalmon = 0x00FFA07A,		// 亮鲑红色
	Orange = 0x00FFA500,		// 橙色
	HoneyOrange = 0x00FFB366,		// 蜜橙色
	ShellPink = 0x00FFB3BF,		// 壳黄红色
	PearlPink = 0x00FFB3E6,		// 浅珍珠红色
	LightPink = 0x00FFB6C1,		// 亮粉红色
	Amber = 0x00FFBF00,		// 琥珀色
	Pink = 0x00FFC0CB,		// 粉红色
	Golden = 0x00FFD700,		// 金色
	BabyPink = 0x00FFD9E6,		// 浅粉红色
	PeachPuff = 0x00FFDAB9,		// 粉扑桃色
	NavajoWhite = 0x00FFDEAD,		// 那瓦霍白色
	Moccasin = 0x00FFE4B5,		// 鹿皮鞋色
	Bisque = 0x00FFE4C4,		// 陶坯黄色
	MistyRose = 0x00FFE4E1,		// 雾玫瑰色
	Peach = 0x00FFE5B4,		// 桃色
	BlanchedAlmond = 0x00FFEBCD,		// 杏仁白色
	CanaryYellow = 0x00FFEF00,		// 鲜黄色
	PapayaWhip = 0x00FFEFD5,		// 蕃木瓜色
	LavenderBlush = 0x00FFF0F5,		// 浅薰衣草紫红色
	Seashell = 0x00FFF5EE,		// 海贝色
	Cornsilk = 0x00FFF8DC,		// 玉米丝色
	LemonChiffon = 0x00FFFACD,		// 柠檬绸色
	FloralWhite = 0x00FFFAF0,		// 花卉白色
	Snow = 0x00FFFAFA,		// 雪色
	Cream = 0x00FFFDD0,		// 奶油色
	Yellow = 0x00FFFF00,		// 黄色
	MoonYellow = 0x00FFFF4D,		// 月黄色
	ChampagneYellow = 0x00FFFF99,		// 香槟黄色
	LightYellow = 0x00FFFFE0,		// 亮黄色
	Ivory = 0x00FFFFF0,		// 象牙色
	White = 0x00FFFFFF,		// 白色
};

inline Color* C(TypicalColor color) {
	return new Color(color);
}

}
}

