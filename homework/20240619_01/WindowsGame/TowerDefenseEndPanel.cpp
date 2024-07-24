#include "pch.h"
#include "TowerDefenseEndPanel.h"
#include "Image.h"
#include "Button.h"

void TowerDefenseEndPanel::Init()
{
	Super::Init();
}
void TowerDefenseEndPanel::Render(HDC hdc)
{
	Super::Render(hdc);
}

void TowerDefenseEndPanel::Update()
{
	Super::Update();
	switch (_state)
	{
	case ePanelState::Show:
	{
		for (Button* button : _buttons)
		{
			button->SetState(ButtonState::Default);
		}
		_state = ePanelState::None;
	}
	break;
	case ePanelState::Hide:
	{
		for (Button* button : _buttons)
		{
			button->SetState(ButtonState::Disabled);
		}
		_state = ePanelState::None;
	}
	break;
	case ePanelState::None:
		break;
	default:
		break;
	}
}

void TowerDefenseEndPanel::Release()
{
	Super::Release();
}

void TowerDefenseEndPanel::LoadResource()
{

}