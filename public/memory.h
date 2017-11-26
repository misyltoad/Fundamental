#ifndef FUNDAMENTAL_MEMORY_H
#define FUNDAMENTAL_MEMORY_H

#include "compilerinfo.h"
#include "definitions.h"
#include "types.h"

#ifdef FUNDAMENTAL_SYSTEM_WINDOWS
#include "windows_stripped.h"
#endif

startcblock

#ifndef FUNDAMENTAL_SYSTEM_WINDOWS
	void set_memory(void* dst, int value, usize size);
#else
#define set_memory(dst, val, size) RtlFillMemory(dst, size, val)
#endif

	void copy_memory(void* dst, const void* src, usize size);

	usize get_memory_size(void* ptr);

	void* malloc(usize allocSize);
#define alloc_heap malloc

	void free(void* ptr);
#define free_heap free

endcblock

#endif