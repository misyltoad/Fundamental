#ifndef FUNDAMENTAL_STRUTILS_H
#define FUNDAMENTAL_STRUTILS_H

#include "definitions.h"
#include "types.h"

startcblock

	inline usize strlen(cstr str);
	#pragma intrinsic(strlen)

#if 0
	inline usize strlen(cstr str)
	{
		cstr terminator = str;
		while (*str != '\0')
			terminator++;

		return terminator - str;
	}
#endif

endcblock

#endif