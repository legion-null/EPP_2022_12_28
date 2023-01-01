#include "defs.h"

const c8* __GetFileBaseName(const c8 *path) {
	const c8 *p = path;
	while (*p != 0)
		p++;
	while (*p != '/')
		p--;

	return p + 1;

}
