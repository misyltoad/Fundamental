#ifndef FUNDAMENTAL_CONSOLE_H
#define FUNDAMENTAL_CONSOLE_H

#include "definitions.h"
#include "types.h"
#include "memory.h"

startcblock

void write_console(void* data, usize length);
void puts(cstr str);
void puts_no_newline(cstr str);

void wide_write_console(void* data, usize length);
void wide_puts(wstr str);
void wide_puts_no_newline(wstr str);


endcblock

#endif