#include "strutils.h"
#include "types.h"
#include "memory.h"
#include "memory_private.h"
#include "console_private.h"
#include "windows_stripped.h"

nomangle extern i32 FundamentalMain(cstr argsString, usize argCount, cstr* argsArray);

void fundamental_init()
{
	fundamental_memory_init();
	fundamental_console_init();
}

#ifdef FUNDAMENTAL_SYSTEM_WINDOWS

int FundamentalBootstrapWindows()
{
	fundamental_init();

	#define argsalloc heapalloc

	cstr argvStr = GetCommandLineA();
	usize argvStrLen = strlen(argvStr);

	int spaceCount = 0;
	for (int i = 0; i < argvStrLen; i++)
	{
		if (argvStr[i] == ' ')
			spaceCount++;
	}

	cstr* argsArray = (cstr*)argsalloc(spaceCount * sizeof(cstr*));

	int lastSpace = -1;
	int currentSpace = 0;
	for (int i = 0; i < argvStrLen; i++)
	{
		if (argvStr[i] == ' ')
		{
			argsArray[currentSpace] = (cstr) argsalloc(i - lastSpace);
			memcpy((void*)argsArray[currentSpace], (void*) &argvStr[lastSpace + 1], i - lastSpace - 1);
			argsArray[i - lastSpace] = '\0';

			lastSpace = i;
			currentSpace++;
		}
	}

	return FundamentalMain(argvStr, currentSpace, argsArray);
}

nomangle int __stdcall mainCRTStartup()
{
	return FundamentalBootstrapWindows();
}

nomangle int __stdcall WinMainCRTStartup()
{
	return FundamentalBootstrapWindows();
}

#endif

nomangle int main()
{
	return FundamentalBootstrapWindows();
}