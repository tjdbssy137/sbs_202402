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
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char* lpszCmdParam, int nCmdShow);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char* lpszCmdParam, int nCmdShow)
{
	_hInstance = hInstance;
	//====================================
	//		## 1. ������ ��� ##
	//====================================
	// RegisterClass ������ ���
	
	//WNDCLASS : ������ ����ü ( �����츦 �������ֱ� ���� ���� ���� )
	WNDCLASS wndClass = {};
	wndClass.cbClsExtra = 0;										// Ŭ���� ���� �޸�
	wndClass.cbWndExtra = 0;										// ������ ���� �޸�
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//��׶��� ��
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					//Ŀ��
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				//������
	wndClass.hInstance = _hInstance;								//�ν��Ͻ� �ڵ�
	wndClass.lpfnWndProc = (WNDPROC)WndProc;						//### �����߿� ### : ������ ���ν���
	wndClass.lpszClassName = _T("SBS Academy");						//Ŭ���� �̸�
	wndClass.lpszMenuName = NULL;									//�޴� �̸�
	wndClass.style = CS_HREDRAW | CS_VREDRAW;						//������ ��Ÿ��

	::RegisterClass(&wndClass);

	//====================================
	//		## 2. ������ ���� ##
	//====================================
	// CreateWindow ������ �����Լ�

	_hWnd = CreateWindow(
		_T("SBS Academy")				//Ŭ���� �̸�
		, _T("SBS Academy")				//������ �̸�
		, WS_CAPTION | WS_SYSMENU		//������ ��Ÿ��
		, 0								//x
		, 0								//y
		, 800							//width
		, 600							//height
		, NULL							//�θ� ������
		, NULL							//�޴� �ڵ�
		, _hInstance					//����� �ν��Ͻ� �ڵ�
		, NULL							//�θ� ���� ����������, � ���ڷ� �����ߴ���
	);

	SetWindowSize(0, 0, 800, 600);


	//====================================
	//		## 3. ������ ��� ##
	//====================================
	//ShowWindow

	::ShowWindow(_hWnd, nCmdShow);

	//====================================
	//		## 4. �޼��� ���� ##
	//====================================

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

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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

	AdjustWindowRect(&rc, WS_CAPTION | WS_SYSMENU, NULL);

	SetWindowPos(_hWnd, NULL, x, y, rc.right - rc.left, rc.bottom - rc.top, SWP_NOZORDER | SWP_NOMOVE);
}