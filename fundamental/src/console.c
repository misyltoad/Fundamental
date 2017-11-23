#include "console.h"
#include "windows_stripped.h"
#include "strutils.h"

#ifdef FUNDAMENTAL_SYSTEM_WINDOWS
//HWND ConsoleWindow;
//HANDLE ConsoleOutput;
#endif

nomangle void fundamental_console_init()
{
	//ConsoleWindow = GetConsoleWindow();
	//ConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
}

nomangle void puts_no_newline(cstr str)
{
	write_console((void*)str, strlen(str));
}

nomangle void write_console(void* data, usize length)
{
	u32 writtenChars;
	WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), data, (u32)length, &writtenChars, nullptr);
}

nomangle void puts(cstr str)
{
	puts_no_newline(str);
	write_console((void*)"\n", 1);
	//puts_no_newline("\n");
}

nomangle void wide_write_console(void* data, usize length)
{
	u32 writtenChars;
	WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), data, (u32)length, &writtenChars, nullptr);
}

nomangle void wide_puts(wstr str)
{
	wide_puts_no_newline(str);
	wide_write_console((void*)L"\n", 1);
}

nomangle void wide_puts_no_newline(wstr str)
{
	write_console((void*)str, wcslen(str));
}