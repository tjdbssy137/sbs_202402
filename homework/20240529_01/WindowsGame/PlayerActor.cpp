#include "pch.h"
#include "PlayerActor.h"

void PlayerActor::Init()
{
	Super::Init();
}
void PlayerActor::Render(HDC hdc)
{
	Super::Render(hdc);

	_body.Draw(hdc);
}
void PlayerActor::Update()
{
	Super::Update();

	if (Input->GetKeyDown(KeyCode::RightMouse) && _name == "플레이어1")
	{
		//마우스 클릭했을때 플레이어가 움직여줄 방향을 정해준다.
		POINT pt = Input->GetMousePos();
		_targetPos = Vector2(pt.x, pt.y);
		_moveDir = (_targetPos - _body.pos).Normalize();
	}

	if (10 < (_targetPos - _body.pos).Length())
	{
		_body.pos += _moveDir * (Time->GetDeltaTime() * 100);
	}
}
void PlayerActor::Release()
{
	Super::Release();

}