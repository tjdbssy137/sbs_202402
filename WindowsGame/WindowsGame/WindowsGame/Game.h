#pragma once
class Game
{
private:
	// 멤버변수
	HWND _hwnd; // _hWnd는 전역변수로 다른 것임
	HDC _hdc; // 유저한테 보여줄 화면
private:
	RECT _rect = {}; // 크기
	HDC _hdcBack = {}; // 유저에게 보이지 않는 화면
	HBITMAP _bmpBack = {}; // 화면에 그릴 물감
private:
	int _x = 0;
public:
	Game();
	~Game();

public:
	void Init(HWND hwnd);
	void Update();
	void Render();

};

