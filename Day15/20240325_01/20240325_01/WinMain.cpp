#include "pch.h"
// 프로젝트 속성 - 링커 - 시스템 - 창으로 수정
// 프로젝트 속성 - C/C++ - 전처리기 - _DEBUG;_Windows;%(PreprocessorDefinitions)
HINSTANCE _hInstance;
HWND _hWnd;

LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void SetWindowSize(int x, int y, int width, int height);
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrewInstance, char* lpszCmdParam, int nCmdShow)
{
	_hInstance = hInstance;
	WNDCLASS wndClass = {};
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursorW(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIconW(NULL, IDI_APPLICATION);
	wndClass.hInstance = _hInstance;
	wndClass.lpfnWndProc = (WNDPROC)WinProc;
	wndClass.lpszClassName = _T("SBS ACADEMY");
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	::RegisterClass(&wndClass);

	_hWnd = CreateWindow(
		_T("SBS ACADEMY"),
		_T("SBS ACADEMY"),
		WS_CAPTION | WS_SYSMENU,
		0,
		0,
		800,
		600,
		NULL,
		NULL,
		_hInstance,
		NULL
	);

	::SetWindowSize(0, 0, 800, 600);
	::ShowWindow(_hWnd, nCmdShow);

	MSG massage;
	while (true)
	{
		if (::PeekMessage(&massage, NULL, 0, 0, PM_REMOVE))
		{
			::TranslateMessage(&massage);
			::DispatchMessage(&massage);
		}
		else
		{

		}
	}
}

LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
}

void SetWindowSize(int x, int y, int width, int height)
{
	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = width;
	rc.bottom = height;

	AdjustWindowRect(&rc, WS_CAPTION | WS_SYSMENU, FALSE);
	SetWindowPos(_hWnd, NULL, x, y, rc.right - rc.left, rc.bottom - rc.top, SWP_NOZORDER | SWP_NOMOVE);
}