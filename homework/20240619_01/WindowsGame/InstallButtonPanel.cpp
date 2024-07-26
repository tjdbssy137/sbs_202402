#include "pch.h"
#include "InstallButtonPanel.h"
#include "Image.h"
#include "Button.h"
#include "TowerDefenseScene.h"
#include "RedBlockController.h"

void InstallButtonPanel::Init()
{
	Super::Init();
	this->LoadResource();

	this->SetRect(Shape::MakeCenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y / 2, 0, 0));

	Panel* iconListPanel = new Panel();
	{
		iconListPanel->SetRect(Shape::MakeCenterRect(0, 0, 0, 0));
		this->AddChild(iconListPanel);
	}

	{
		Button* InstallButton = new Button();
		InstallButton->SetRect(Shape::MakeCenterRect(-500, 300, 60, 60));
		InstallButton->SetSprite(ButtonState::Default, Resource->GetSprite(L"S_InstallButton_Default"));
		InstallButton->SetSprite(ButtonState::Hover, Resource->GetSprite(L"S_InstallButton_Hover"));
		InstallButton->SetSprite(ButtonState::Pressed, Resource->GetSprite(L"S_InstallButton_Pressed"));
		InstallButton->SetSprite(ButtonState::Disabled, Resource->GetSprite(L"S_InstallButton_Default"));
		InstallButton->AddOnClickDelegate(this, &InstallButtonPanel::OnClick_GoToInstall);
		InstallButton->SetState(ButtonState::Disabled);
		InstallButton->Init();
		iconListPanel->AddChild(InstallButton);
	}

	{
		Button* cancelButton = new Button();
		cancelButton->SetRect(Shape::MakeCenterRect(-400, 300, 60, 60));
		cancelButton->SetSprite(ButtonState::Default, Resource->GetSprite(L"S_CancelButton_Default"));
		cancelButton->SetSprite(ButtonState::Hover, Resource->GetSprite(L"S_CancelButton_Hover"));
		cancelButton->SetSprite(ButtonState::Pressed, Resource->GetSprite(L"S_CancelButton_Pressed"));
		cancelButton->SetSprite(ButtonState::Disabled, Resource->GetSprite(L"S_CancelButton_Default"));
		cancelButton->AddOnClickDelegate(this, &InstallButtonPanel::OnClick_GoToCancel);
		cancelButton->SetState(ButtonState::Disabled);
		cancelButton->Init();
		iconListPanel->AddChild(cancelButton);
	}
}
void InstallButtonPanel::Render(HDC hdc)
{
	Super::Render(hdc);
}

void InstallButtonPanel::Update()
{
	Super::Update();
}

void InstallButtonPanel::Release()
{
	Super::Release();
}

void InstallButtonPanel::OnClick_GoToInstall()
{
	TowerDefenseScene* towerDefenseScene = static_cast<TowerDefenseScene*>(CurrentScene);
	RedBlockController* redBlockController = towerDefenseScene->GetRedBlockController();
	redBlockController->OnMouse();
}

void InstallButtonPanel::OnClick_GoToCancel()
{
	TowerDefenseScene* towerDefenseScene = static_cast<TowerDefenseScene*>(CurrentScene);
	RedBlockController* redBlockController = towerDefenseScene->GetRedBlockController();
	redBlockController->OffMouse();
}

void InstallButtonPanel::LoadResource()
{
	auto install = Resource->GetTexture(L"T_Buttons2");
	Resource->CreateSprite(L"S_InstallButton_Default", install, 60, 0, 60, 60);
	Resource->CreateSprite(L"S_InstallButton_Hover", install, 60, 60, 60, 60);
	Resource->CreateSprite(L"S_InstallButton_Pressed", install, 60, 120, 60, 60);

	auto cancel = Resource->GetTexture(L"T_Buttons2");
	Resource->CreateSprite(L"S_CancelButton_Default", cancel, 0, 0, 60, 60);
	Resource->CreateSprite(L"S_CancelButton_Hover", cancel, 0, 60, 60, 60);
	Resource->CreateSprite(L"S_CancelButton_Pressed", cancel, 0, 120, 60, 60);

}