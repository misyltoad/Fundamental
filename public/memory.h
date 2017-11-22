#ifndef FUNDAMENTAL_MEMORY_H
#define FUNDAMENTAL_MEMORY_H

#include "definitions.h"
#include "types.h"

startcblock

	#ifdef FUNDAMENTAL_COMPILER_MSVC
	void* __cdecl _alloca(usize allocSize);
	#define alloca _alloca
	#else
	
	#endif

	#define stackalloc alloca

	void* memset(void* dst, int value, usize size);
	#pragma intrinsic(memset)

	void* memcpy(void* dst, const void* src, usize size);
	#pragma intrinsic(memcpy)

	usize memsize(void* ptr);

	void* heapalloc(usize allocSize);
#define malloc heapalloc

	void heapfree(void* ptr);
#define free heapfree

endcblock

#endif