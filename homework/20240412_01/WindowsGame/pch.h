#pragma once

#include "framework.h"

//===========================================
//		## WindowsGame 커스텀 헤더 ##
//===========================================
#include "Defines.h"
#include "Types.h"
#include "CommonFunction.h"
#include "Enums.h"

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
#include <unordered_set>
#include <map>
#include <set>

//===========================================
//		## NAMESPACE ##
//===========================================
using namespace std;


//===========================================
//		## 싱글톤 ##
//===========================================
#include "TimeManager.h"	// Time
#include "InputManager.h"	// Input
#include "SceneManager.h"	// Scene Manager
#include "CollisionManager.h" // CollisionManager

//===========================================
//		## Windows Size ##
//===========================================

#define WIN_SIZE_X 1280
#define WIN_SIZE_Y 720

//===========================================
//		## 전역 변수 선언 ##
//===========================================
extern HINSTANCE _hInstance;	// instance => 프로그램(인스턴스) 객체
extern HWND _hWnd;				// wnd => 윈도우 객체
