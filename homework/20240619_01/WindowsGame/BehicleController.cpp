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
			_behicle->SetBehicleType(L"FB_Submarine_");
			_behicle->ChangeDirection(eDirection::DOWN_RIGHT);
			_behicle->SetActiveBehicle();
			//_type = BehicleTypeState::None; 
			//		�̰� ������ behicleController[index]->GetBehicleTypeState()���� ��� None = 7�� ���� ������Ʈ�� �� ��
			//		�ٵ� �̰� �����ϱ� �����̶� LookAtBoat�� �� �� ����
		}
		break;
		case BehicleTypeState::Delete:
		{
			_behicle->SetBehicleType(L"FB_Submarine_");
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
	wstring name = wstring().assign(data.Name.begin(), data.Name.end());

	_behicle->SetBehicleType(name);
	_behicle->SetColliderSize(data.ColliderSize);
	_behicle->ChangeDirection(eDirection::DOWN_RIGHT);//�� �ڵ尡 ������ actor�� �� ����
	_behicle->SetActiveBehicle();
	_behicle->SetBulletDamage(data.BulletDamage);
	_behicle->SetAttackTime(data.AttackTime);
	_behicle->SetBulletSpeed(data.BulletSpeed);
}