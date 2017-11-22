#include "memory.h"
#include "memory_private.h"

#include "compilerinfo.h"
#include "windows_stripped.h"

#ifdef FUNDAMENTAL_SYSTEM_WINDOWS
HANDLE fundamental_heap;
#endif

nomangle void fundamental_memory_init()
{
#ifdef FUNDAMENTAL_SYSTEM_WINDOWS
	fundamental_heap = HeapCreate(0, 0, 0);
#endif
}

nomangle usize memsize(void* ptr)
{
	MemoryHeader* memory = (MemoryHeader*)(ptr);
	memory--;

	return memory->size;
}

nomangle void* heapalloc(usize allocSize)
{
	MemoryHeader header;
	header.size = allocSize;

	allocSize += sizeof(MemoryHeader);

	MemoryHeader* data;

#ifdef FUNDAMENTAL_SYSTEM_WINDOWS
	 data = (MemoryHeader*) HeapAlloc(fundamental_heap, 0, allocSize);
#else
#endif

	*data = header;
	data++;

	return (void*)(data);
}

void heapfree(void* ptr)
{
	MemoryHeader* memory = (MemoryHeader*)(ptr);
	memory--;

#ifdef FUNDAMENTAL_SYSTEM_WINDOWS
	HeapFree(fundamental_heap, 0, (void*) memory);
#endif
}

#pragma function(memset)
nomangle void *memset(void *dest, int c, size_t count)
{
	char *bytes = (char *)dest;
	while (count--)
	{
		*bytes++ = (char)c;
	}
	return dest;
}

#pragma function(memcpy)
nomangle void *memcpy(void *dest, const void *src, size_t count)
{
	char *dest8 = (char *)dest;
	const char *src8 = (const char *)src;
	while (count--)
	{
		*dest8++ = *src8++;
	}
	return dest;
}