#include "types.h"
#include "file.h"
#include "console.h"

nomangle i32 FundamentalMain(cstr argsString, usize argCount, cstr* argsArray)
{
	usize fileSize;

	if (argCount != 2)
	{
		puts_no_newline("No such file.");
		return 1;
	}

	u8* fileData = loadfile(argsArray[1], &fileSize);
	if (!fileData)
	{
		puts_no_newline("No such file.");
		return 1;
	}

	write_console(fileData, fileSize);
	//free_heap(fileData); // Let Windows do dis when we end the process.

	return 1;
}