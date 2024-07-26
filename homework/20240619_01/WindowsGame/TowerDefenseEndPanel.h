#pragma once
#include "Panel.h"
class Button;
class TowerDefenseEndPanel : public Panel
{
public:
	DECLARE_CHILD(TowerDefenseEndPanel, Panel);
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void LoadResource();
	void SetState(ePanelState state) { _state = state; }

private:
	vector<Button*> _buttons = {};
	ePanelState _state = ePanelState::Hide;

};
