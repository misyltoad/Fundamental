#ifndef FUNDAMENTAL_WINDOWS_STRIPPED_H
#define FUNDAMENTAL_WINDOWS_STRIPPED_H

#include "definitions.h"
#include "types.h"
#include "compilerinfo.h"

#ifdef FUNDAMENTAL_SYSTEM_WINDOWS

startcblock

#define WINBASEAPI __declspec(dllimport) 
#define WINAPI __stdcall
#define VOID void
#define LPSTR char*
#define SIZE_T usize
#define DWORD u32
#define _Ret_maybenull_
#define LPVOID void*
#define LPCTSTR char*
#define _In_opt_
#define _In_ 
#define _Out_ 
#define _Post_writable_byte_size_(x)
#define BOOL int

#if _MSC_VER < 1900
#define DECLSPEC_ALLOCATOR
#else
#define DECLSPEC_ALLOCATOR __declspec(allocator)
#endif

	typedef void* HANDLE;

#define GENERIC_WRITE 0x40000000
#define GENERIC_READ 0x80000000

#define FILE_SHARE_READ 0x00000001
#define FILE_SHARE_WRITE 0x00000002
#define FILE_SHARE_DELETE 0x00000004

#define CREATE_ALWAYS 2
#define CREATE_NEW 1
#define OPEN_ALWAYS 4
#define OPEN_EXISTING 3
#define TRUNCATE_EXISTING 5

#define _Out_opt_
#define _Inout_opt_
#define LPDWORD u32*

#define LONG long
#define LONGLONG long long
#define PVOID void*
#define HWND void*
#define ULONG_PTR unsigned long*

typedef struct _SECURITY_ATTRIBUTES {
	DWORD  nLength;
	LPVOID lpSecurityDescriptor;
	BOOL   bInheritHandle;
} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;


typedef struct _OVERLAPPED {
	ULONG_PTR Internal;
	ULONG_PTR InternalHigh;
	union {
		struct {
			DWORD Offset;
			DWORD OffsetHigh;
		};
		PVOID  Pointer;
	};
	HANDLE    hEvent;
} OVERLAPPED, *LPOVERLAPPED;

#define INVALID_HANDLE_VALUE (HANDLE)((u64)(-1))

#define DELETE                           (0x00010000L)
#define READ_CONTROL                     (0x00020000L)
#define WRITE_DAC                        (0x00040000L)
#define WRITE_OWNER                      (0x00080000L)
#define SYNCHRONIZE                      (0x00100000L)

#define STANDARD_RIGHTS_REQUIRED         (0x000F0000L)

#define STANDARD_RIGHTS_READ             (READ_CONTROL)
#define STANDARD_RIGHTS_WRITE            (READ_CONTROL)
#define STANDARD_RIGHTS_EXECUTE          (READ_CONTROL)

#define STANDARD_RIGHTS_ALL              (0x001F0000L)

#define SPECIFIC_RIGHTS_ALL              (0x0000FFFFL)

#define STD_ERROR_HANDLE (DWORD)-12
#define STD_OUTPUT_HANDLE (DWORD)-11
#define STD_INPUT_HANDLE (DWORD)-10
#define _Reserved_

BOOL WINAPI WriteConsoleA(
	_In_             HANDLE  hConsoleOutput,
	_In_       const VOID    *lpBuffer,
	_In_             DWORD   nNumberOfCharsToWrite,
	_Out_            LPDWORD lpNumberOfCharsWritten,
	_Reserved_       LPVOID  lpReserved
);

WINBASEAPI LPSTR WINAPI GetCommandLineA(VOID);
WINBASEAPI _Ret_maybenull_ HANDLE WINAPI HeapCreate( _In_ DWORD flOptions, _In_ SIZE_T dwInitialSize, _In_ SIZE_T dwMaximumSize );
BOOL WINAPI HeapFree(
	_In_ HANDLE hHeap,
	_In_ DWORD  dwFlags,
	_In_ LPVOID lpMem
);
HANDLE WINAPI GetStdHandle(
	_In_ DWORD nStdHandle
);
WINBASEAPI _Ret_maybenull_ _Post_writable_byte_size_(dwBytes) DECLSPEC_ALLOCATOR LPVOID WINAPI HeapAlloc( _In_ HANDLE hHeap, _In_ DWORD dwFlags, _In_ SIZE_T dwBytes );
HANDLE WINAPI CreateFileA(
	_In_     LPCTSTR               lpFileName,
	_In_     DWORD                 dwDesiredAccess,
	_In_     DWORD                 dwShareMode,
	_In_opt_ LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	_In_     DWORD                 dwCreationDisposition,
	_In_     DWORD                 dwFlagsAndAttributes,
	_In_opt_ HANDLE                hTemplateFile
);

typedef union _LARGE_INTEGER {
	struct {
		DWORD LowPart;
		LONG  HighPart;
	};
	struct {
		DWORD LowPart;
		LONG  HighPart;
	} u;
	LONGLONG QuadPart;
} LARGE_INTEGER, *PLARGE_INTEGER;

BOOL WINAPI CloseHandle(
	_In_ HANDLE hObject
);

BOOL WINAPI ReadFile(
	_In_        HANDLE       hFile,
	_Out_       LPVOID       lpBuffer,
	_In_        DWORD        nNumberOfBytesToRead,
	_Out_opt_   LPDWORD      lpNumberOfBytesRead,
	_Inout_opt_ LPOVERLAPPED lpOverlapped
);

BOOL WINAPI GetFileSizeEx(
	_In_  HANDLE         hFile,
	_Out_ PLARGE_INTEGER lpFileSize
);

DWORD WINAPI GetLastError(void);

HWND WINAPI GetConsoleWindow(void);

endcblock

#endif
#endif