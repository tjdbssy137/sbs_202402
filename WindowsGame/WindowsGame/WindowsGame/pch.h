#pragma once

#include "framework.h"
#include <Windows.h>
#include <Windowsx.h>
//===========================================
//		## WindowsGame 커스텀 헤더 ##
//===========================================
#include "Defines.h"
#include "Types.h"
#include "CommonFunction.h"

#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")

//===========================================
//		## C++ 관련 함수 ##
//===========================================
#include <iostream>
#include <algorithm>

#include <string>
#include <tchar.h>
#include <format>

//===========================================
//		## 자료 구조 ##
//===========================================
#include <vector>
#include <unordered_map>
#include <map>

//===========================================
//		## 싱글톤 ##
//===========================================
#include "TimeManager.h"

//===========================================
//		## NAMESPACE ##
//===========================================
using namespace std;


//===========================================
//		## 전역 변수 선언 ##
//===========================================
extern HINSTANCE _hInstance;	// instance => 프로그램(인스턴스) 객체
extern HWND _hWnd;				// wnd => 윈도우 객체
extern POINT _mousePos;			// 마우스 좌표