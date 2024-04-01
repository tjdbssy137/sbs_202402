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
	this->_hdc = ::GetDC(this->_hwnd);

	//������۸�
	::GetClientRect(_hwnd, &_rect);		//�������ڵ��� ũ�⸦ ��ȯ�ϰڴ�.

	_hdcBack = ::CreateCompatibleDC(_hdc);	//_hdc�� ȣȯ�Ǵ� ȭ�� ����
	_bmpBack = ::CreateCompatibleBitmap(_hdc, _rect.right, _rect.bottom);	//_hdc�� ȣȯ�Ǵ� ��Ʈ�� ����
	HBITMAP prev = (HBITMAP)::SelectObject(_hdcBack, _bmpBack);	//_hdcBack�� _bmp ����
	::DeleteObject(prev);


	//�̱��� �ʱ�ȭ
	Time->Init();
	Input->Init(_hwnd);

	//------------------------------
	//	## �ڵ� ¥�� ��
	//------------------------------
	_player.left = 100;
	_player.right = 200;
	_player.top = 100;
	_player.bottom = 200;

	_enemy.left = 650;
	_enemy.right = 700;
	_enemy.top = 200;
	_enemy.bottom = 250;
}

void Game::Update()
{
	//�̱��� ������Ʈ
	Time->Update();
	Input->Update();

	//------------------------------
	//	## �ڵ� ¥�� ��
	//------------------------------
	//------------------------------
	//�ǽ�
	// 1. WASD �� ����Ű��,
	//    _player�� �����ϼ� �ְ��Ѵ�.
	// 2. _player�� _enmey�� �ε�����
	//   ::MessageBox(_hwnd, L"�˸�", L"�浹�Ǿ����ϴ�", 0);
	//  �� �����Ѵ�.
	//------------------------------
	
	// �̵� ��ũ��Ʈ
	if (Input->GetKeyDown(KeyCode::Right))
	{
		_player.left += 15;
		_player.right += 15;
	}
	else if (Input->GetKeyDown(KeyCode::Left))
	{
		_player.left -= 15;
		_player.right -= 15;
	}
	else if (Input->GetKeyDown(KeyCode::Up))
	{
		_player.top -= 15;
		_player.bottom -= 15;
	}
	else if (Input->GetKeyDown(KeyCode::Down))
	{
		_player.top += 15;
		_player.bottom += 15;
	}

	// _enemy���� �浹 ��ũ��Ʈ
	if(Collision::RectInRect(_player, _enemy))
	{
		::MessageBox(_hwnd, L"�浹�Ǿ����ϴ�", L"�˸�", 0);
	}

	// ���콺 Ŭ�� ��ũ��Ʈ
	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		POINT mousePosUpdate = Input->GetMousePos();
		if (Collision::PtInRect(mousePosUpdate, _player))
		{
			::MessageBox(_hwnd, L"�÷��̾ �����Ͽ����ϴ�.", L"�˸�", 0);
		}
	}
	
}
void Game::Render()
{
	//FPS ���
	{
		uint32 fps = Time->GetFps();
		float deltaTime = Time->GetDeltaTime();

		wstring timeStr = format(L"FPS({0}), DT({1} ms)", fps, static_cast<int32>(deltaTime * 1000));
		::TextOut(_hdcBack, 0, 0, timeStr.c_str(), timeStr.length());
	}

	//���콺��ǥ ���
	{
		POINT mousePos = Input->GetMousePos();
		wstring str = format(L"mouse({0}, {1})", mousePos.x, mousePos.y);
		::TextOut(_hdcBack, 0, 20, str.c_str(), str.length());
	}

	//------------------------------
	//	## �ڵ� ¥�� ��
	//------------------------------
	::Rectangle(_hdcBack, _player.left, _player.top, _player.right, _player.bottom);
	::Rectangle(_hdcBack, _enemy.left, _enemy.top, _enemy.right, _enemy.bottom);



	//��Ʈ�� : ��� ����
	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY);
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);
}