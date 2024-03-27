// WindowsGame.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "pch.h"
#include "WindowsGame.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE _hInstance;
HWND _hWnd;
POINT _mousePos; // 마우스 좌표

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    // TODO: 여기에 코드를 입력합니다.

    // 1. 클래스 등록
    MyRegisterClass(hInstance);

    // 2. 클래스 생성
    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    MSG msg;

    // 3. 메세지 루프
    // 마우스를 움직였나?
    // 키보드를 눌렀나?
    // 다른 시스템적인 무언가가 왔나?
    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}


//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc; // *중요* 아래서 메세지 처리
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSGAME));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = nullptr;
    wcex.lpszClassName  = _T("WINDOWS GAME");
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   _hInstance = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(_T("WINDOWS GAME"), _T("GAME CLIENT"), WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_MOUSEMOVE:
        _mousePos.x = GET_X_LPARAM(lParam);
        _mousePos.y = GET_Y_LPARAM(lParam);
        ::InvalidateRect(_hWnd, NULL, true);
        break;
        // 화면을 그려라.라는 메세지가 왔을 때 처리하는 곳

    case WM_KEYDOWN:
        if (wParam == 'A')
        {

        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps; // 그림 도구
            HDC hdc = BeginPaint(hWnd, &ps); //도화지
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            // 가장 간단한 함수
            // 사각형 그리기
            ::Rectangle(hdc, 100, 100, 200, 200);
            
            // 원 그리기
            ::Ellipse(hdc, 250, 250, 350, 350);


            wchar_t str[128];

            // <마우스 좌표>
            wsprintf(str, L"%d X %d", _mousePos.x, _mousePos.y);
            ::TextOut(hdc, 400, 400, str, _tcsclen(str));

            
            {// <구구단>
                int a = 1;
                int b = 0;
                for (int i = 1; i < 10; i++)
                {
                    for (int j = 1; j < 10; j++)
                    {
                        wsprintf(str, L"%d X %d = %d", i, j, i * j);
                        ::TextOut(hdc, a * 100, j * 15 + b, str, _tcsclen(str));
                    }
                    a++;
                    if (a % 3 == 1 && a != 1)
                    {
                        a = 1;
                        b += 150;
                    }
                }
            }
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY: 
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}