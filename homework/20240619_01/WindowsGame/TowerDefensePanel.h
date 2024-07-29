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

private:
	Label* _waveStatusLabel = nullptr;
	Label* _gameInfoLabel = nullptr;
};

