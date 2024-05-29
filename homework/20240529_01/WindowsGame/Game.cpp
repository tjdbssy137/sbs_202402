#include "pch.h"
#include "Game.h"


Game::Game()
{

}
Game::~Game()
{
	GET_SINGLE(ResourceManager)->Release();
	GET_SINGLE(SoundManager)->Release();
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
	GET_SINGLE(SceneManager)->Init();
	GET_SINGLE(CollisionManager)->Init();
	Resource->Init();
	Random->Init();
	GET_SINGLE(SoundManager)->Init();

	GET_SINGLE(SceneManager)->ChangeScene(SceneType::Dev1Scene);
}
void Game::Update()
{
	//�̱��� ������Ʈ
	Time->Update();
	Input->Update();
	GET_SINGLE(SceneManager)->Update();
	GET_SINGLE(CollisionManager)->Update();


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


	GET_SINGLE(SceneManager)->Render(_hdcBack);
	

	//��Ʈ�� : ��� ����
	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY);
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);
}