#include "types.h"
#include "file.h"
#include "console.h"
#include "windows_stripped.h"
#include "random.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{

	case WM_PAINT:
		{

			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hwnd, &ps);

			HBRUSH blackBrushie = GetStockObject(BLACK_BRUSH);
			HBRUSH whiteBrushie = GetStockObject(WHITE_BRUSH);

			RECT rect;
			GetClientRect(hwnd, &rect);

			FillRect(hdc, &rect, blackBrushie);

			for (int i = 0; i < 200; i++)
			{
				RECT starRect;
				int x = random_number() % rect.right;
				int y = random_number() % rect.bottom;
				starRect.top = y;
				starRect.bottom = y + 2;
				starRect.left = x;
				starRect.right = x + 2;
				FillRect(hdc, &starRect, whiteBrushie);
			}

			EndPaint(hwnd, &ps);
			InvalidateRect(hwnd, &rect, 0);

		}
		return 0;
	default:
		return DefWindowProcA(hwnd, uMsg, wParam, lParam);
	}
}

nomangle i32 FundamentalMain()
{
	WNDCLASSEX wc;
	set_memory(&wc, 0, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = GetModuleHandleA(NULL);
	wc.lpszClassName = "Starfield";
	
	RegisterClassExA(&wc);

	HWND window = CreateWindowExA(0, wc.lpszClassName, wc.lpszClassName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, NULL, NULL, wc.hInstance, NULL);
	ShowWindow(window, 5);

	MSG msg;
	set_memory(&msg, 0, sizeof(MSG));

	while (GetMessageA(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}

	return 1;
}