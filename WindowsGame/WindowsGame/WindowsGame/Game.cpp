#include "pch.h"
#include "Game.h"

Game::Game()
{

}
Game::~Game()
{

}

void Game::Init(HWND hwnd)
{
	this->_hwnd = hwnd;
	this->_hdc = ::GetDC(this->_hwnd); // �������� ������ ȭ��

	//������۸�
	::GetClientRect(_hwnd, &_rect); // ������ �ڵ鿡 ũ�⸦ �������ְڴ�.

	_hdcBack = ::CreateCompatibleDC(_hdc);// �������� ������ �ʴ� ȭ�� ����, _hdc�� �Ȱ��� ���� ����
	_bmpBack = ::CreateCompatibleBitmap(_hdc, _rect.right, _rect.bottom); // _hdc�� ȣȯ�Ǵ� ��Ʈ�� ����
	HBITMAP prev = (HBITMAP)::SelectObject(_hdcBack, _bmpBack); //  _hdcBack�� _bmp����
	//_hdcBack�� ������ ���� �ִ� ���� prev�� return. SelectObject�� ��Ư�� �Լ���.
	::DeleteObject(prev); // ������ ����� �� �� ����
	

	//�̱��� �ʱ�ȭ
	GET_SINGLE(TimeManager)->Init();
}

void Game::Update()
{
	GET_SINGLE(TimeManager)->Update();
	_x++;
}

void Game::Render()
{
	//FPS ���
	{
		uint32 fps = GET_SINGLE(TimeManager)->GetFps();
		float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

		wstring timeStr = format(L"FPS({0}), DT({1} ms)", fps, static_cast<int32>(deltaTime * 1000));
		::TextOut(_hdcBack, 0, 0, timeStr.c_str(), timeStr.length()); // �������� ������ �ʴ� ���� �ۼ�
	}


	wstring str = L"���ع��� ��λ��� ������ �⵵�� �ϴ����� �����ϻ� �츮���� ����. ����ȭ ��õ�� ȭ������ ���ѻ�� �������� ���� �����ϼ�.";
	::TextOut(_hdcBack, 100 + _x % 700, 100, str.c_str(), str.length()); // �������� ������ �ʴ� ���� �ۼ�
	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY);
	//BitBlt ��� ����
	//_hdcBack�� �ִ� ���� _hdc�� �ű�µ�. (0, 0)���� _rect.right���� _rect.bottom���� SRCCOPY�������� ����
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);
	// _hdcBack�� WHITENESS�� ����ϰ� ����
}