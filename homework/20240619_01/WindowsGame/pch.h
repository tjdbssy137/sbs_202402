#pragma once

#include "framework.h"

//===========================================
//		## WindowsGame Ŀ���� ��� ##
//===========================================
#include "Defines.h"
#include "Types.h"
#include "Enums.h"
#include "DefineContents.h"

#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")

//===========================================
//		## RapidJson ���̺귯�� ##
//===========================================
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
using namespace rapidjson;

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
#include <queue>

//===========================================
//		## SOUND ##
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
//		## ���� ������ ##
//===========================================
#include "Data.h"
#include "CommonFunction.h"
//===========================================
//		## �̱��� ##
//===========================================
#include "GameEventManager.h"
#include "TimeManager.h"	// Time
#include "InputManager.h"	// Input
#include "SceneManager.h"	// Scene Manager
#include "CollisionManager.h" // CollisionManager
#include "ResourceManager.h"
#include "RandomManager.h"
#include "SoundManager.h"
#include "DataManager.h"
#include "UserDataManager.h"

//===========================================
//		## Windows Size ##
//===========================================

#define WIN_SIZE_X 1280
#define WIN_SIZE_Y 900

//===========================================
//		## ���� ���� ���� ##
//===========================================
extern HINSTANCE _hInstance;	// instance => ���α׷�(�ν��Ͻ�) ��ü
extern HWND _hWnd;				// wnd => ������ ��ü
