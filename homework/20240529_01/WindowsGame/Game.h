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
	//------------------------------
	//	## �ڵ� ¥�� ��
	//------------------------------
	
	//
};

