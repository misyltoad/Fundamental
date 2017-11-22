#ifndef FUNDAMENTAL_MEMORY_H
#define FUNDAMENTAL_MEMORY_H

#include "definitions.h"
#include "types.h"

startcblock

	void set_memory(void* dst, int value, usize size);

	void copy_memory(void* dst, const void* src, usize size);

	usize get_memory_size(void* ptr);

	void* alloc_heap(usize allocSize);

	void free_heap(void* ptr);

endcblock

#endif