#include "pch.h"
#include "GameStateController.h"
#include "Image.h"
#include "Button.h"
#include "Sprite.h"

void GameStateController::Init()
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
		InstallButton->AddOnClickDelegate(this, &GameStateController::OnClick_GoToInstall);
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
		_nextWaveButton->AddOnClickDelegate(this, &GameStateController::OnClick_GoToNextWave);
		_nextWaveButton->SetState(ButtonState::Disabled);
		_nextWaveButton->Init();
		iconListPanel->AddChild(_nextWaveButton);
	}

	// Add Event
	Events->AddEvent("SetPanelState_GameStateController", new GameEvent<ePanelState>());
	Events->GetEvent<ePanelState>("SetPanelState_GameStateController")
		->AddListen(this, &GameStateController::SetState);
}
void GameStateController::Render(HDC hdc)
{
	Super::Render(hdc);
	
	if(_state == GameWaveState::Wave)
	{ // wave가 진행되는 동안에
		if (_pauseButton == nullptr) return;

		Vector2Int size = _pauseButton->GetSize();
		Vector2Int renderPos = Vector2Int(
			WIN_SIZE_X / 2,
			WIN_SIZE_Y / 2 - 400
		);
		::TransparentBlt(hdc,
			renderPos.x,
			renderPos.y,
			size.x,
			size.y,
			_pauseButton->GetDC(),
			_pauseButton->GetPos().x,
			_pauseButton->GetPos().y,
			size.x,
			size.y,
			_pauseButton->GetTransparent()//투명색
		);
	}
}

void GameStateController::Update()
{
	Super::Update();

	switch (_panelState)
	{
	case ePanelState::SHOW:
	{
		this->Show();
		_nextWaveButton->SetState(ButtonState::Default);
		_state = GameWaveState::Done;
		_panelState = ePanelState::NONE;
	}
	break;

	case ePanelState::HIDE:
	{
		this->Hide();
		_nextWaveButton->SetState(ButtonState::Disabled);
		_panelState = ePanelState::NONE;
	}
	break;
	case ePanelState::NONE:
		break;
	default:
		break;
	}
}

void GameStateController::Release()
{
	Super::Release();
}

void GameStateController::OnClick_GoToNextWave()
{
	_state = GameWaveState::Wave;	
	GameEvent<GameWaveState>* gameEvent = Events->GetEvent<GameWaveState>("SetGameWaveState");
	gameEvent->Invoke(_state);

	_panelState = ePanelState::HIDE;
}

void GameStateController::OnClick_GoToInstall()
{
	GameEvent<>* gameEvent = Events->GetEvent<>("OnMouse");
	gameEvent->Invoke();
}

void GameStateController::LoadResource()
{
	auto nextWave = Resource->GetTexture(L"T_Buttons2");
	Resource->CreateSprite(L"S_NextWaveButton_Default", nextWave, 120, 0, 60, 60);
	Resource->CreateSprite(L"S_NextWaveButton_Hover", nextWave, 120, 60, 60, 60);
	Resource->CreateSprite(L"S_NextWaveButton_Pressed", nextWave, 120, 120, 60, 60);

	auto install = Resource->GetTexture(L"T_Buttons2");
	Resource->CreateSprite(L"S_InstallButton_Default", install, 60, 0, 60, 60);
	Resource->CreateSprite(L"S_InstallButton_Hover", install, 60, 60, 60, 60);
	Resource->CreateSprite(L"S_InstallButton_Pressed", install, 60, 120, 60, 60);

	_pauseButton = Resource->GetSprite(L"S_PauseButton");
}