#pragma once
#include "Panel.h"
class Button;

enum class ActionButtonsButtonManagState
{
	Show,
	Hide,
	None
};
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
public:
	void SetState(ActionButtonsButtonManagState state) { _state = state; }
private:
	vector<Button*> _buttons = {};
	ActionButtonsButtonManagState _state = ActionButtonsButtonManagState::Hide;
};

