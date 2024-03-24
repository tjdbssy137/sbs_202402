#pragma once
//���� ���������, ���� ������� �ʴ� ������� ���ԵǴ� ���

//�ַ� ���̴� ������� ������.

//������Ʈ - �Ӽ� - C/C++ - �̸� �����ϵ� ���
// ������� ����
// pch.h

// pch��� Ŭ���� ���� �� #pragma once �����ϰ� ���� ����
// pch.cpp - �Ӽ� - C/C++ - �̸� ������ �� ���
// ������ ����

//==========================
// API ���� �Լ�
//==========================

// windows API ��� �ϴ� ��,
// windows �Լ��� ����Ѵٶ�� �ǹ�
// <Windows.h>, <Windowsx.h> ���⿡ ����ִ°� windows �Լ�
#include <Windows.h>
#include <Windowsx.h>


//==========================
//C++ ���� �Լ�
//==========================
#include <iostream>
#include <algorithm>

#include <string>
#include <tchar.h>

//==========================
// �ڷᱸ��
//==========================
#include <vector>
#include <unordered_map>
#include <map>

//==========================
//NAMESPACE
//==========================
using namespace std;

//==========================
//���� ���� ����
//==========================

extern HINSTANCE _hInstace; // instance => ���α׷� ��ü �� ��ü (ex: zoom, visual studio�� �׷� ��)
extern HWND _hWnd; // wnd => ������ ��ü => ���α׷� �� �ȿ� �ִ� �� ���� ��