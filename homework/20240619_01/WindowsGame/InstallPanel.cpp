#include "pch.h"
#include "InstallPanel.h"
#include "Image.h"
#include "Button.h"
#include "TowerDefenseScene.h"
#include "RedBlockController.h"
#include "BehicleController.h"
#include "BehicleActor.h"

void InstallPanel::Init()
{
	Super::Init();
	{
		this->LoadResource();
		
		Panel* iconListPanel = new Panel();
		{
			iconListPanel->SetRect(Shape::MakeCenterRect(WIN_SIZE_X/2, WIN_SIZE_Y / 2, 100, 40));
			this->AddChild(iconListPanel);
		}
		
		{
			Image* image1 = new Image();
			image1->SetRect(Shape::MakeCenterRect(0, 0, 0, 0));
			image1->SetSprite(Resource->GetSprite(L"S_Button_L"));
			image1->Init();
			iconListPanel->AddChild(image1);
		}

		{
			Button* drillButton = new Button();
			drillButton->SetRect(Shape::MakeCenterRect(-25, -2, 32, 32));
			drillButton->SetSprite(ButtonState::Default, Resource->GetSprite(L"S_DrillTank1_Default"));
			drillButton->SetSprite(ButtonState::Hover, Resource->GetSprite(L"S_DrillTank1_Hover"));
			drillButton->SetSprite(ButtonState::Pressed, Resource->GetSprite(L"S_DrillTank1_Pressed"));
			drillButton->SetSprite(ButtonState::Disabled, Resource->GetSprite(L"S_DrillTank1_Disabled"));
			drillButton->AddOnClickDelegate(this, &InstallPanel::OnClick_GoToInstallDrill);
			drillButton->Init();
			iconListPanel->AddChild(drillButton);
			_buttons.push_back(drillButton);

		}
		{
			Button* tankButton = new Button();
			tankButton->SetRect(Shape::MakeCenterRect(25, -2, 32, 32));
			tankButton->SetSprite(ButtonState::Default, Resource->GetSprite(L"S_Tank1_Default"));
			tankButton->SetSprite(ButtonState::Hover, Resource->GetSprite(L"S_Tank1_Hover"));
			tankButton->SetSprite(ButtonState::Pressed, Resource->GetSprite(L"S_Tank1_Pressed"));
			tankButton->SetSprite(ButtonState::Disabled, Resource->GetSprite(L"S_Tank1_Disabled"));
			tankButton->AddOnClickDelegate(this, &InstallPanel::OnClick_GoToInstallTank);
			tankButton->Init();
			iconListPanel->AddChild(tankButton);
			_buttons.push_back(tankButton);

		}
	}
}

void InstallPanel::Render(HDC hdc)
{
	Super::Render(hdc);
}
void InstallPanel::Update()
{
	Super::Update();
	switch (_state)
	{
	case InstallButtonManagState::Show:
	{
		for (Button* button : _buttons)
		{
			button->SetState(ButtonState::Default);
		}
		_state = InstallButtonManagState::None;
	}
	break;
	case InstallButtonManagState::Hide:
	{
		for (Button* button : _buttons)
		{
			button->SetState(ButtonState::Disabled);
		}
		_state = InstallButtonManagState::None;
	}
	break;
	case InstallButtonManagState::None:
		break;
	default:
		break;
	}
}
void InstallPanel::Release()
{
	Super::Release();
}

void InstallPanel::OnClick_GoToInstallDrill()
{
	this->InstallingBehicle(Datas->GetBehicleData(1).Id); // DrillTank1
	this->Hide();
}
void InstallPanel::OnClick_GoToInstallTank()
{
	this->InstallingBehicle(Datas->GetBehicleData(4).Id); // Tank1
	this->Hide();
}
void InstallPanel::InstallingBehicle(int type)
{
	TowerDefenseScene* towerDefenseScene = dynamic_cast<TowerDefenseScene*>(CurrentScene);
	RedBlockController* redBlockController = towerDefenseScene->GetRedBlockController();
	Vector2Int pos = redBlockController->GetInstallBehiclePos();

	if (Datas->GetBehicleData(type).InstallGold <= towerDefenseScene->GetGold()) // 갖고 있는 돈이 설치하기에 충분하다면
	{
		BehicleController* behicleController = new BehicleController();
		{
			cout << "Create Behicle" << endl;
			BehicleActor* behicle = new BehicleActor();
			behicle->SetLayer(LayerType::Character);
			behicleController->SetLink(behicle);
			behicleController->IsSetting(true);
			behicleController->SetBehicleTypeState(type);
			behicle->Init();
			towerDefenseScene->SpawnActor(behicle);
			behicle->SetCellPos(pos, true);
			towerDefenseScene->SetBehicleActor(behicle);
		}
		towerDefenseScene->SetBehicleController(behicleController);//_behicleControllers.push_back();
		towerDefenseScene->PayGold(Datas->GetBehicleData(type).InstallGold);
	}
	else
	{
		vector<Vector2Int> alreadyInstallBehicle = redBlockController->GetAlreadyInstallBehicle();

		auto findIt = find(alreadyInstallBehicle.begin(), alreadyInstallBehicle.end(), pos);
		if (findIt != alreadyInstallBehicle.end())
		{
			alreadyInstallBehicle.erase(findIt);
			redBlockController->SetAlreadyInstallBehicle(alreadyInstallBehicle);
		}
	}
	_state = InstallButtonManagState::Hide;
}

void InstallPanel::LoadResource()
{
	auto a = Resource->GetTexture(L"T_DrillTank1");
	Resource->CreateSprite(L"S_DrillTank1_Default", a, 0, 0, 32, 32);
	Resource->CreateSprite(L"S_DrillTank1_Hover", a, 0, 32, 32, 32);
	Resource->CreateSprite(L"S_DrillTank1_Pressed", a, 0, 64, 32, 32);
	Resource->CreateSprite(L"S_DrillTank1_Disabled", a, 0, 96, 32, 32);

	auto b = Resource->GetTexture(L"T_Tank1");
	Resource->CreateSprite(L"S_Tank1_Default", b, 0, 0, 32, 32);
	Resource->CreateSprite(L"S_Tank1_Hover", b, 0, 32, 32, 32);
	Resource->CreateSprite(L"S_Tank1_Pressed", b, 0, 64, 32, 32);
	Resource->CreateSprite(L"S_Tank1_Disabled", b, 0, 96, 32, 32);
}