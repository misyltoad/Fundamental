#ifndef FUNDAMENTAL_CONSOLE_H
#define FUNDAMENTAL_CONSOLE_H

#include "definitions.h"
#include "types.h"
#include "memory.h"

startcblock

void write_console(void* data, usize length);
void puts(cstr str);
void puts_no_newline(cstr str);

endcblock

#endif