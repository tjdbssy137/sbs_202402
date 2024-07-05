#pragma once
#include "Panel.h"

enum class ClickButtonState
{
	Submarine,
	Tank,
	DrillTank,
	Done
};
class InstallPanel : public Panel
{
	DECLARE_CHILD(InstallPanel, Panel)
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
public:
	void LoadResource();
public:
	void OnClick_GoToUpGrade();
	void OnClick_GoToInstallDrill();
	void OnClick_GoToInstallTank();
	void OnClick_GoToInstallSubmarine();
private:
	ClickButtonState _state = ClickButtonState::Done;
};