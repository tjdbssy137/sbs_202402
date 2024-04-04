#pragma once
class Game
{
public:
	Game();
	~Game();

public:
	void Init(HWND hwnd);
	void Update();
	void Render();

private:
	HWND _hwnd;
	HDC _hdc;		//�������� ������ ȭ��


private:
	//������۸� ����
	RECT _rect = {};		//ũ��
	HDC _hdcBack = {};		//�������� ������ �ʴ� ȭ��
	HBITMAP _bmpBack = {};	//ȭ�鿡 �׸� ����

private:
	RECT _player = {};
	RECT _enemy = {};

private:
	//RECT _rectangle[9] = {};
	//bool _toggle = false;
	//int _gugudan = 1;
private:
	vector<RECT> _gugudanVec;
	int _dan = 1;
};
