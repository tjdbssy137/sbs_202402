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

	_enemy.left = 550;
	_enemy.right = 600;
	_enemy.top = 100;
	_enemy.bottom = 150;

	int a = 0;
	int b = 0;
	for (int i = 1; i <= 9; i++)
	{
		_rectangle[i - 1].left = 200 + a;
		_rectangle[i - 1].right = 300 + a;
		_rectangle[i - 1].top = 200 + b;
		_rectangle[i - 1].bottom = 300 + b;
		a += 110;
		if (i % 3 == 0)
		{
			a = 0;
			b += 110;
		}
	}
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
	POINT _direction = {};
	int _moveDistance = 10;
	if (Input->GetKeyDown(KeyCode::Right))
	{
		_player.left += _moveDistance;
		_player.right += _moveDistance;
		_direction = { 0, 1 };
	}
	else if (Input->GetKeyDown(KeyCode::Left))
	{
		_player.left -= _moveDistance;
		_player.right -= _moveDistance;
		_direction = { 0, -1 };
	}
	else if (Input->GetKeyDown(KeyCode::Up))
	{
		_player.top -= _moveDistance;
		_player.bottom -= _moveDistance;
		_direction = { -1, 0 };
	}
	else if (Input->GetKeyDown(KeyCode::Down))
	{
		_player.top += _moveDistance;
		_player.bottom += _moveDistance;
		_direction = { 1, 0 };
	}

	// _enemy���� �浹&�̵� ��ũ��Ʈ
	if (Collision::RectInRect(_player, _enemy))
	{
		//::MessageBox(_hwnd, L"�浹�Ǿ����ϴ�", L"�˸�", 0);
		_enemy.left += _moveDistance * _direction.y;
		_enemy.right += _moveDistance * _direction.y;
		_enemy.top += _moveDistance * _direction.x;
		_enemy.bottom += _moveDistance * _direction.x;
	}


	// ���콺 Ŭ�� ��ũ��Ʈ
	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		POINT mousePosUpdate = Input->GetMousePos();
		for (int i = 0; i < 9; i++)
		{
			if (Collision::PtInRect(mousePosUpdate, _rectangle[i]))
			{
				::MessageBox(_hwnd, (L"_rectangle(" + ::to_wstring(i + 1) + L")�� �����Ͽ����ϴ�.").c_str(), L"�˸�", 0);
			}
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

	for (int i = 0; i < 9; i++)
	{
		::Rectangle(_hdcBack, _rectangle[i].left, _rectangle[i].top, _rectangle[i].right, _rectangle[i].bottom);
	}

	//��Ʈ�� : ��� ����
	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY);
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);
}