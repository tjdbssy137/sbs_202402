#include "pch.h"
#include "ActionButtonsPanel.h"
#include "Image.h"
#include "Button.h"
#include "TowerDefenseScene.h"
#include "RedBlockController.h"
#include "BehicleActor.h"
#include "BehicleController.h"

// TO-DO
// submarine과 tank는 upgrade와 delete가 다르게 뜨도록 조정 
void ActionButtonsPanel::Init()
{
	Super::Init();
	{
		this->LoadResource();

		Panel* iconListPanel = new Panel();
		{
			iconListPanel->SetRect(Shape::MakeCenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y / 2, 100, 40));
			this->AddChild(iconListPanel);
		}
		{
			Button* UpgradeButton = new Button();
			UpgradeButton->SetRect(Shape::MakeCenterRect(-40, 0, 32, 32));
			UpgradeButton->SetSprite(ButtonState::Default, Resource->GetSprite(L"S_Upgrade_Default"));
			UpgradeButton->SetSprite(ButtonState::Hover, Resource->GetSprite(L"S_Upgrade_Hover"));
			UpgradeButton->SetSprite(ButtonState::Pressed, Resource->GetSprite(L"S_Upgrade_Pressed"));
			UpgradeButton->SetSprite(ButtonState::Disabled, Resource->GetSprite(L"S_Upgrade_Disabled"));
			UpgradeButton->AddOnClickDelegate(this, &ActionButtonsPanel::OnClick_GoToUpgrade);
			UpgradeButton->SetState(ButtonState::Disabled);
			UpgradeButton->Init();
			iconListPanel->AddChild(UpgradeButton);
			_buttons.push_back(UpgradeButton);
		}

		{
			Button* DeleteButton = new Button();
			DeleteButton->SetRect(Shape::MakeCenterRect(40, 0, 32, 32));
			DeleteButton->SetSprite(ButtonState::Default, Resource->GetSprite(L"S_Delete_Default"));
			DeleteButton->SetSprite(ButtonState::Hover, Resource->GetSprite(L"S_Delete_Hover"));
			DeleteButton->SetSprite(ButtonState::Pressed, Resource->GetSprite(L"S_Delete_Pressed"));
			DeleteButton->SetSprite(ButtonState::Disabled, Resource->GetSprite(L"S_Delete_Disabled"));
			DeleteButton->AddOnClickDelegate(this, &ActionButtonsPanel::OnClick_GoToDelete);
			DeleteButton->SetState(ButtonState::Disabled);
			DeleteButton->Init();
			iconListPanel->AddChild(DeleteButton);
			_buttons.push_back(DeleteButton);
		}
	}
	Events->AddEvent("SetPanelState_ActionButtonsPanel", new GameEvent<ePanelState>());
	Events->GetEvent<ePanelState>("SetPanelState_ActionButtonsPanel")
		->AddListen(this, &ActionButtonsPanel::SetState);
}

void ActionButtonsPanel::Render(HDC hdc)
{
	Super::Render(hdc);
}
void ActionButtonsPanel::Update()
{
	Super::Update();
	switch (_state)
	{
	case ePanelState::SHOW:
	{
		this->Show();
		for (Button* button : _buttons)
		{
			button->SetState(ButtonState::Default);
		}		
		_state = ePanelState::NONE;
	}
		break;
	case ePanelState::HIDE:
	{
		this->Hide();
		for (Button* button : _buttons)
		{
			button->SetState(ButtonState::Disabled);
		}
		_state = ePanelState::NONE;
	}
		break;
	case ePanelState::NONE:
		break;
	default:
		break;
	}
	
}
void ActionButtonsPanel::Release()
{
	Super::Release();
}
void ActionButtonsPanel::OnClick_GoToUpgrade()
{
	TowerDefenseScene* towerDefenseScene = static_cast<TowerDefenseScene*>(CurrentScene);
	RedBlockController* redBlockController = towerDefenseScene->GetRedBlockController();	

	vector<BehicleController*> behicleController = towerDefenseScene->GetBehicleController();
	int index = redBlockController->GetBehicleControllerIndex();
	
	BehicleData data = behicleController[index]->GetBehicleData();
	
	if (data.Id == Datas->GetBehicleData(7).Id) // 잠수함일 경우 업그레이드 안 됨.
	{
		// 업데이트가 안된다는 문구 삽입
		return;
	}

	if (data.UpgradeGold <= UserDatas->GetGold()) // 돈이 있다면 업그레이드
	{
		behicleController[index]->SettingBehicle(data.UpgradeTowerId);
		UserDatas->PayGold(Datas->GetBehicleData(data.Id).UpgradeGold);
	}
	else // 돈이 없다면 사용한 위치값 반환
	{
		Vector2Int pos = redBlockController->GetInstallBehiclePos();
		GameEvent<Vector2Int>* gameEvent = Events->GetEvent<Vector2Int>("RemoveInstallPos");
		gameEvent->Invoke(pos);
	}
	_state = ePanelState::HIDE;
	this->Hide();
}
void ActionButtonsPanel::OnClick_GoToDelete()
{
	TowerDefenseScene* towerDefenseScene = static_cast<TowerDefenseScene*>(CurrentScene);
	RedBlockController* redBlockController = towerDefenseScene->GetRedBlockController();
	vector<BehicleController*> behicleController = towerDefenseScene->GetBehicleController();
	
	int index = redBlockController->GetBehicleControllerIndex();
	Vector2Int pos = redBlockController->GetInstallBehiclePos();

	GameEvent<Vector2Int>* gameEvent = Events->GetEvent<Vector2Int>("RemoveInstallPos");
	gameEvent->Invoke(pos);

	behicleController[index]->DeleteBehicle();
	UserDatas->MakeGold(behicleController[index]->GetBehicleData().RefundGold);

	_state = ePanelState::HIDE;
	this->Hide();
}

void ActionButtonsPanel::LoadResource()
{
	auto a = Resource->GetTexture(L"T_Buttons");
	Resource->CreateSprite(L"S_Upgrade_Default", a, 0, 40, 40, 40);
	Resource->CreateSprite(L"S_Upgrade_Hover", a, 40, 40, 40, 40);
	Resource->CreateSprite(L"S_Upgrade_Pressed", a, 80, 40, 40, 40);
	Resource->CreateSprite(L"S_Upgrade_Disabled", a, 0, 40, 40, 40);

	auto b = Resource->GetTexture(L"T_Buttons");
	Resource->CreateSprite(L"S_Delete_Default", b, 0, 80, 40, 40);
	Resource->CreateSprite(L"S_Delete_Hover", b, 40, 80, 40, 40);
	Resource->CreateSprite(L"S_Delete_Pressed", b, 80, 80, 40, 40);
	Resource->CreateSprite(L"S_Delete_Disabled", b, 0, 80, 40, 40);
}