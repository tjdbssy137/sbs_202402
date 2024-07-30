#pragma once
#include "Panel.h"
class Button;

class ActionButtonsPanel : public Panel
{
public:
	DECLARE_CHILD(ActionButtonsPanel, Panel);
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
private:
	void LoadResource();
	void OnClick_GoToUpgrade();
	void OnClick_GoToDelete();
	void OnHover_GoToUpgrade();
	void OnHover_GoToDelete();
public:
	void SetState(ePanelState state) { _state = state; }
private:
	vector<Button*> _buttons = {};
	ePanelState _state = ePanelState::HIDE;
};

