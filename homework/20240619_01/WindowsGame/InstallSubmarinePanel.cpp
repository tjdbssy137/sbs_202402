#include "pch.h"
#include "InstallSubmarinePanel.h"
#include "Image.h"
#include "Button.h"
#include "Dev2Scene.h"
#include "RedBlockController.h"
#include "BehicleController.h"
#include "BehicleActor.h"
void InstallSubmarinePanel::Init()
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
			Image* image1 = new Image();
			image1->SetRect(Shape::MakeCenterRect(0, 0, 0, 0));
			image1->SetSprite(Resource->GetSprite(L"S_Button_S"));
			image1->Init();
			iconListPanel->AddChild(image1);
		}

		{
			Button* submarineButton = new Button();
			submarineButton->SetRect(Shape::MakeCenterRect(0, 0, 32, 32));
			submarineButton->SetSprite(ButtonState::Default, Resource->GetSprite(L"S_Submarine_Default"));
			submarineButton->SetSprite(ButtonState::Hover, Resource->GetSprite(L"S_Submarine_Hover"));
			submarineButton->SetSprite(ButtonState::Pressed, Resource->GetSprite(L"S_Submarine_Pressed"));
			submarineButton->SetSprite(ButtonState::Disabled, Resource->GetSprite(L"S_Submarine_Disabled"));
			submarineButton->AddOnClickDelegate(this, &InstallSubmarinePanel::OnClick_GoToInstallSubmarine);
			submarineButton->Init();
			iconListPanel->AddChild(submarineButton);
			_buttons.push_back(submarineButton);
		}
	}
}

void InstallSubmarinePanel::Render(HDC hdc)
{
	Super::Render(hdc);
}
void InstallSubmarinePanel::Update()
{
	Super::Update();
	switch (_state)
	{
	case InstallSubmarineButtonManagState::Show:
	{
		for (Button* button : _buttons)
		{
			button->SetState(ButtonState::Default);
		}
		_state = InstallSubmarineButtonManagState::None;
	}
	break;
	case InstallSubmarineButtonManagState::Hide:
	{
		for (Button* button : _buttons)
		{
			button->SetState(ButtonState::Disabled);
		}
		_state = InstallSubmarineButtonManagState::None;
	}
	break;
	case InstallSubmarineButtonManagState::None:
		break;
	default:
		break;
	}
}
void InstallSubmarinePanel::Release()
{
	Super::Release();
}

void InstallSubmarinePanel::OnClick_GoToInstallSubmarine()
{
	Dev2Scene* dev2Scene = dynamic_cast<Dev2Scene*>(CurrentScene);
	RedBlockController* redBlockController = dev2Scene->GetRedBlockController();
	Vector2Int pos = redBlockController->GetInstallBehiclePos();
	BehicleController* behicleController = new BehicleController();
	{
		cout << "Create Behicle" << endl;
		BehicleActor* behicle = new BehicleActor();
		behicle->SetLayer(LayerType::Character);
		behicleController->SetLink(behicle);
		behicleController->IsSetting(true);
		behicleController->SetBehicleTypeState(static_cast<int>(BehicleTypeState::Submarine));
		behicle->Init();
		dev2Scene->SpawnActor(behicle);
		behicle->SetCellPos(pos, true);
		dev2Scene->SetBehicleActor(behicle);
	}
	dev2Scene->SetBehicleController(behicleController); //_behicleControllers.push_back

	_state = InstallSubmarineButtonManagState::Hide;
	this->Hide();
}
void InstallSubmarinePanel::LoadResource()
{
	auto a = Resource->GetTexture(L"T_Submarine");
	Resource->CreateSprite(L"S_Submarine_Default", a, 0, 0, 32, 32);
	Resource->CreateSprite(L"S_Submarine_Hover", a, 0, 32, 32, 32);
	Resource->CreateSprite(L"S_Submarine_Pressed", a, 0, 64, 32, 32);
	Resource->CreateSprite(L"S_Submarine_Disabled", a, 0, 96, 32, 32);
}