#pragma once
//자주 사용하지만, 자주 변경되지 않는 내용들이 포함되는 헤더

//주로 쓰이는 내용들을 적어줌.

//프로젝트 - 속성 - C/C++ - 미리 컴파일된 헤더
// 사용으로 변경
// pch.h

// pch라는 클래스 생성 후 #pragma once 제외하고 전부 지움
// pch.cpp - 속성 - C/C++ - 미리 컴파일 된 헤더
// 만들기로 변경

//==========================
// API 관련 함수
//==========================

// windows API 라고 하는 게,
// windows 함수를 사용한다라는 의미
// <Windows.h>, <Windowsx.h> 여기에 들어있는게 windows 함수
#include <Windows.h>
#include <Windowsx.h>


//==========================
//C++ 관련 함수
//==========================
#include <iostream>
#include <algorithm>

#include <string>
#include <tchar.h>

//==========================
// 자료구조
//==========================
#include <vector>
#include <unordered_map>
#include <map>

//==========================
//NAMESPACE
//==========================
using namespace std;

//==========================
//전역 변수 선언
//==========================

extern HINSTANCE _hInstace; // instance => 프로그램 객체 그 자체 (ex: zoom, visual studio뭐 그런 것)
extern HWND _hWnd; // wnd => 윈도우 객체 => 프로그램 그 안에 있는 값 같은 것