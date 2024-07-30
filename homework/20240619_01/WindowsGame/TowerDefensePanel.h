#pragma once
#include "Panel.h"
class Label;
class TowerDefensePanel : public Panel
{
	DECLARE_CHILD(TowerDefensePanel, Panel);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void SetText(wstring text);
	void SetGameInfoText(wstring text);
	void SetInstallInfoText(BehicleData data, float textTimer);
	void SetUpgradeInfoText(BehicleData data, float textTimer);
	void SetDeleteInfoText(BehicleData data, float textTimer);

private:
	Label* _defaultLabel = nullptr;
	Label* _gameInfoLabel = nullptr;
	Label* _infoLabel = nullptr;

private:
	float _textTimer = 0;
	Label* _label = nullptr;
};

