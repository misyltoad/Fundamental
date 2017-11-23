#ifndef FUNDAMENTAL_STRUTILS_H
#define FUNDAMENTAL_STRUTILS_H

#include "definitions.h"
#include "types.h"

startcblock

#if 1
	usize strlen(cstr str);
	#pragma intrinsic(strlen)

	usize wcslen(wstr str);
	#pragma intrinsic(wcslen)
#else
	usize strlen(cstr str);
#endif

endcblock

#endif