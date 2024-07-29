#pragma once

#include "framework.h"

//===========================================
//		## WindowsGame 커스텀 헤더 ##
//===========================================
#include "Defines.h"
#include "Types.h"
#include "Enums.h"
#include "DefineContents.h"

#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")

//===========================================
//		## RapidJson 라이브러리 ##
//===========================================
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
using namespace rapidjson;

//===========================================
//		## C++ 관련 함수 ##
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
//		## 자료 구조 ##
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
//		## 게임 데이터 ##
//===========================================
#include "Data.h"
#include "CommonFunction.h"
//===========================================
//		## 싱글톤 ##
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
//		## 전역 변수 선언 ##
//===========================================
extern HINSTANCE _hInstance;	// instance => 프로그램(인스턴스) 객체
extern HWND _hWnd;				// wnd => 윈도우 객체
