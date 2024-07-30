#pragma once
#include "Panel.h"

class Button;

class InstallPanel : public Panel
{
public:
	DECLARE_CHILD(InstallPanel, Panel)
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
public:
	void LoadResource();
	void InstallingBehicle(BehicleData data);
public:
	void OnClick_GoToInstallDrill();
	void OnClick_GoToInstallTank();

	void OnHover_GoToInstallDrill();
	void OnHover_GoToInstallTank();

	void SetState(ePanelState state) { _state = state; }

private:
	vector<Button*> _buttons = {};
	ePanelState _state = ePanelState::HIDE;
};