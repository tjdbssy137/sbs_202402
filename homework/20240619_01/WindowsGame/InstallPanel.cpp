#include "pch.h"
#include "InstallPanel.h"
#include "Image.h"
#include "Button.h"
#include "InstallBehicle.h"
#include "Dev2Scene.h"
#include "RedBlockController.h"
#include "BehicleController.h"
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
		/*
		{
			Image* image1 = new Image();
			image1->SetRect(Shape::MakeCenterRect(0, 0, 0, 0));//panel기준으로 해야하기 때문에 좌표가 같아야 함.
			image1->SetSprite(Resource->GetSprite(L"S_Victory"));
			image1->Init();
			iconListPanel->AddChild(image1);
		}

		{
			Image* image1 = new Image();
			image1->SetRect(Shape::MakeCenterRect(0, 60, 0, 0));//panel기준으로 해야하기 때문에 좌표가 같아야 함.
			image1->SetSprite(Resource->GetSprite(L"S_Mole_Idle"));
			image1->Init();
			iconListPanel->AddChild(image1);
		}
		*/

		{
			Button* drillButton = new Button();
			drillButton->SetRect(Shape::MakeCenterRect(-40, 4, 32, 32));
			drillButton->SetSprite(ButtonState::Default, Resource->GetSprite(L"S_DrillTank1_Default"));
			drillButton->SetSprite(ButtonState::Hover, Resource->GetSprite(L"S_DrillTank1_Hover"));
			drillButton->SetSprite(ButtonState::Pressed, Resource->GetSprite(L"S_DrillTank1_Pressed"));
			drillButton->SetSprite(ButtonState::Disabled, Resource->GetSprite(L"S_DrillTank1_Disabled"));
			drillButton->AddOnClickDelegate(this, &InstallPanel::OnClick_GoToInstallDrill);
			drillButton->Init();
			iconListPanel->AddChild(drillButton);
		}
		{
			Button* tankButton = new Button();
			tankButton->SetRect(Shape::MakeCenterRect(40, 4, 32, 32));
			tankButton->SetSprite(ButtonState::Default, Resource->GetSprite(L"S_Tank1_Default"));
			tankButton->SetSprite(ButtonState::Hover, Resource->GetSprite(L"S_Tank1_Hover"));
			tankButton->SetSprite(ButtonState::Pressed, Resource->GetSprite(L"S_Tank1_Pressed"));
			tankButton->SetSprite(ButtonState::Disabled, Resource->GetSprite(L"S_Tank1_Disabled"));
			tankButton->AddOnClickDelegate(this, &InstallPanel::OnClick_GoToInstallTank);
			tankButton->Init();
			iconListPanel->AddChild(tankButton);
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
}
void InstallPanel::Release()
{
	Super::Release();
}

void InstallPanel::OnClick_GoToUpGrade()
{

}
void InstallPanel::OnClick_GoToInstallDrill()
{
	Dev2Scene* scene = static_cast<Dev2Scene*>(CurrentScene);
	InstallBehicle* installBehicle = scene->GetInstallBehicle();
	RedBlockController* redBlockController = scene->GetRedBlockController();

	installBehicle->SetBehicleTypeState(static_cast<int>(BehicleTypeState::DrillTank1));
	installBehicle->InstallBehicleFunc(redBlockController->GetInstallBehiclePos());
	this->Hide();
}
void InstallPanel::OnClick_GoToInstallTank()
{
	Dev2Scene* scene = static_cast<Dev2Scene*>(CurrentScene);
	InstallBehicle* installBehicle = scene->GetInstallBehicle();
	RedBlockController* redBlockController = scene->GetRedBlockController();

	installBehicle->SetBehicleTypeState(static_cast<int>(BehicleTypeState::Tank1));
	installBehicle->InstallBehicleFunc(redBlockController->GetInstallBehiclePos());

	this->Hide();
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