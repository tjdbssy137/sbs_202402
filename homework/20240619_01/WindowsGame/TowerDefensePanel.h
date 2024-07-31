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
	void SetInstallInfoText(BehicleData data, float textTimer = 1);
	void SetUpgradeInfoText(BehicleData data, float textTimer = 1);
	void SetDeleteInfoText(BehicleData data, float textTimer = 1);
	void SetTimerText(wstring text, float textTimer = 1);

private:
	Label* _defaultLabel = nullptr;
	Label* _gameInfoLabel = nullptr;
	Label* _infoLabel = nullptr;
	Label* _timerLabel = nullptr;

private:
	float _textTimer = 0;
	float _textLabelTimer = 0;

};

