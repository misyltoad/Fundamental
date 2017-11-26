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
#define LPWSTR wchar_t*
#define SIZE_T usize
#define DWORD unsigned long
#define _Ret_maybenull_
#define LPVOID void*
#define LPCWSTR wchar_t*
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

#define LPARAM isize
#define LRESULT isize
#define WPARAM usize
#define CALLBACK __stdcall

#define UCHAR unsigned char

#define UINT unsigned int
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

typedef HANDLE HINSTANCE;
typedef HANDLE HICON;
typedef HANDLE HCURSOR;
typedef HANDLE HBRUSH;
typedef HANDLE HMENU;
typedef HANDLE HMODULE;
typedef unsigned short ATOM;

#define LPCTSTR char*


/*
* Window Styles
*/
#define WS_OVERLAPPED       0x00000000L
#define WS_POPUP            0x80000000L
#define WS_CHILD            0x40000000L
#define WS_MINIMIZE         0x20000000L
#define WS_VISIBLE          0x10000000L
#define WS_DISABLED         0x08000000L
#define WS_CLIPSIBLINGS     0x04000000L
#define WS_CLIPCHILDREN     0x02000000L
#define WS_MAXIMIZE         0x01000000L
#define WS_CAPTION          0x00C00000L     /* WS_BORDER | WS_DLGFRAME  */
#define WS_BORDER           0x00800000L
#define WS_DLGFRAME         0x00400000L
#define WS_VSCROLL          0x00200000L
#define WS_HSCROLL          0x00100000L
#define WS_SYSMENU          0x00080000L
#define WS_THICKFRAME       0x00040000L
#define WS_GROUP            0x00020000L
#define WS_TABSTOP          0x00010000L

#define WS_MINIMIZEBOX      0x00020000L
#define WS_MAXIMIZEBOX      0x00010000L

#define UNALIGNED

#define WS_OVERLAPPEDWINDOW (WS_OVERLAPPED     | \
                             WS_CAPTION        | \
                             WS_SYSMENU        | \
                             WS_THICKFRAME     | \
                             WS_MINIMIZEBOX    | \
                             WS_MAXIMIZEBOX)

#define WS_POPUPWINDOW      (WS_POPUP          | \
                             WS_BORDER         | \
                             WS_SYSMENU)

#define WS_CHILDWINDOW      (WS_CHILD)

#define WS_TILED            WS_OVERLAPPED
#define WS_ICONIC           WS_MINIMIZE
#define WS_SIZEBOX          WS_THICKFRAME
#define WS_TILEDWINDOW      WS_OVERLAPPEDWINDOW



#define CW_USEDEFAULT       ((int)0x80000000)

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

typedef struct tagWNDCLASSEX {
	UINT      cbSize;
	UINT      style;
	WNDPROC   lpfnWndProc;
	int       cbClsExtra;
	int       cbWndExtra;
	HINSTANCE hInstance;
	HICON     hIcon;
	HCURSOR   hCursor;
	HBRUSH    hbrBackground;
	LPCTSTR   lpszMenuName;
	LPCTSTR   lpszClassName;
	HICON     hIconSm;
} WNDCLASSEX, *PWNDCLASSEX;


typedef struct tagPOINT {
	LONG x;
	LONG y;
} POINT, *PPOINT;


typedef struct tagMSG {
	HWND   hwnd;
	UINT   message;
	WPARAM wParam;
	LPARAM lParam;
	DWORD  time;
	POINT  pt;
} MSG, *PMSG, *LPMSG;

#define WM_NULL                         0x0000
#define WM_CREATE                       0x0001
#define WM_DESTROY                      0x0002
#define WM_MOVE                         0x0003
#define WM_SIZE                         0x0005

#define WM_ACTIVATE                     0x0006
/*
* WM_ACTIVATE state values
*/
#define     WA_INACTIVE     0
#define     WA_ACTIVE       1
#define     WA_CLICKACTIVE  2

#define WM_SETFOCUS                     0x0007
#define WM_KILLFOCUS                    0x0008
#define WM_ENABLE                       0x000A
#define WM_SETREDRAW                    0x000B
#define WM_SETTEXT                      0x000C
#define WM_GETTEXT                      0x000D
#define WM_GETTEXTLENGTH                0x000E
#define WM_PAINT                        0x000F
#define WM_CLOSE                        0x0010
#ifndef _WIN32_WCE
#define WM_QUERYENDSESSION              0x0011
#define WM_QUERYOPEN                    0x0013
#define WM_ENDSESSION                   0x0016
#endif
#define WM_QUIT                         0x0012
#define WM_ERASEBKGND                   0x0014
#define WM_SYSCOLORCHANGE               0x0015
#define WM_SHOWWINDOW                   0x0018
#define WM_WININICHANGE                 0x001A
#if(WINVER >= 0x0400)
#define WM_SETTINGCHANGE                WM_WININICHANGE
#endif /* WINVER >= 0x0400 */


#define WM_DEVMODECHANGE                0x001B
#define WM_ACTIVATEAPP                  0x001C
#define WM_FONTCHANGE                   0x001D
#define WM_TIMECHANGE                   0x001E
#define WM_CANCELMODE                   0x001F
#define WM_SETCURSOR                    0x0020
#define WM_MOUSEACTIVATE                0x0021
#define WM_CHILDACTIVATE                0x0022
#define WM_QUEUESYNC                    0x0023

#define WM_GETMINMAXINFO                0x0024

#define HDC HANDLE

#define BYTE char

