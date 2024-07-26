#pragma once
#include "Panel.h"

class Button;
class Sprite;
class GameStateController : public Panel
{
	// 돈
	// 웨이브 관리
public:
	DECLARE_CHILD(GameStateController, Panel);
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void LoadResource();
	void OnClick_GoToNextWave();
	void SetState(ePanelState state) { _panelState = state; }
	void SetGameWaveState(GameWaveState state) { _state = state; }
private:
	Sprite* _pauseButton = nullptr;
	Button* _nextWaveButton = nullptr;
	GameWaveState _state = GameWaveState::Done;
	ePanelState _panelState = ePanelState::SHOW;

};

