#include "pch.h"
#include "ActionButtonsPanel.h"
#include "Image.h"
#include "Button.h"
#include "InstallBehicle.h"
#include "Dev2Scene.h"
#include "RedBlockController.h"
#include "BehicleActor.h"
#include "BehicleController.h"

void ActionButtonsPanel::Init()
{
	Super::Init();
	{
		Panel* iconListPanel = new Panel();
		{
			iconListPanel->SetRect(Shape::MakeCenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y / 2, 100, 40));
			this->AddChild(iconListPanel);

		}
		{
			auto a = Resource->GetSprite(L"S_Button_Upgrade");

			Button* UpgradeButton = new Button();
			UpgradeButton->SetRect(Shape::MakeCenterRect(-40, 0, 32, 32));
			UpgradeButton->SetSprite(ButtonState::Default, a);
			UpgradeButton->SetSprite(ButtonState::Hover, a);
			UpgradeButton->SetSprite(ButtonState::Pressed, a);
			UpgradeButton->SetSprite(ButtonState::Disabled, a);
			UpgradeButton->AddOnClickDelegate(this, &ActionButtonsPanel::OnClick_GoToUpgrade);
			UpgradeButton->Init();
			iconListPanel->AddChild(UpgradeButton);
		}

		{
			auto a = Resource->GetSprite(L"S_Button_Delete");

			Button* DeleteButton = new Button();
			DeleteButton->SetRect(Shape::MakeCenterRect(40, 0, 32, 32));
			DeleteButton->SetSprite(ButtonState::Default, a);
			DeleteButton->SetSprite(ButtonState::Hover, a);
			DeleteButton->SetSprite(ButtonState::Pressed, a);
			DeleteButton->SetSprite(ButtonState::Disabled, a);
			DeleteButton->AddOnClickDelegate(this, &ActionButtonsPanel::OnClick_GoToDelete);
			DeleteButton->Init();
			iconListPanel->AddChild(DeleteButton);
		}
	}
}

void ActionButtonsPanel::Render(HDC hdc)
{
	Super::Render(hdc);
}
void ActionButtonsPanel::Update()
{
	Super::Update();
}
void ActionButtonsPanel::Release()
{
	Super::Release();
}

void ActionButtonsPanel::OnClick_GoToUpgrade()
{
	Dev2Scene* scene = static_cast<Dev2Scene*>(CurrentScene);
	RedBlockController* redBlockController = scene->GetRedBlockController();	

	vector<BehicleController*> behicleController = scene->GetBehicleController();
	int index = redBlockController->GetBehicleControllerIndex();

	switch (behicleController[index]->GetBehicleTypeState()) // ¾Èµé¾î¿È
	{
	case BehicleTypeState::Tank1:
	{
		behicleController[index]->SetBehicleTypeState(static_cast<int>(BehicleTypeState::Tank2));
		cout << "Tank2" << endl;
	}
		break;
	case BehicleTypeState::Tank2:
		behicleController[index]->SetBehicleTypeState(static_cast<int>(BehicleTypeState::Tank3));
		break;
	case BehicleTypeState::DrillTank1:
	{
		behicleController[index]->SetBehicleTypeState(static_cast<int>(BehicleTypeState::DrillTank2));
		cout << "DrillTank2" << endl;
	}		
	break;
	case BehicleTypeState::DrillTank2:
		behicleController[index]->SetBehicleTypeState(static_cast<int>(BehicleTypeState::DrillTank3));
		break;
	default:
		break;
	}
	// behicleController[index]->SetBehicleTypeState(static_cast<int>(behicleController[index]->GetBehicleTypeState()) + 1);
	this->Hide();
}
void ActionButtonsPanel::OnClick_GoToDelete()
{
	Dev2Scene* scene = static_cast<Dev2Scene*>(CurrentScene);
	RedBlockController* redBlockController = scene->GetRedBlockController();
	vector<Vector2Int> alreadyInstallBehicle = redBlockController->GetAlreadyInstallBehicle();
	vector<BehicleController*> behicleController = scene->GetBehicleController();
	int index = redBlockController->GetBehicleControllerIndex();
	Vector2Int pos = redBlockController->GetBehiclePos();

	auto findIt = find(alreadyInstallBehicle.begin(), alreadyInstallBehicle.end(), pos);
	if (findIt != alreadyInstallBehicle.end())
	{
		alreadyInstallBehicle.erase(findIt); // °Á ÀûÆó°°´Ù..
	}
	redBlockController->SetAlreadyInstallBehicle(alreadyInstallBehicle);
	behicleController[index]->SetBehicleTypeState(static_cast<int>(BehicleTypeState::Delete));
	this->Hide();
}