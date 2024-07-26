#include "pch.h"
#include "TowerDefenseStartPanel.h"
#include "Image.h"
#include "Button.h"
#include "TowerDefenseScene.h"

void TowerDefenseStartPanel::Init()
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
		Image* start = new Image();
		start->SetRect(Shape::MakeCenterRect(0, 0, 0, 0));
		start->SetSprite(Resource->GetSprite(L"S_StartPanel"));
		start->Init();
		iconListPanel->AddChild(start);
	}

	{
		Button* startButton = new Button();
		startButton->SetRect(Shape::MakeCenterRect(0, 186, 280, 80));
		startButton->SetSprite(ButtonState::Default, Resource->GetSprite(L"S_StartButton_Default"));
		startButton->SetSprite(ButtonState::Hover, Resource->GetSprite(L"S_StartButton_Hover"));
		startButton->SetSprite(ButtonState::Pressed, Resource->GetSprite(L"S_StartButton_Pressed"));
		startButton->SetSprite(ButtonState::Disabled, Resource->GetSprite(L"S_StartButton_Disabled"));
		startButton->AddOnClickDelegate(this, &TowerDefenseStartPanel::OnClick_GoToStart);
		startButton->SetState(ButtonState::Disabled);
		startButton->Init();
		iconListPanel->AddChild(startButton);
		_buttons.push_back(startButton);
	}
}
void TowerDefenseStartPanel::Render(HDC hdc)
{
	Super::Render(hdc);
}

void TowerDefenseStartPanel::Update()
{
	Super::Update();
	switch (_state)
	{
	case ePanelState::SHOW:
	{
		for (Button* button : _buttons)
		{
			button->SetState(ButtonState::Default);
		}
		_state = ePanelState::NONE;
	}
	break;
	case ePanelState::HIDE:
	{
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

void TowerDefenseStartPanel::Release()
{
	Super::Release();
}

void TowerDefenseStartPanel::OnClick_GoToStart()
{
	TowerDefenseScene* towerDefenseScene = static_cast<TowerDefenseScene*>(CurrentScene);
	towerDefenseScene->SetGameStart(true);
	_state = ePanelState::HIDE;
	this->Hide();
}

void TowerDefenseStartPanel::LoadResource()
{
	auto a = Resource->GetTexture(L"T_StartButton");
	Resource->CreateSprite(L"S_StartButton_Default", a, 0, 0, 280, 80);
	Resource->CreateSprite(L"S_StartButton_Hover", a, 0, 80, 280, 80);
	Resource->CreateSprite(L"S_StartButton_Pressed", a, 0, 160, 280, 80);
	Resource->CreateSprite(L"S_StartButton_Disabled", a, 0, 0, 280, 80);
}