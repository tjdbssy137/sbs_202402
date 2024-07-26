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

void TowerDefenseEndPanel::Release()
{
	Super::Release();
}

void TowerDefenseEndPanel::LoadResource()
{

}