#include "Epp.h"

#include "ASCII_16X24_1BPP.h"

// !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~

namespace Epp {
namespace graphics {

const u32 MATRIX_ASCII_16X24_1BPP_CODES[1][2] = {
	{ 32, 126 },
};

const u8 MATRIX_ASCII_16X24_1BPP_DATA[95][16 * 24 / 8] = {
	{ // [   ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ ! ]
		0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ " ]
		0x00, 0x00, 0x0c, 0xc0, 0x0c, 0xc0, 0x0c, 0xc0, 0x0c, 0xc0, 0x0c, 0xc0, 0x0c, 0xc0, 0x0c, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ # ]
		0x00, 0x00, 0x03, 0x30, 0x02, 0x30, 0x06, 0x30, 0x06, 0x30, 0x06, 0x20, 0x7f, 0xfc, 0x7f, 0xfc, 0x0c, 0x60, 0x0c, 0x40, 0x0c, 0xc0, 0x08, 0xc0, 0xff, 0xf8, 0xff, 0xf8, 0x19, 0x80, 0x11, 0x80, 0x31, 0x80, 0x31, 0x80, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ $ ]
		0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x07, 0xe0, 0x1f, 0xf0, 0x39, 0x10, 0x31, 0x00, 0x31, 0x00, 0x31, 0x00, 0x1f, 0x00, 0x0f, 0xe0, 0x01, 0xf0, 0x01, 0x38, 0x01, 0x18, 0x01, 0x18, 0x21, 0x38, 0x3f, 0xf0, 0x1f, 0xc0, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00,
	},
	{ // [ % ]
		0x00, 0x00, 0x38, 0x00, 0x7c, 0x00, 0xc6, 0x00, 0xc6, 0x00, 0xc6, 0x00, 0x7c, 0x18, 0x38, 0x30, 0x00, 0xe0, 0x01, 0x80, 0x06, 0x00, 0x1c, 0x00, 0x30, 0x70, 0x60, 0xf8, 0x01, 0x8c, 0x01, 0x8c, 0x01, 0x8c, 0x00, 0xf8, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ & ]
		0x00, 0x00, 0x07, 0x80, 0x0f, 0xc0, 0x1c, 0x40, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x0c, 0x00, 0x0e, 0x00, 0x1e, 0x00, 0x33, 0x06, 0x61, 0x86, 0x61, 0xc6, 0x60, 0xee, 0x60, 0x7c, 0x70, 0x38, 0x38, 0x7c, 0x1f, 0xec, 0x0f, 0xce, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ ' ]
		0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ ( ]
		0x00, 0x00, 0x00, 0xc0, 0x01, 0x80, 0x01, 0x80, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x01, 0x80, 0x01, 0x80, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ ) ]
		0x00, 0x00, 0x0c, 0x00, 0x06, 0x00, 0x06, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x06, 0x00, 0x06, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ * ]
		0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x31, 0x18, 0x1d, 0x70, 0x07, 0xc0, 0x07, 0xc0, 0x1d, 0x70, 0x31, 0x18, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ + ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x7f, 0xf8, 0x7f, 0xf8, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ , ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x00, 0x07, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ - ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xc0, 0x0f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ . ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ / ]
		0x00, 0x00, 0x00, 0x30, 0x00, 0x60, 0x00, 0x60, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x01, 0x80, 0x01, 0x80, 0x03, 0x00, 0x03, 0x00, 0x06, 0x00, 0x06, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x30, 0x00, 0x30, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ 0 ]
		0x00, 0x00, 0x07, 0xc0, 0x0f, 0xe0, 0x1c, 0x70, 0x18, 0x30, 0x38, 0x30, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x33, 0x98, 0x33, 0x98, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x38, 0x30, 0x18, 0x30, 0x1c, 0x70, 0x0f, 0xe0, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ 1 ]
		0x00, 0x00, 0x07, 0x80, 0x1f, 0x80, 0x19, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x1f, 0xf8, 0x1f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ 2 ]
		0x00, 0x00, 0x0f, 0xc0, 0x3f, 0xe0, 0x30, 0x30, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x38, 0x00, 0x70, 0x00, 0x60, 0x00, 0xc0, 0x01, 0x80, 0x03, 0x80, 0x06, 0x00, 0x0c, 0x00, 0x18, 0x00, 0x3f, 0xf8, 0x3f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ 3 ]
		0x00, 0x00, 0x07, 0xc0, 0x1f, 0xf0, 0x10, 0x30, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x70, 0x07, 0xe0, 0x07, 0xe0, 0x00, 0x70, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x20, 0x70, 0x3f, 0xf0, 0x1f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ 4 ]
		0x00, 0x00, 0x00, 0xe0, 0x01, 0xe0, 0x01, 0x60, 0x03, 0x60, 0x06, 0x60, 0x06, 0x60, 0x0c, 0x60, 0x0c, 0x60, 0x18, 0x60, 0x30, 0x60, 0x30, 0x60, 0x60, 0x60, 0x7f, 0xf8, 0x7f, 0xf8, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ 5 ]
		0x00, 0x00, 0x1f, 0xf0, 0x1f, 0xf0, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x1f, 0xc0, 0x1f, 0xe0, 0x10, 0x70, 0x00, 0x38, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x38, 0x20, 0x70, 0x3f, 0xe0, 0x1f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ 6 ]
		0x00, 0x00, 0x03, 0xe0, 0x0f, 0xf0, 0x0e, 0x10, 0x18, 0x00, 0x18, 0x00, 0x30, 0x00, 0x33, 0xc0, 0x37, 0xf0, 0x3c, 0x70, 0x38, 0x38, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x18, 0x38, 0x1c, 0x70, 0x0f, 0xf0, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ 7 ]
		0x00, 0x00, 0x3f, 0xf8, 0x3f, 0xf8, 0x00, 0x30, 0x00, 0x30, 0x00, 0x70, 0x00, 0x60, 0x00, 0x60, 0x00, 0xc0, 0x00, 0xc0, 0x01, 0xc0, 0x01, 0x80, 0x01, 0x80, 0x03, 0x00, 0x03, 0x00, 0x07, 0x00, 0x06, 0x00, 0x06, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ 8 ]
		0x00, 0x00, 0x07, 0xc0, 0x1f, 0xf0, 0x38, 0x30, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x18, 0x30, 0x0f, 0xe0, 0x0f, 0xe0, 0x18, 0x30, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x38, 0x38, 0x1f, 0xf0, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ 9 ]
		0x00, 0x00, 0x07, 0xc0, 0x1f, 0xe0, 0x1c, 0x70, 0x38, 0x30, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x38, 0x38, 0x18, 0x78, 0x1f, 0xd8, 0x07, 0x98, 0x00, 0x18, 0x00, 0x30, 0x00, 0x30, 0x10, 0x60, 0x1f, 0xe0, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ : ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ ; ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x00, 0x07, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ < ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x78, 0x01, 0xf0, 0x07, 0xc0, 0x3e, 0x00, 0x78, 0x00, 0x78, 0x00, 0x3e, 0x00, 0x07, 0xc0, 0x01, 0xf0, 0x00, 0x78, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ = ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xf8, 0x7f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xf8, 0x7f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ > ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x78, 0x00, 0x3e, 0x00, 0x0f, 0x80, 0x01, 0xf0, 0x00, 0x78, 0x00, 0x78, 0x01, 0xf0, 0x0f, 0x80, 0x3e, 0x00, 0x78, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ ? ]
		0x00, 0x00, 0x07, 0xc0, 0x0f, 0xe0, 0x18, 0x70, 0x10, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x60, 0x00, 0xe0, 0x01, 0xc0, 0x03, 0x80, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ @ ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x07, 0xf8, 0x1e, 0x1c, 0x18, 0x0e, 0x30, 0x06, 0x30, 0xf6, 0x61, 0xfe, 0x63, 0x8e, 0x63, 0x06, 0x63, 0x06, 0x63, 0x06, 0x63, 0x06, 0x63, 0x8e, 0x71, 0xfe, 0x30, 0xf6, 0x38, 0x00, 0x1c, 0x00, 0x0e, 0x00, 0x07, 0xf8, 0x01, 0xf8, 0x00, 0x00,
	},
	{ // [ A ]
		0x00, 0x00, 0x03, 0x00, 0x07, 0x80, 0x07, 0x80, 0x07, 0x80, 0x07, 0x80, 0x0c, 0xc0, 0x0c, 0xc0, 0x0c, 0xc0, 0x1c, 0xc0, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x3f, 0xf0, 0x3f, 0xf0, 0x30, 0x30, 0x30, 0x30, 0x60, 0x18, 0x60, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ B ]
		0x00, 0x00, 0x7f, 0x00, 0x7f, 0xc0, 0x60, 0xe0, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0xc0, 0x7f, 0xc0, 0x7f, 0xc0, 0x60, 0x60, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x70, 0x7f, 0xe0, 0x7f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ C ]
		0x00, 0x00, 0x07, 0xe0, 0x0f, 0xf0, 0x1c, 0x10, 0x30, 0x00, 0x30, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x30, 0x00, 0x30, 0x00, 0x1c, 0x10, 0x0f, 0xf0, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ D ]
		0x00, 0x00, 0x7f, 0x00, 0x7f, 0x80, 0x61, 0xc0, 0x60, 0x60, 0x60, 0x60, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x60, 0x60, 0x60, 0x61, 0xc0, 0x7f, 0x80, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ E ]
		0x00, 0x00, 0x7f, 0xf0, 0x7f, 0xf0, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x7f, 0xe0, 0x7f, 0xe0, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x7f, 0xf0, 0x7f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ F ]
		0x00, 0x00, 0x7f, 0xf0, 0x7f, 0xf0, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x7f, 0xe0, 0x7f, 0xe0, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ G ]
		0x00, 0x00, 0x07, 0xe0, 0x0f, 0xf0, 0x1c, 0x10, 0x30, 0x00, 0x30, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0xf8, 0x60, 0xf8, 0x60, 0x18, 0x60, 0x18, 0x30, 0x18, 0x30, 0x18, 0x1c, 0x18, 0x0f, 0xf8, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ H ]
		0x00, 0x00, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x7f, 0xf0, 0x7f, 0xf0, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ I ]
		0x00, 0x00, 0x3f, 0xf0, 0x3f, 0xf0, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x3f, 0xf0, 0x3f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ J ]
		0x00, 0x00, 0x07, 0xe0, 0x07, 0xe0, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x40, 0x60, 0x60, 0xc0, 0x7f, 0xc0, 0x3f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ K ]
		0x00, 0x00, 0x60, 0x38, 0x60, 0x70, 0x60, 0xe0, 0x61, 0xc0, 0x63, 0x80, 0x67, 0x00, 0x6e, 0x00, 0x7c, 0x00, 0x7e, 0x00, 0x77, 0x00, 0x63, 0x00, 0x61, 0x80, 0x61, 0xc0, 0x60, 0xc0, 0x60, 0x60, 0x60, 0x70, 0x60, 0x30, 0x60, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ L ]
		0x00, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x7f, 0xf0, 0x7f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ M ]
		0x00, 0x00, 0x70, 0x38, 0x70, 0x38, 0x78, 0x78, 0x78, 0x78, 0x68, 0x58, 0x6c, 0xd8, 0x6c, 0xd8, 0x64, 0x98, 0x67, 0x98, 0x67, 0x98, 0x63, 0x18, 0x63, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ N ]
		0x00, 0x00, 0x70, 0x30, 0x70, 0x30, 0x78, 0x30, 0x78, 0x30, 0x6c, 0x30, 0x6c, 0x30, 0x6c, 0x30, 0x66, 0x30, 0x66, 0x30, 0x63, 0x30, 0x63, 0x30, 0x61, 0xb0, 0x61, 0xb0, 0x61, 0xb0, 0x60, 0xf0, 0x60, 0xf0, 0x60, 0x70, 0x60, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ O ]
		0x00, 0x00, 0x0f, 0xc0, 0x1f, 0xe0, 0x38, 0x70, 0x30, 0x30, 0x70, 0x30, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x70, 0x30, 0x30, 0x30, 0x38, 0x70, 0x1f, 0xe0, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ P ]
		0x00, 0x00, 0x7f, 0x80, 0x7f, 0xe0, 0x60, 0xe0, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0xe0, 0x7f, 0xe0, 0x7f, 0x80, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ Q ]
		0x00, 0x00, 0x0f, 0xc0, 0x1f, 0xe0, 0x38, 0x70, 0x30, 0x30, 0x70, 0x30, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x70, 0x38, 0x30, 0x30, 0x38, 0x70, 0x1f, 0xe0, 0x07, 0xc0, 0x00, 0xe0, 0x00, 0x70, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ R ]
		0x00, 0x00, 0x7f, 0x80, 0x7f, 0xe0, 0x60, 0xe0, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x60, 0x7f, 0xc0, 0x7f, 0xc0, 0x60, 0xc0, 0x60, 0x60, 0x60, 0x70, 0x60, 0x30, 0x60, 0x30, 0x60, 0x18, 0x60, 0x18, 0x60, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ S ]
		0x00, 0x00, 0x0f, 0xc0, 0x3f, 0xe0, 0x30, 0x20, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x38, 0x00, 0x3f, 0x00, 0x0f, 0xc0, 0x00, 0xe0, 0x00, 0x70, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x60, 0x60, 0x7f, 0xe0, 0x3f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ T ]
		0x00, 0x00, 0x7f, 0xf8, 0x7f, 0xf8, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ U ]
		0x00, 0x00, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x60, 0x30, 0x30, 0x60, 0x3f, 0xe0, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ V ]
		0x00, 0x00, 0x60, 0x18, 0x60, 0x18, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x38, 0x70, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x1c, 0xe0, 0x0c, 0xc0, 0x0c, 0xc0, 0x0c, 0xc0, 0x07, 0xc0, 0x07, 0x80, 0x07, 0x80, 0x07, 0x80, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ W ]
		0x00, 0x00, 0xc0, 0x0c, 0xc0, 0x0c, 0xc0, 0x0c, 0xe0, 0x1c, 0x60, 0x18, 0x63, 0x18, 0x67, 0x98, 0x67, 0x98, 0x67, 0x98, 0x67, 0x98, 0x74, 0xb8, 0x3c, 0xf0, 0x3c, 0xf0, 0x3c, 0xf0, 0x38, 0x70, 0x38, 0x70, 0x38, 0x70, 0x38, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ X ]
		0x00, 0x00, 0x70, 0x38, 0x30, 0x30, 0x38, 0x70, 0x18, 0x60, 0x0c, 0xc0, 0x0c, 0xc0, 0x07, 0x80, 0x07, 0x80, 0x03, 0x00, 0x07, 0x80, 0x07, 0x80, 0x0d, 0xc0, 0x0c, 0xc0, 0x18, 0xe0, 0x18, 0x60, 0x30, 0x70, 0x30, 0x30, 0x60, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ Y ]
		0x00, 0x00, 0xe0, 0x1c, 0x60, 0x18, 0x30, 0x38, 0x30, 0x30, 0x18, 0x60, 0x1c, 0xe0, 0x0c, 0xc0, 0x07, 0x80, 0x07, 0x80, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ Z ]
		0x00, 0x00, 0x7f, 0xf8, 0x7f, 0xf8, 0x00, 0x38, 0x00, 0x70, 0x00, 0x60, 0x00, 0xe0, 0x01, 0xc0, 0x01, 0x80, 0x03, 0x80, 0x07, 0x00, 0x06, 0x00, 0x0e, 0x00, 0x1c, 0x00, 0x18, 0x00, 0x30, 0x00, 0x70, 0x00, 0x7f, 0xf8, 0x7f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ [ ]
		0x00, 0x00, 0x07, 0xc0, 0x07, 0xc0, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x07, 0xc0, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ "\" ]
		0x00, 0x00, 0x60, 0x00, 0x30, 0x00, 0x30, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x06, 0x00, 0x06, 0x00, 0x03, 0x00, 0x03, 0x00, 0x01, 0x80, 0x01, 0x80, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0x60, 0x00, 0x60, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ ] ]
		0x00, 0x00, 0x0f, 0x80, 0x0f, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x0f, 0x80, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ ^ ]
		0x00, 0x00, 0x03, 0x80, 0x07, 0xc0, 0x0e, 0xe0, 0x0c, 0x60, 0x18, 0x30, 0x30, 0x18, 0x70, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ _ ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xfc,
	},
	{ // [ ` ]
		0x1c, 0x00, 0x06, 0x00, 0x03, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ a ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xc0, 0x1f, 0xf0, 0x10, 0x38, 0x00, 0x18, 0x00, 0x18, 0x07, 0xf8, 0x1f, 0xf8, 0x38, 0x18, 0x30, 0x18, 0x30, 0x38, 0x38, 0x78, 0x1f, 0xd8, 0x0f, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ b ]
		0x00, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x33, 0xc0, 0x3f, 0xe0, 0x3c, 0x70, 0x38, 0x38, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x38, 0x38, 0x3c, 0x70, 0x3f, 0xe0, 0x33, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ c ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xe0, 0x0f, 0xf0, 0x1c, 0x10, 0x18, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x18, 0x00, 0x1c, 0x10, 0x0f, 0xf0, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ d ]
		0x00, 0x00, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x07, 0x98, 0x0f, 0xf8, 0x1c, 0x78, 0x38, 0x38, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x38, 0x38, 0x1c, 0x78, 0x0f, 0xf8, 0x07, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ e ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xc0, 0x0f, 0xf0, 0x1c, 0x30, 0x38, 0x18, 0x30, 0x18, 0x3f, 0xf8, 0x3f, 0xf8, 0x30, 0x00, 0x30, 0x00, 0x38, 0x00, 0x1c, 0x10, 0x0f, 0xf0, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ f ]
		0x00, 0x00, 0x00, 0xf8, 0x01, 0xf8, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x3f, 0xf8, 0x3f, 0xf8, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ g ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x98, 0x0f, 0xf8, 0x1c, 0x78, 0x38, 0x38, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x38, 0x38, 0x1c, 0x78, 0x0f, 0xf8, 0x07, 0x98, 0x00, 0x18, 0x00, 0x18, 0x10, 0x30, 0x1f, 0xe0, 0x0f, 0xc0,
	},
	{ // [ h ]
		0x00, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x33, 0xe0, 0x37, 0xf0, 0x3c, 0x38, 0x38, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ i ]
		0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x1f, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x3f, 0xf0, 0x3f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ j ]
		0x00, 0x00, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x80, 0x1f, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x03, 0x80, 0x3f, 0x00, 0x3e, 0x00,
	},
	{ // [ k ]
		0x00, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x70, 0x30, 0xe0, 0x31, 0xc0, 0x33, 0x80, 0x37, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x39, 0x80, 0x31, 0xc0, 0x30, 0xc0, 0x30, 0x60, 0x30, 0x70, 0x30, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ l ]
		0x00, 0x00, 0x7e, 0x00, 0x7e, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x07, 0x00, 0x03, 0xf0, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ m ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x37, 0x38, 0x3f, 0xf8, 0x31, 0x8c, 0x31, 0x8c, 0x31, 0x8c, 0x31, 0x8c, 0x31, 0x8c, 0x31, 0x8c, 0x31, 0x8c, 0x31, 0x8c, 0x31, 0x8c, 0x31, 0x8c, 0x31, 0x8c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ n ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0xe0, 0x37, 0xf0, 0x3c, 0x38, 0x38, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ o ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xc0, 0x0f, 0xe0, 0x1c, 0x70, 0x38, 0x38, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x38, 0x38, 0x1c, 0x70, 0x0f, 0xe0, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ p ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0xc0, 0x3f, 0xe0, 0x3c, 0x70, 0x38, 0x38, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x38, 0x38, 0x3c, 0x70, 0x3f, 0xe0, 0x33, 0xc0, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00,
	},
	{ // [ q ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x98, 0x0f, 0xf8, 0x1c, 0x78, 0x38, 0x38, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x38, 0x38, 0x1c, 0x78, 0x0f, 0xf8, 0x07, 0x98, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18,
	},
	{ // [ r ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xf0, 0x0d, 0xf8, 0x0f, 0x08, 0x0e, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ s ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xe0, 0x1f, 0xf0, 0x38, 0x10, 0x30, 0x00, 0x38, 0x00, 0x3f, 0x80, 0x0f, 0xf0, 0x00, 0xf8, 0x00, 0x18, 0x00, 0x18, 0x30, 0x38, 0x3f, 0xf0, 0x0f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ t ]
		0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x7f, 0xf0, 0x7f, 0xf0, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x07, 0x00, 0x03, 0xf0, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ u ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x38, 0x38, 0x78, 0x1f, 0xd8, 0x0f, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ v ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x18, 0x38, 0x38, 0x18, 0x30, 0x18, 0x30, 0x1c, 0x70, 0x0c, 0x60, 0x0c, 0x60, 0x0e, 0xe0, 0x06, 0xc0, 0x06, 0xc0, 0x07, 0xc0, 0x03, 0x80, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ w ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x0c, 0xc0, 0x0c, 0x60, 0x18, 0x60, 0x18, 0x63, 0x18, 0x63, 0x18, 0x77, 0xb8, 0x37, 0xb0, 0x34, 0xb0, 0x34, 0xb0, 0x3c, 0xf0, 0x18, 0x60, 0x18, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ x ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x1c, 0x70, 0x0c, 0x60, 0x0e, 0xe0, 0x07, 0xc0, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x06, 0xc0, 0x0e, 0xe0, 0x0c, 0x60, 0x18, 0x30, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ y ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x18, 0x18, 0x30, 0x18, 0x30, 0x18, 0x30, 0x0c, 0x60, 0x0c, 0x60, 0x0e, 0x60, 0x06, 0xc0, 0x06, 0xc0, 0x07, 0xc0, 0x03, 0x80, 0x03, 0x80, 0x01, 0x80, 0x03, 0x00, 0x03, 0x00, 0x07, 0x00, 0x1e, 0x00, 0x1c, 0x00,
	},
	{ // [ z ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xf8, 0x3f, 0xf8, 0x00, 0x30, 0x00, 0x70, 0x00, 0xe0, 0x01, 0xc0, 0x03, 0x80, 0x07, 0x00, 0x0e, 0x00, 0x1c, 0x00, 0x18, 0x00, 0x3f, 0xf8, 0x3f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
	{ // [ { ]
		0x00, 0x00, 0x01, 0xe0, 0x03, 0xe0, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x07, 0x00, 0x3e, 0x00, 0x3e, 0x00, 0x07, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0xe0, 0x01, 0xe0, 0x00, 0x00,
	},
	{ // [ | ]
		0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00,
	},
	{ // [ } ]
		0x00, 0x00, 0x1e, 0x00, 0x1f, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x80, 0x01, 0xf0, 0x01, 0xf0, 0x03, 0x80, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x1f, 0x00, 0x1e, 0x00, 0x00, 0x00,
	},
	{ // [ ~ ]
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x08, 0x7f, 0xf8, 0x41, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	},
};

}
}
