#pragma once

#include "framework.h"

//===========================================
//		## WindowsGame Ŀ���� ��� ##
//===========================================
#include "Defines.h"
#include "DefineContents.h"
#include "Types.h"
#include "Enums.h"
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

#include <fstream>
#include <functional>
#include <assert.h>

//===========================================
//		## �ڷ� ���� ##
//===========================================
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

//===========================================
//		## Sound ���� ##
//===========================================
#include <mmsystem.h>
#include <dsound.h>
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "dsound.lib")


//===========================================
//		## NAMESPACE ##
//===========================================
using namespace std;


//===========================================
//		## �̱��� ##
//===========================================
#include "TimeManager.h"	//Time
#include "InputManager.h"	//Input
#include "SceneManager.h"
#include "CollisionManager.h"
#include "ResourceManager.h"
#include "RandomManager.h"
#include "SoundManager.h"

//===========================================
//		## ������ ������ ##
//===========================================
#define WIN_SIZE_X 1280
#define WIN_SIZE_Y 900

//===========================================
//		## ���� ���� ���� ##
//===========================================
extern HINSTANCE _hInstance;	// instance => ���α׷�(�ν��Ͻ�) ��ü
extern HWND _hWnd;				// wnd => ������ ��ü
