#include "pch.h"
#include "Dev1Scene.h"

void Dev1Scene::Init()
{
	Super::Init();
	_player = {Vector2(250, 250), 100, 100};
}
void Dev1Scene::Render(HDC hdc) {
	Super::Render(hdc);

	wstring str = L"Dev1Scene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());
	
	_player.Draw(hdc);
}
void Dev1Scene::Update()
{
	Super::Update();
	if (Input->GetKey(KeyCode::Control) && Input->GetKeyDown(KeyCode::RightMouse))//not work
	{// 두 개를 입력 받을 때에는 둘 중 하나는 GetKey로 해야함. 둘 다 GetKeyDown으로 받으면 한 프레임에 동시에 두 개 눌러야 함.
		GET_SINGLE(SceneManager)->ChangeScene(SceneType::Dev2Scene);
	}

	/*
	if (Input->GetKey(KeyCode::Left))
	{
		_playerDir = Vector2(-1, 0);
		_player.pos += _playerDir * (Time->GetDeltaTime() * 100);
	}
	else if (Input->GetKey(KeyCode::Up))
	{
		_playerDir = Vector2(0, -1);
		_player.pos += _playerDir * (Time->GetDeltaTime() * 100);
	}
	else if (Input->GetKey(KeyCode::Right))
	{
		_playerDir = Vector2(1, 0);
		_player.pos += _playerDir * (Time->GetDeltaTime() * 100);
	}
	else if (Input->GetKey(KeyCode::Down))
	{
		_playerDir = Vector2(0, 1);
		_player.pos += _playerDir * (Time->GetDeltaTime() * 100);
	}
	*/

	if (Input->GetKeyDown(KeyCode::RightMouse))
	{
		POINT pt = Input->GetMousePos();
		_targetPos = Vector2(pt.x, pt.y);
		_playerDir = (_targetPos - _player.pos).Normalize();
	}
	
	if(2 < (_targetPos - _player.pos).Length())
	{
		_player.pos += _playerDir * (Time->GetDeltaTime() * 100);
	}
}
void Dev1Scene::Release()
{
	Super::Release();
}