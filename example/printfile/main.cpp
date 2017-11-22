#include "types.h"
#include "file.h"
#include "console.h"

nomangle i32 FundamentalMain(cstr argsString, usize argCount, cstr* argsArray)
{
	usize fileSize;
	u8* fileData = loadfile(argsString, &fileSize);
	write_console(fileData, fileSize);
	free(fileData);

	return 1;
}
