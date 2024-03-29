#pragma once
class Game
{
private:
	// �������
	HWND _hwnd; // _hWnd�� ���������� �ٸ� ����
	HDC _hdc; // �������� ������ ȭ��
private:
	RECT _rect = {}; // ũ��
	HDC _hdcBack = {}; // �������� ������ �ʴ� ȭ��
	HBITMAP _bmpBack = {}; // ȭ�鿡 �׸� ����
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

