#include "memory.h"
#include "memory_private.h"

#include "compilerinfo.h"
#include "windows_stripped.h"

#ifdef FUNDAMENTAL_SYSTEM_WINDOWS
//HANDLE fundamental_heap;
#endif

nomangle void fundamental_memory_init()
{
#ifdef FUNDAMENTAL_SYSTEM_WINDOWS
	//fundamental_heap = HeapCreate(0, 0, 0);
#endif
}

nomangle usize get_memory_size(void* ptr)
{
	MemoryHeader* memory = (MemoryHeader*)(ptr);
	memory--;

	return memory->size;
}

nomangle void* malloc(usize allocSize)
{
	MemoryHeader header;
	header.size = allocSize;

	allocSize += sizeof(MemoryHeader);

	MemoryHeader* data;

#ifdef FUNDAMENTAL_SYSTEM_WINDOWS
	 //data = (MemoryHeader*) HeapAlloc(fundamental_heap, 0, allocSize);
	data = (MemoryHeader*)HeapAlloc(GetProcessHeap(), 0, allocSize);
#else
#endif

	*data = header;
	data++;

	return (void*)(data);
}

nomangle void free(void* ptr)
{
	MemoryHeader* memory = (MemoryHeader*)(ptr);
	memory--;

#ifdef FUNDAMENTAL_SYSTEM_WINDOWS
	HeapFree(GetProcessHeap(), 0, (void*) memory);
#endif
}

#ifndef FUNDAMENTAL_SYSTEM_WINDOWS
nomangle void set_memory(void *dest, int c, usize count)
{
	char *bytes = (char *)dest;
	while (count--)
		*bytes++ = (char)c;
}
#endif

nomangle void copy_memory(void *dest, const void *src, usize count)
{
	char *dest8 = (char *)dest;
	const char *src8 = (const char *)src;
	while (count--)
		*dest8++ = *src8++;
}