#include "pch.h"
#include "GameStatePanel.h"
#include "Image.h"
#include "Button.h"
#include "TowerDefensePanel.h"
#include "TowerDefenseScene.h"

void GameStatePanel::Init()
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
		InstallButton->AddOnClickDelegate(this, &GameStatePanel::OnClick_GoToInstall);
		InstallButton->SetState(ButtonState::Disabled);
		InstallButton->Init();
		iconListPanel->AddChild(InstallButton);
	}

	{
		_nextWaveButton = new Button();
		_nextWaveButton->SetRect(Shape::MakeCenterRect(30, -370, 60, 60));
		_nextWaveButton->SetSprite(ButtonState::Default, Resource->GetSprite(L"S_NextWaveButton_Default"));
		_nextWaveButton->SetSprite(ButtonState::Hover, Resource->GetSprite(L"S_NextWaveButton_Hover"));
		_nextWaveButton->SetSprite(ButtonState::Pressed, Resource->GetSprite(L"S_NextWaveButton_Pressed"));
		_nextWaveButton->SetSprite(ButtonState::Disabled, Resource->GetSprite(L"S_NextWaveButton_Default"));
		_nextWaveButton->AddOnClickDelegate(this, &GameStatePanel::OnClick_GoToNextWave);
		_nextWaveButton->SetState(ButtonState::Disabled);
		_nextWaveButton->Init();
		iconListPanel->AddChild(_nextWaveButton);
	}
	
	{
		_pauseButton = new Image();
		_pauseButton->SetRect(Shape::MakeCenterRect(30, -370, 60, 60));
		_pauseButton->SetSprite(Resource->GetSprite(L"S_PauseButton"));
		_pauseButton->Init();
		iconListPanel->AddChild(_pauseButton);
	}

	_mainPanel = new TowerDefensePanel();
	_mainPanel->Init();
	
	TowerDefenseScene* towerDefenseScene = dynamic_cast<TowerDefenseScene*>(CurrentScene);
	towerDefenseScene->AddUI(_mainPanel);

	// Add Event
	Events->AddEvent("SetPanelState_GameStateController", new GameEvent<ePanelState>());
	Events->GetEvent<ePanelState>("SetPanelState_GameStateController")
		->AddListen(this, &GameStatePanel::SetState);
}
void GameStatePanel::Render(HDC hdc)
{
	Super::Render(hdc);
}

void GameStatePanel::Update()
{
	Super::Update();

	switch (_panelState)
	{
	case ePanelState::SHOW:
	{
		this->Show();
		_nextWaveButton->SetState(ButtonState::Default);
		_pauseButton->SetSprite(nullptr);
		_state = GameWaveState::Done;
		_panelState = ePanelState::NONE;
	}
	break;

	case ePanelState::HIDE:
	{
		this->Hide();
		_nextWaveButton->SetState(ButtonState::Disabled);
		_pauseButton->SetSprite(Resource->GetSprite(L"S_PauseButton"));
		_panelState = ePanelState::NONE;
	}
	break;
	case ePanelState::NONE:
		break;
	default:
		break;
	}

	wchar_t str[50];
	swprintf_s(str, L"Round %d | Enter Enemy %d | Gold %d",
		UserDatas->GetWave(), UserDatas->GetEnterEnemy(), UserDatas->GetGold());
	_mainPanel->SetGameInfoText(wstring(str));
}

void GameStatePanel::Release()
{
	Super::Release();
}

void GameStatePanel::OnClick_GoToNextWave()
{
	_state = GameWaveState::Wave;	
	GameEvent<GameWaveState>* gameEvent = Events->GetEvent<GameWaveState>("SetGameWaveState");
	gameEvent->Invoke(_state);

	_panelState = ePanelState::HIDE;
}

void GameStatePanel::OnClick_GoToInstall()
{
	GameEvent<>* gameEvent = Events->GetEvent<>("OnMouse");
	gameEvent->Invoke();
}

void GameStatePanel::LoadResource()
{
	auto nextWave = Resource->GetTexture(L"T_Buttons2");
	Resource->CreateSprite(L"S_NextWaveButton_Default", nextWave, 120, 0, 60, 60);
	Resource->CreateSprite(L"S_NextWaveButton_Hover", nextWave, 120, 60, 60, 60);
	Resource->CreateSprite(L"S_NextWaveButton_Pressed", nextWave, 120, 120, 60, 60);

	auto install = Resource->GetTexture(L"T_Buttons2");
	Resource->CreateSprite(L"S_InstallButton_Default", install, 60, 0, 60, 60);
	Resource->CreateSprite(L"S_InstallButton_Hover", install, 60, 60, 60, 60);
	Resource->CreateSprite(L"S_InstallButton_Pressed", install, 60, 120, 60, 60);
}