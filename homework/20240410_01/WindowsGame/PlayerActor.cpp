#include "pch.h"
#include "PlayerActor.h"
#include "Collider.h"

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

	if (Input->GetKeyDown(KeyCode::RightMouse) && _name == "Ball")
	{
		//마우스 클릭했을때 플레이어가 움직여줄 방향을 정해준다.
		POINT pt = Input->GetMousePos();
		_targetPos = Vector2(pt.x, pt.y);
		_moveDir = (_targetPos - _body.pos).Normalize();
	}
	_body.pos += _moveDir * (Time->GetDeltaTime() * 150);

	/*
	if (Input->GetKey(KeyCode::A) && _name == "Player")
	{
		_moveDir = Vector2(-1, 0);
		_body.pos += _moveDir * (Time->GetDeltaTime() * 50);
	}
	else if (Input->GetKey(KeyCode::D) && _name == "Player")
	{
		_moveDir = Vector2(1, 0);
		_body.pos += _moveDir * (Time->GetDeltaTime() * 50);
	}
	*/

}
void PlayerActor::Release()
{
	Super::Release();
}

void PlayerActor::OnTriggerEnter(Collider* collider, Collider* other)
{
	Super::OnTriggerEnter(collider, other);
	if (collider->GetOwner()->GetName() == "Ball")
	{
		cout << "ball and player reflect " << endl;
		//_moveDir = _moveDir.Reflect(Vector2(0,1)).Normalize();
	}
}