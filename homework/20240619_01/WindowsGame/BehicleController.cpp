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
	switch (_type)
	{
	case BehicleTypeState::Tank1:
	{
		_behicle->SetBehicleType(L"FB_Tank1_");
		_behicle->SetColliderSize(120);
		_behicle->ChangeDirection(eDirection::DOWN_RIGHT);//이 코드가 없으면 actor가 안 보임
		_behicle->SetActiveBehicle();
		_behicle->SetBehicleDamage(10);
		_behicle->SetAttackTime(1);
		_behicle->SetBulletSpeed(210);
		_type = BehicleTypeState::None;
	}
		break;
	case BehicleTypeState::Tank2:
	{
		_behicle->SetBehicleType(L"FB_Tank2_");
		_behicle->SetColliderSize(150);
		_behicle->ChangeDirection(eDirection::DOWN_RIGHT);
		_behicle->SetActiveBehicle();
		_behicle->SetBehicleDamage(15);
		_behicle->SetAttackTime(0.8f);
		_behicle->SetBulletSpeed(240);
		_type = BehicleTypeState::None;

	}
	break;
	case BehicleTypeState::Tank3:
	{
		_behicle->SetBehicleType(L"FB_Tank3_");
		_behicle->SetColliderSize(200);
		_behicle->ChangeDirection(eDirection::DOWN_RIGHT);
		_behicle->SetActiveBehicle();
		_behicle->SetBehicleDamage(20);
		_behicle->SetAttackTime(0.7f);
		_behicle->SetBulletSpeed(270);
		_type = BehicleTypeState::None;

	}
		break;
	case BehicleTypeState::DrillTank1:
	{
		_behicle->SetBehicleType(L"FB_DrillTank1_");
		_behicle->SetColliderSize(90);
		_behicle->ChangeDirection(eDirection::DOWN_RIGHT);
		_behicle->SetActiveBehicle();
		_behicle->SetBehicleDamage(15);
		_behicle->SetAttackTime(0.8f);
		_behicle->SetBulletSpeed(200);
		_type = BehicleTypeState::None;

	}
		break;
	case BehicleTypeState::DrillTank2:
	{
		_behicle->SetBehicleType(L"FB_DrillTank2_");
		_behicle->SetColliderSize(120);
		_behicle->ChangeDirection(eDirection::DOWN_RIGHT);
		_behicle->SetActiveBehicle();
		_behicle->SetBehicleDamage(18);
		_behicle->SetAttackTime(0.7f); 
		_behicle->SetBulletSpeed(220);
		_type = BehicleTypeState::None;

	}
		break;
	case BehicleTypeState::DrillTank3:
	{
		_behicle->SetBehicleType(L"FB_DrillTank3_");
		_behicle->SetColliderSize(150);
		_behicle->ChangeDirection(eDirection::DOWN_RIGHT);
		_behicle->SetActiveBehicle();
		_behicle->SetBehicleDamage(21);
		_behicle->SetAttackTime(0.6f);
		_behicle->SetBulletSpeed(240);
		_type = BehicleTypeState::None;

	}
		break;
	case BehicleTypeState::Submarine:
	{
		_behicle->SetBehicleType(L"FB_Submarine_");
		_behicle->ChangeDirection(eDirection::DOWN_RIGHT);
		_behicle->SetActiveBehicle();
		_type = BehicleTypeState::None;
	}
		break;
	case BehicleTypeState::None:

		break;
	default:
		break;
	}
}