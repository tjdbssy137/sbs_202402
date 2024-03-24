//windows api
// 
// 프로젝트 속성 - 링커 - 시스템 - 창으로 수정
// 프로젝트 속성 - C/C++ - 전처리기 - _DEBUG;_Windows;%(PreprocessorDefinitions)
//==========================
//		## 헤더파일 선언 ##
//==========================
#include "pch.h"

//==========================
//		## 전역변수 선언 ##
//==========================
HINSTANCE _hInstance;
HWND _hWnd;

//==========================
//		## 함수 전방 선언 ##
//==========================
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM IParm);
void SetWindowSize(int x, int y, int width, int height);
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char* lpszCmdParam, int nCmdShow);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char* lpszCmdParam, int nCmdShow)
{
	_hInstance = hInstance;
	//====================================
	//		## 1. 윈도우 등록 ##
	//====================================
	// RegisterClass 윈도우 등록
	
	//WNDCLASS : 윈도우 구조체 ( 윈도우를 구성해주기 위해 쓰일 변수 )
	WNDCLASS wndClass = {};
	wndClass.cbClsExtra = 0;										// 클래스 여분 메모리
	wndClass.cbWndExtra = 0;										// 윈도우 여분 메모리
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//백그라운드 색
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					//커서
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				//아이콘
	wndClass.hInstance = _hInstance;								//인스턴스 핸들
	wndClass.lpfnWndProc = (WNDPROC)WndProc;						//### 제일중요 ### : 윈도우 프로시저
	wndClass.lpszClassName = _T("SBS Academy");						//클래스 이름
	wndClass.lpszMenuName = NULL;									//메뉴 이름
	wndClass.style = CS_HREDRAW | CS_VREDRAW;						//윈도우 스타일

	::RegisterClass(&wndClass);

	//====================================
	//		## 2. 윈도우 생성 ##
	//====================================
	// CreateWindow 윈도우 생성함수

	_hWnd = CreateWindow(
		_T("SBS Academy")				//클래스 이름
		, _T("SBS Academy")				//윈도우 이름
		, WS_CAPTION | WS_SYSMENU		//윈도우 스타일
		, 0								//x
		, 0								//y
		, 800							//width
		, 600							//height
		, NULL							//부모 윈도우
		, NULL							//메뉴 핸들
		, _hInstance					//사용할 인스턴스 핸들
		, NULL							//부모가 나를 생성했을때, 어떤 인자로 생성했는지
	);

	SetWindowSize(0, 0, 800, 600);


	//====================================
	//		## 3. 윈도우 출력 ##
	//====================================
	//ShowWindow

	::ShowWindow(_hWnd, nCmdShow);

	//====================================
	//		## 4. 메세지 루프 ##
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
		PostQuitMessage(0);// 프로그램을 끄겠다.
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