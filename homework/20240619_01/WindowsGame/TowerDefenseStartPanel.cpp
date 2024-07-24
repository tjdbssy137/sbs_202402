#include "pch.h"
#include "TowerDefenseStartPanel.h"
#include "Image.h"
#include "Button.h"

void TowerDefenseStartPanel::Init()
{
	Super::Init();
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

void TowerDefenseStartPanel::Release()
{
	Super::Release();
}

void TowerDefenseStartPanel::LoadResource()
{

}