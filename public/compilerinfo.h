#ifndef FUNDAMENTAL_COMPILERINFO_H
#define FUNDAMENTAL_COMPILERINFO_H

#include "definitions.h"

startcblock

#define __midl

#if defined(_WIN32) || defined(_WIN64)
	#define FUNDAMENTAL_SYSTEM_WINDOWS

	#ifndef NOMINMAX
		#define NOMINMAX
	#endif

#elif defined(__APPLE__) && defined(__MACH__)
	#define FUNDAMENTAL_SYSTEM_OSX
#elif defined(__unix__)
	#define FUNDAMENTAL_SYSTEM_UNIX
	#if defined(__linux__)
		#define FUNDAMENTAL_SYSTEM_LINUX
	#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
		#define FUNDAMENTAL_SYSTEM_FREEBSD
	#else
		#error This UNIX operating system is not supported by Fundamental
	#endif

#else
	#error This operating system is not supported by Fundamental
#endif

#if defined(_WIN32) || defined(_WIN64)
	#if defined(_WIN64)
		#define FUNDAMENTAL_64_BIT
	#else
		#define FUNDAMENTAL_32_BIT
	#endif
#endif

#if defined(__GNUC__)
	#if defined(__x86_64__) || defined(__ppc64__)
		#define FUNDAMENTAL_64_BIT
	#else
		#define FUNDAMENTAL_32_BIT
	#endif
#endif

#if defined(_MSC_VER)
	#define FUNDAMENTAL_COMPILER_MSVC
#elif defined(__clang__)
	#define FUNDAMENTAL_COMPILER_CLANG
#elif defined(__GNUC__) || defined(__GNUG__) && !(defined(__clang__) || defined(__INTEL_COMPILER))
	#define FUNDAMENTAL_COMPILER_GNU_GCC
#elif defined(__INTEL_COMPILER)
	#define FUNDAMENTAL_COMPILER_INTEL
#endif


endcblock

#endif