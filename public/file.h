#ifndef FUNDAMENTAL_FILE_H
#define FUNDAMENTAL_FILE_H

#include "definitions.h"
#include "types.h"
#include "memory.h"

startcblock

u8* loadfile(cstr path, usize* size);

endcblock

#endif