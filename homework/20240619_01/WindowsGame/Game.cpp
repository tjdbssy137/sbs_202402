#include "pch.h"
#include "Game.h"

Game::Game()
{

}
Game::~Game()
{
	GET_SINGLE(ResourceManager)->Release();
	GET_SINGLE(SoundManager)->Release();
	Datas->Release();
	UserDatas->Release();
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

	SetBkMode(_hdcBack, TRANSPARENT); // �۾� ���� �Ͼ�� ���

	//�̱��� �ʱ�ȭ
	Events->Init();

	Time->Init();
	Input->Init(_hwnd);
	GET_SINGLE(SceneManager)->Init();
	GET_SINGLE(CollisionManager)->Init();
	GET_SINGLE(ResourceManager)->Init();	
	Datas->Init();
	UserDatas->Init();

	GET_SINGLE(SoundManager)->Init();

	GET_SINGLE(SceneManager)->ChangeScene(SceneType::TowerDefenseScene);
}
void Game::Update()
{
	//�̱��� ������Ʈ
	Events->Update();
	Time->Update();
	Input->Update();
	GET_SINGLE(SceneManager)->Update();
	GET_SINGLE(CollisionManager)->Update();
}
void Game::Render()
{
	GET_SINGLE(SceneManager)->Render(_hdcBack);

	//��Ʈ�� : ��� ����
	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY);
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);
}