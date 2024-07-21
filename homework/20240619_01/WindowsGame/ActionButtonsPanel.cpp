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
			UpgradeButton->SetState(ButtonState::Disabled);
			UpgradeButton->Init();
			iconListPanel->AddChild(UpgradeButton);
			_buttons.push_back(UpgradeButton);
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
			DeleteButton->SetState(ButtonState::Disabled);
			DeleteButton->Init();
			iconListPanel->AddChild(DeleteButton);
			_buttons.push_back(DeleteButton);
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
	switch (_state)
	{
	case ActionButtonsButtonManagState::Show:
	{
		for (Button* button : _buttons)
		{
			button->SetState(ButtonState::Default);
		}		
		_state = ActionButtonsButtonManagState::None;
	}
		break;
	case ActionButtonsButtonManagState::Hide:
	{
		for (Button* button : _buttons)
		{
			button->SetState(ButtonState::Disabled);
		}
		_state = ActionButtonsButtonManagState::None;
	}
		break;
	case ActionButtonsButtonManagState::None:
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
	Dev2Scene* scene = static_cast<Dev2Scene*>(CurrentScene);
	RedBlockController* redBlockController = scene->GetRedBlockController();	

	vector<BehicleController*> behicleController = scene->GetBehicleController();
	int index = redBlockController->GetBehicleControllerIndex();
	
	//cout <<" static_cast<int>(behicleController[index]->GetBehicleTypeState()) : "
	//  << static_cast<int>(behicleController[index]->GetBehicleTypeState()) << endl;
	switch (behicleController[index]->GetBehicleTypeState())
	{
	case BehicleTypeState::Tank1:
	{
		behicleController[index]->IsSetting(true);
		behicleController[index]->SetBehicleTypeState(static_cast<int>(BehicleTypeState::Tank2));
	}
		break;
	case BehicleTypeState::Tank2:
	{
		behicleController[index]->IsSetting(true);
		behicleController[index]->SetBehicleTypeState(static_cast<int>(BehicleTypeState::Tank3));
	}	break;
	case BehicleTypeState::DrillTank1:
	{
		behicleController[index]->IsSetting(true);
		behicleController[index]->SetBehicleTypeState(static_cast<int>(BehicleTypeState::DrillTank2));
	}
	break;
	case BehicleTypeState::DrillTank2:
	{
		behicleController[index]->IsSetting(true);
		behicleController[index]->SetBehicleTypeState(static_cast<int>(BehicleTypeState::DrillTank3));
	}
		break;
	default:
		break;
	}
	_state = ActionButtonsButtonManagState::Hide;
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
		//cout << "index : " << index << endl; // 같은 장소에 있는 건 인덱스가 왜인지 안달라지네..?? -> SetPos가 아니라 SetCellPos였음
		alreadyInstallBehicle.erase(findIt);
		redBlockController->SetAlreadyInstallBehicle(alreadyInstallBehicle); 
		// 이거 없으면 제대로 작동 안됨.. vector인데 왜지.. -> 복사본을 들고 오는 것이기 때문에 그냥 레퍼런스로 들고오면 됨
		behicleController[index]->IsSetting(true);
		behicleController[index]->SetBehicleTypeState(static_cast<int>(BehicleTypeState::Delete));
	}
	_state = ActionButtonsButtonManagState::Hide;
	this->Hide();
}