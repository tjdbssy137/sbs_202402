#include "pch.h"
#include "BulletActor.h"
#include "BoatActor.h"
#include "TowerDefenseScene.h"

void BulletActor::Init()
{
	this->SetSprite(Resource->GetSprite(L"S_Bullet"));
	
	Super::Init();
}
void BulletActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void BulletActor::Update()
{
	Super::Update();
	switch (_state)
	{
	case BulletState::Move:
		Update_Move();
		break;
	case BulletState::Done:
	{
		this->SetPos({ 2000, 2000 });
	}
		break;
	default:
		break;
	}
}
void BulletActor::Release()
{
	Super::Release();
}
void BulletActor::Update_Move()
{
	if(_targetBoat->GetCellPos() == STARTPOS) // _targetBoat->GetState() == Goal or Die
	//if (_targetBoat->GetState() == BoatState::Move || _targetBoat->GetState() == BoatState::Idle) // Á×¾úÀ» ¶§ 
	{
		GameEvent<BulletActor*>* gePushBullet = Events->GetEvent<BulletActor*>("PushBullet");
		gePushBullet->Invoke(this);
		_state = BulletState::Done;
	}
	else
	{
		Vector2 dir = _targetBoat->GetPos() - this->GetPos();
		dir = dir.Normalize();
		_body.pos += dir * Time->GetDeltaTime() * _speed;

		float lengthSq = (_targetBoat->GetPos() - this->_body.pos).LengthSqrt();

		if (lengthSq <= 5 * 5)
		{
			_targetBoat->OnDamage(_damage);
			GameEvent<BulletActor*>* gePushBullet = Events->GetEvent<BulletActor*>("PushBullet");
			gePushBullet->Invoke(this);
			_state = BulletState::Done;
		}
	}
}
void BulletActor::SetATarget(BoatActor* targetBoat)
{
	if (targetBoat == nullptr)
	{
		return;
	}
	_targetBoat = targetBoat;
	_state = BulletState::Move;
}