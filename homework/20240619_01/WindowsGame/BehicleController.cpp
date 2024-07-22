#include "pch.h"
#include "BehicleController.h"
#include "BehicleActor.h"
#include "TilemapScene.h"
#include "Tilemap.h"
#include "TilemapActor.h"
#include "MapToolController.h"
#include "Dev2Scene.h"
#include <queue>

void BehicleController::SetLink(BehicleActor* behicle)
{
	assert(behicle != nullptr);

	_behicle = behicle;
}
void BehicleController::Update()
{
	if (_isSetting)
	{
		switch (_type)
		{
		case BehicleTypeState::DrillTank1:
			SettingBehicle(Datas->GetBehicleData(1));
			break;
		case BehicleTypeState::DrillTank2:
			SettingBehicle(Datas->GetBehicleData(2));
			break;
		case BehicleTypeState::DrillTank3:
			SettingBehicle(Datas->GetBehicleData(3));
			break;
		case BehicleTypeState::Tank1:
			SettingBehicle(Datas->GetBehicleData(4));
			break;
		case BehicleTypeState::Tank2:
			SettingBehicle(Datas->GetBehicleData(5));
			break;
		case BehicleTypeState::Tank3:
			SettingBehicle(Datas->GetBehicleData(6));
			break;
		case BehicleTypeState::Submarine:
		{
			_behicle->SetBehicleData(Datas->GetBehicleData(7));
			_behicle->ChangeDirection(eDirection::DOWN_RIGHT);
			_behicle->SetActiveBehicle();
			//_type = BehicleTypeState::None; 
			//	이거 때문에 behicleController[index]->GetBehicleTypeState()에서 계속 None = 7이 떠서 업데이트가 안 됨
			//	근데 이거 막으니까 공격이랑 LookAtBoat가 안 됨 ㅋㅋ
		}
		break;
		case BehicleTypeState::Delete:
		{
			_behicle->SetBehicleData(Datas->GetBehicleData(7));
			_behicle->SetState(BehicleState::None);
			_behicle->SetCellPos({ 54, 1 }, true);
			_type = BehicleTypeState::None;
		}
		break;
		default:
			break;
		}
		_isSetting = false;
	}
}

void BehicleController::SettingBehicle(BehicleData data)
{
	_data = data;
	_behicle->SetBehicleData(_data);
	_behicle->ChangeDirection(eDirection::DOWN_RIGHT);//이 코드가 없으면 actor가 안 보임
	_behicle->SetActiveBehicle();
}