#pragma once

#include "framework.h"

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
#include <format>

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
//		## �̱��� ##
//===========================================
#include "TimeManager.h"	//Time
#include "InputManager.h"	//Input


//===========================================
//		## ���� ���� ���� ##
//===========================================
extern HINSTANCE _hInstance;	// instance => ���α׷�(�ν��Ͻ�) ��ü
extern HWND _hWnd;				// wnd => ������ ��ü
