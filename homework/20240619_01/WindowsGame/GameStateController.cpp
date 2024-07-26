#include "pch.h"
#include "GameStateController.h"
#include "Image.h"
#include "Button.h"
#include "Sprite.h"
#include "TowerDefenseScene.h"
#include "GameWave.h"

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
		_nextWaveButton = new Button();
		_nextWaveButton->SetRect(Shape::MakeCenterRect(0, -400, 60, 60));
		_nextWaveButton->SetSprite(ButtonState::Default, Resource->GetSprite(L"S_NextWaveButton_Default"));
		_nextWaveButton->SetSprite(ButtonState::Hover, Resource->GetSprite(L"S_NextWaveButton_Hover"));
		_nextWaveButton->SetSprite(ButtonState::Pressed, Resource->GetSprite(L"S_NextWaveButton_Pressed"));
		_nextWaveButton->SetSprite(ButtonState::Disabled, Resource->GetSprite(L"S_NextWaveButton_Default"));
		_nextWaveButton->AddOnClickDelegate(this, &GameStateController::OnClick_GoToNextWave);
		_nextWaveButton->SetState(ButtonState::Disabled);
		_nextWaveButton->Init();
		iconListPanel->AddChild(_nextWaveButton);
	}
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
		switch (_state)
		{
		case GameWaveState::Wave: // 웨이브가 시작되면
		{
			_nextWaveButton->SetState(ButtonState::Disabled);
			_nextWaveButton->Hide();
		}
		break;

		default: //case GameWaveState::Done:
		{
			_nextWaveButton->Show();
			_nextWaveButton->SetState(ButtonState::Default);
		}
		break;
		}
		_panelState = ePanelState::NONE; // 이게 있어야 클릭이 됨
	}
	break;

	case ePanelState::HIDE:
	{
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
	TowerDefenseScene* towerDefenseScene = static_cast<TowerDefenseScene*>(CurrentScene);
	GameWave* gameWave = towerDefenseScene->GetGameWave();
	gameWave->SetGameWaveState(GameWaveState::Wave);
	_state = GameWaveState::Wave;
}

void GameStateController::LoadResource()
{
	auto nextWave = Resource->GetTexture(L"T_Buttons2");
	Resource->CreateSprite(L"S_NextWaveButton_Default", nextWave, 120, 0, 60, 60);
	Resource->CreateSprite(L"S_NextWaveButton_Hover", nextWave, 120, 60, 60, 60);
	Resource->CreateSprite(L"S_NextWaveButton_Pressed", nextWave, 120, 120, 60, 60);

	_pauseButton = Resource->GetSprite(L"S_PauseButton");

}