#include "console.h"
#include "windows_stripped.h"
#include "strutils.h"

#ifdef FUNDAMENTAL_SYSTEM_WINDOWS
//HWND ConsoleWindow;
HANDLE ConsoleOutput;
#endif

nomangle void fundamental_console_init()
{
	//ConsoleWindow = GetConsoleWindow();
	ConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
}

nomangle void puts_no_newline(cstr str)
{
	write_console((void*)str, strlen(str));
}

nomangle void write_console(void* data, usize length)
{
	u32 writtenChars;
	WriteConsoleA(ConsoleOutput, data, (u32)length, &writtenChars, nullptr);
}

nomangle void puts(cstr str)
{
	puts_no_newline(str);
	write_console((void*)"\n", 1);
	//puts_no_newline("\n");
}
