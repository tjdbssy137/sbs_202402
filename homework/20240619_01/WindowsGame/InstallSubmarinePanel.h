#pragma once
#include "Panel.h"


class InstallSubmarinePanel : public Panel
{
public:
	DECLARE_CHILD(InstallSubmarinePanel, Panel)
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
public:
	void LoadResource();
	void OnClick_GoToInstallSubmarine();
};

