#include "strutils.h"
#include "types.h"
#include "memory.h"
#include "memory_private.h"
#include "console_private.h"
#include "windows_stripped.h"
#include "fundamental_config.h"

#ifdef FUNDAMENTAL_SIMPLE_ENTRY
nomangle extern i32 FundamentalMain();
#else
nomangle extern i32 FundamentalMain(wstr argsString, int argCount, wstr* argsArray);
#endif

#ifdef FUNDAMENTAL_SYSTEM_WINDOWS

//inline void fundamental_init()
//{
	//fundamental_memory_init();
	//fundamental_console_init();
//}

#if 0
inline int FundamentalBootstrapWindows()
{
	//fundamental_init();

	#define argsalloc alloc_heap

	cstr argvStr = GetCommandLineA();
	usize argvStrLen = strlen(argvStr);

	usize spaceCount = 0;
	for (usize i = 0; i < argvStrLen; i++)
	{
		if (argvStr[i] == ' ')
		{
			if (argvStr[i + 1] == ' ' || argvStr[i + 1] == '\0')
				continue;

			spaceCount++;
		}
	}

	usize argCount = (spaceCount + 1);
	cstr* argsArray = (cstr*)argsalloc(argCount * sizeof(cstr*));

	usize lastSpace = -1;
	usize currentSpace = 0;
	for (usize i = 0; i < argvStrLen + 1; i++)
	{
		if (argvStr[i] == ' ' || argvStr[i] == '\0')
		{
			argsArray[currentSpace] = (cstr) argsalloc(i - lastSpace);
			copy_memory((void*)argsArray[currentSpace], (void*) &argvStr[lastSpace + 1], i - lastSpace - 1);
			argsArray[i - lastSpace] = '\0';

			lastSpace = i;
			currentSpace++;
		}
	}

	return FundamentalMain(argvStr, argCount, argsArray);
}
#else
inline int FundamentalBootstrapWindows()
{
#ifdef FUNDAMENTAL_SYSTEM_WINDOWS
	wstr cmdLine = GetCommandLineW();
	int argCount;
	wstr* cmdArgs = CommandLineToArgvW(cmdLine, &argCount);
	return FundamentalMain(cmdLine, argCount, cmdArgs);
#else
	return FundamentalMain();
#endif
}
#endif

#endif

nomangle int __stdcall mainCRTStartup()
{
	return FundamentalBootstrapWindows();
}

nomangle int __stdcall WinMainCRTStartup()
{
	return FundamentalBootstrapWindows();
}

nomangle int __stdcall FundamentalEntryPoint()
{
	return FundamentalBootstrapWindows();
}

nomangle int __stdcall main()
{
	return FundamentalBootstrapWindows();
}