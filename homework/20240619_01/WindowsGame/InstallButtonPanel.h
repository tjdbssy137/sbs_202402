#pragma once
#include "Panel.h"

class Button;
class InstallButtonPanel : public Panel
{
public:
	DECLARE_CHILD(InstallButtonPanel, Panel);
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void LoadResource();
	void OnClick_GoToInstall();
	void OnClick_GoToCancel();
private:

};

