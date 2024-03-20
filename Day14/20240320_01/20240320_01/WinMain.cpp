//windows api
// 
// ������Ʈ �Ӽ� - ��Ŀ - �ý��� - â���� ����
// ������Ʈ �Ӽ� - C/C++ - ��ó���� - _DEBUG;_Windows;%(PreprocessorDefinitions)
//==========================
//		## ������� ���� ##
//==========================
#include "pch.h"

//==========================
//		## �������� ���� ##
//==========================
HINSTANCE _hInstance;
HWND _hWnd;

//==========================
//		## �Լ� ���� ���� ##
//==========================
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM IParm);
void SetWindowSize(int x, int y, int width, int height);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	_hInstace = hInstance;
	//1. ������ ���
	// WNDCLASS : ������ ����ü (�����츦 �������ֱ� ���� ���� ����)
	WNDCLASS wndClass = {};
	wndClass.cbClsExtra = 0;										// Ŭ���� ���� �޸�
	wndClass.cbWndExtra = 0;										// ������ ���� �޸� 
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// background color
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					// cursor
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// icon
	wndClass.hInstance = _hInstace;									// �ν���Ʈ �ڵ�
	wndClass.lpfnWndProc = (WNDPROC)WndProc;						// <���� �߿�> ������ ���ν���
	wndClass.lpszClassName = _T("SBS Academy");						// Ŭ���� �̸�
	wndClass.lpszMenuName = NULL;									// �޴� �̸�
	wndClass.style = CS_HREDRAW | CS_VREDRAW;						// ������ ��Ÿ��

	::RegisterClass(&wndClass);

	//2. ������ ����
	_hWnd = CreateWindow(
		_T("SBS Academy"),			// Ŭ���� �̸�
		_T("SBS Academy"),			// ������ �̸�
		WS_CAPTION | WS_SYSMENU,	// ������ ��Ÿ��
		0,							// x
		0,							// y
		800,						// width
		600,						// height
		NULL,						// �θ� ������
		NULL,						// �޴� �ڵ�
		_hInstace,					// ����� �ν��Ͻ� �ڵ�
		NULL						// �θ� ���� �������� ��, � ���ڷ� �����ߴ���
	);
	SetWindowSize(0, 0, 800, 600);

	//3. ������ ���
	::ShowWindow(_hWnd, nCmdShow);

	//4. �޼��� ����
	MSG message;
	while (true)
	{
		if (::PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			::TranslateMessage(&message);
			::DispatchMessage(&message);
		}
		else
		{

		}
	}
	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM IParam)
{
	switch (message)
	{
	//case WM_MOUSEMOVE:
	//	PostQuitMessage(0);
	//	break;
	case WM_DESTROY:
		PostQuitMessage(0);// ���α׷��� ���ڴ�.
		break;
	delfault:
		return DefWindowProc(hWnd, message, wParam, IParam);
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

	AdjustWindowRect(&rc, WS_CAPTION | WS_SYSMENU, NULL);
	//SetWindowPos(_hWnd, x, y, rc.right - rc.left);
}