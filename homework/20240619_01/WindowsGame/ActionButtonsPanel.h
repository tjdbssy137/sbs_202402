#pragma once
#include "Panel.h"
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
	void OnClick_GoToUpgrade();
	void OnClick_GoToDelete();
private:
};

