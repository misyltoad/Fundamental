#include "strutils.h"

#if 0
nomangle usize strlen(cstr str)
{
	cstr terminator = str;
	while (*str != '\0')
		terminator++;
	return terminator - str;
}
#endif