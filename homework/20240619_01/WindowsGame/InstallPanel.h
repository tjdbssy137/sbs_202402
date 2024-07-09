#pragma once
#include "Panel.h"

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
	void OnClick_GoToUpGrade();
	void OnClick_GoToInstallDrill();
	void OnClick_GoToInstallTank();
};