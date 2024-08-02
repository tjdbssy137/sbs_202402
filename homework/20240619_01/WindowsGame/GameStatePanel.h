#pragma once
#include "Panel.h"

class Button;
class Image;
class TowerDefensePanel;

class GameStatePanel : public Panel
{
public:
	DECLARE_CHILD(GameStatePanel, Panel);
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void LoadResource();
	void OnClick_GoToNextWave();
	void OnClick_GoToInstall();

	void SetState(ePanelState state) { _panelState = state; }
	GameWaveState GetGameWaveState() { return _state; }

private:
	Image* _pauseButton = nullptr;
	Button* _nextWaveButton = nullptr;
	GameWaveState _state = GameWaveState::Done;
	ePanelState _panelState = ePanelState::SHOW;
private:
	TowerDefensePanel* _mainPanel = nullptr;
};
