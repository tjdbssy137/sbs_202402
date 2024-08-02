#include "pch.h"
#include "BehicleController.h"
#include "BehicleActor.h"
#include "TowerDefenseScene.h"
#include <queue>

void BehicleController::SetLink(BehicleActor* behicle)
{
	assert(behicle != nullptr);

	_behicle = behicle;
}
void BehicleController::Update()
{
	_behicle->LookAtTarget();

	// XXX : <- 이슈 위험
	switch (_behicle->GetState())
	{
	case BehicleState::Attack:
		_behicle->UpdateAttack();
		break;
	case BehicleState::Submarine:
		break;
	case BehicleState::Idle:
		_behicle->UpdateIdle();
		break;
	case BehicleState::None:
		break;
	default:
		break;
	}
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
	_behicle->SetBehicleData(Datas->GetBehicleData(7));
	_behicle->SetState(BehicleState::None);
	_behicle->SetCellPos({ 54, 1 }, true);
}