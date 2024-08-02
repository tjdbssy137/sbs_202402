#include "pch.h"
#include "BehicleController.h"
#include "BehicleActor.h"
#include "TowerDefenseScene.h"
#include "BulletActor.h"
#include "BulletActorController.h"
#include "BoatActor.h"
#include "CircleCollider.h"
#include <queue>

void BehicleController::SetLink(BehicleActor* behicle)
{
	assert(behicle != nullptr);

	_behicle = behicle;

	{
		TowerDefenseScene* towerDefenseScene = static_cast<TowerDefenseScene*>(CurrentScene);
		_bulletActorController = towerDefenseScene->GetBulletActorController();
		_boats = towerDefenseScene->GetBoatActor();
	}
}
void BehicleController::Update()
{
	_behicle->LookAtTarget();

	// XXX : <- 이슈 위험
	switch (_behicle->GetState())
	{
	case BehicleState::Attack:
		this->UpdateAttack();
		break;
	case BehicleState::Submarine:
		break;
	case BehicleState::Idle:
		this->UpdateIdle();
		break;
	case BehicleState::None:
		break;
	default:
		break;
	}
}

void BehicleController::UpdateIdle()
{
	//범위 안에 들어오면 공격을 실행할거다.
	for (BoatActor* boat : _boats)
	{
		// 공격하기로 결정했을 때 내 바운더리 안에 있으면 공격.
		if (Collision::CircleInCircle(_behicle->GetPos(), _behicle->GetCollider()->GetRadius(),
			boat->GetPos(), boat->GetBoatCollider()->GetRadius()))
		{
			_targetBoat = boat;
			_behicle->SetTargetBoat(_targetBoat);
			if (_targetBoat->GetBoatHp() <= 0)
			{
				continue;
			}

			if (_data.Id < 7)
			{
				_behicle->SetState(BehicleState::Attack);
			}
			else
			{
				_behicle->SetState(BehicleState::Submarine);
			}
		}
	};
}

void BehicleController::UpdateAttack()
{
	_attackCoolDown -= Time->GetDeltaTime();
	//static float lastTick = ::GetTickCount64(); //모든 호출에서 공유
	//float currentTick = ::GetTickCount64();
	if (_attackCoolDown <= 0) // AttackTime마다 한번씩 공격할말을 결정
	{
		UseBullet();
		_attackCoolDown = _data.AttackTime;
	}
}
void BehicleController::UseBullet()
{
	if (_bulletActorController->BulletCount() < 1) // 씬에서 생성하고 꺼내 쓰기 -> 이미 BulletActorController 여기서 하고 있음
	{
		BulletActor* bullet = new BulletActor();
		bullet->SetLayer(LayerType::Object);
		bullet->SetPos(_behicle->GetPos());
		bullet->Init();
		CurrentScene->SpawnActor(bullet);
		bullet->SetBulletDamage(_data.BulletDamage);
		bullet->SetBulletSpeed(_data.BulletSpeed);

		bullet->SetATarget(_targetBoat);
		GameEvent<BulletActor*>* gePushBullet = Events->GetEvent<BulletActor*>("PushBullet");
		gePushBullet->Invoke(bullet);
	}
	else
	{
		BulletActor* bullet = _bulletActorController->PopBullet();
		bullet->SetPos(_behicle->GetPos());
		bullet->SetBulletDamage(_data.BulletDamage);
		bullet->SetBulletSpeed(_data.BulletSpeed);
		bullet->SetATarget(_targetBoat);
	}
	_behicle->SetState(BehicleState::Idle);
}

void BehicleController::SettingBehicle(int id)
{
	_data = Datas->GetBehicleData(id);
	_behicle->SetBehicleData(_data);
	_behicle->ChangeDirection(eDirection::DOWN_RIGHT);//이 코드가 없으면 actor가 안 보임
	_behicle->SetActiveBehicle();
}

void BehicleController::DeleteBehicle()
{
	_behicle->SetBehicleData(Datas->GetBehicleData(10000));
	_behicle->SetState(BehicleState::None);
	_behicle->SetCellPos({ 54, 1 }, true);
}