#include "pch.h"
#include "BehicleController.h"
#include "BehicleActor.h"
#include <queue>

void BehicleController::SetLink(BehicleActor* behicle)
{
	assert(behicle != nullptr);

	_behicle = behicle;
}
void BehicleController::Update()
{

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