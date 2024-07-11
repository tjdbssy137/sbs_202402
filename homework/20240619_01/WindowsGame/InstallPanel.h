#pragma once
#include "Panel.h"

class Button;

enum class InstallButtonManagState
{
	Show,
	Hide,
	None
};
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
public:
	void OnClick_GoToInstallDrill();
	void OnClick_GoToInstallTank();
	void SetState(InstallButtonManagState state) { _state = state; }

private:
	vector<Button*> _buttons = {};
	InstallButtonManagState _state = InstallButtonManagState::Hide;
};