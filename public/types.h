#ifndef FUNDAMENTAL_TYPES_H
#define FUNDAMENTAL_TYPES_H

#include "definitions.h"
#include "compilerinfo.h"

startcblock

	typedef signed char i8;
	typedef signed short i16;
	typedef signed int i32;

	typedef unsigned char u8;
	typedef unsigned short u16;
	typedef unsigned int u32;

#if defined (_MSC_VER)
	typedef signed __int64 i64;
	typedef unsigned __int64 u64;
#else
	typedef signed long long i64;
	typedef unsigned long long u64;
#endif

	typedef float f32;
	typedef double f64;

#ifdef FUNDAMENTAL_64_BIT
	typedef u64 usize;
	typedef i64 isize;
	typedef f64 fsize;
#else // FUNDAMENTAL_32_BIT
	typedef u32 usize;
	typedef i32 isize;
	typedef f32 fsize;
#endif

	typedef const char* cstr;
	typedef unsigned short wchar_t;
	typedef const wchar_t* wstr;

endcblock

#endif