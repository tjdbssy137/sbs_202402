#pragma once

#include "framework.h"
#include <Windows.h>
#include <Windowsx.h>
//===========================================
//		## WindowsGame Ŀ���� ��� ##
//===========================================
#include "Defines.h"
#include "Types.h"
#include "CommonFunction.h"

#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")

//===========================================
//		## C++ ���� �Լ� ##
//===========================================
#include <iostream>
#include <algorithm>

#include <string>
#include <tchar.h>

//===========================================
//		## �ڷ� ���� ##
//===========================================
#include <vector>
#include <unordered_map>
#include <map>

//===========================================
//		## NAMESPACE ##
//===========================================
using namespace std;


//===========================================
//		## ���� ���� ���� ##
//===========================================
extern HINSTANCE _hInstance;	// instance => ���α׷�(�ν��Ͻ�) ��ü
extern HWND _hWnd;				// wnd => ������ ��ü
extern POINT _mousePos;			// ���콺 ��ǥ