#define WHITE_BRUSH         0
#define LTGRAY_BRUSH        1
#define GRAY_BRUSH          2
#define DKGRAY_BRUSH        3
#define BLACK_BRUSH         4
#define NULL_BRUSH          5
#define HOLLOW_BRUSH        NULL_BRUSH
#define WHITE_PEN           6
#define BLACK_PEN           7
#define NULL_PEN            8
#define OEM_FIXED_FONT      10
#define ANSI_FIXED_FONT     11
#define ANSI_VAR_FONT       12
#define SYSTEM_FONT         13
#define DEVICE_DEFAULT_FONT 14
#define DEFAULT_PALETTE     15
#define SYSTEM_FIXED_FONT   16

typedef struct _RECT {
	LONG left;
	LONG top;
	LONG right;
	LONG bottom;
} RECT, *PRECT;


BOOL InvalidateRect(
	_In_       HWND hWnd,
	_In_ const RECT *lpRect,
	_In_       BOOL bErase
);

BOOL UpdateWindow(
	_In_ HWND hWnd
);

BOOL WINAPI GetClientRect(
	_In_  HWND   hWnd,
	_Out_ PRECT lpRect
);

int FillRect(
	_In_       HDC    hDC,
	_In_ const RECT   *lprc,
	_In_       HBRUSH hbr
);

#define WORD ATOM
#define RGB(r,g,b)          ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))

typedef struct tagPAINTSTRUCT {
	HDC  hdc;
	BOOL fErase;
	RECT rcPaint;
	BOOL fRestore;
	BOOL fIncUpdate;
	BYTE rgbReserved[32];
} PAINTSTRUCT, *PPAINTSTRUCT, *LPPAINTSTRUCT;

HDC BeginPaint(
	_In_  HWND          hwnd,
	_Out_ LPPAINTSTRUCT lpPaint
);

BOOL EndPaint(
	_In_       HWND        hWnd,
	_In_ const PAINTSTRUCT *lpPaint
);


typedef DWORD COLORREF;
typedef DWORD* LPCOLORREF;
COLORREF SetPixel(
	_In_ HDC      hdc,
	_In_ int      X,
	_In_ int      Y,
	_In_ COLORREF crColor
);
HBRUSH CreateSolidBrush(
	_In_ COLORREF crColor
);

#define HGDIOBJ HANDLE

HGDIOBJ GetStockObject(
	_In_ int fnObject
);

LRESULT WINAPI DefWindowProcA(
	_In_ HWND   hWnd,
	_In_ UINT   Msg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
);

VOID RtlFillMemory(
	_Out_ VOID UNALIGNED *Destination,
	_In_  SIZE_T         Length,
	_In_  UCHAR          Fill
);


HMODULE WINAPI GetModuleHandleA(
	_In_opt_ LPSTR lpModuleName
);


ATOM WINAPI RegisterClassExA(
	_In_ const WNDCLASSEX *lpwcx
);


BOOL WINAPI ShowWindow(
	_In_ HWND hWnd,
	_In_ int  nCmdShow
);

BOOL WINAPI GetMessageA(
	_Out_    LPMSG lpMsg,
	_In_opt_ HWND  hWnd,
	_In_     UINT  wMsgFilterMin,
	_In_     UINT  wMsgFilterMax
);

BOOL WINAPI TranslateMessage(
	_In_ const MSG *lpMsg
);

LRESULT WINAPI DispatchMessageA(
	_In_ const MSG *lpmsg
);

HWND WINAPI CreateWindowExA(
	_In_     DWORD     dwExStyle,
	_In_opt_ LPCTSTR   lpClassName,
	_In_opt_ LPCTSTR   lpWindowName,
	_In_     DWORD     dwStyle,
	_In_     int       x,
	_In_     int       y,
	_In_     int       nWidth,
	_In_     int       nHeight,
	_In_opt_ HWND      hWndParent,
	_In_opt_ HMENU     hMenu,
	_In_opt_ HINSTANCE hInstance,
	_In_opt_ LPVOID    lpParam
);

HANDLE WINAPI GetProcessHeap(void);

LPWSTR* WINAPI CommandLineToArgvW(
	_In_  LPCWSTR lpCmdLine,
	_Out_ int     *pNumArgs
);

BOOL WINAPI WriteConsoleA(
	_In_             HANDLE  hConsoleOutput,
	_In_       const VOID    *lpBuffer,
	_In_             DWORD   nNumberOfCharsToWrite,
	_Out_            LPDWORD lpNumberOfCharsWritten,
	_Reserved_       LPVOID  lpReserved
);

BOOL WINAPI WriteConsoleW(
	_In_             HANDLE  hConsoleOutput,
	_In_       const VOID    *lpBuffer,
	_In_             DWORD   nNumberOfCharsToWrite,
	_Out_            LPDWORD lpNumberOfCharsWritten,
	_Reserved_       LPVOID  lpReserved
);

WINBASEAPI LPSTR WINAPI GetCommandLineA(VOID);
WINBASEAPI LPWSTR WINAPI GetCommandLineW(VOID);
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
	_In_     LPSTR				   lpFileName,
	_In_     DWORD                 dwDesiredAccess,
	_In_     DWORD                 dwShareMode,
	_In_opt_ LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	_In_     DWORD                 dwCreationDisposition,
	_In_     DWORD                 dwFlagsAndAttributes,
	_In_opt_ HANDLE                hTemplateFile
);

HANDLE WINAPI CreateFileW(
	_In_     LPWSTR				   lpFileName,
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