#pragma once
#include "Scene.h"

class MoleActor;
class MoleHouseActor;
class HammerActor;
class InGameState;
class WhacAMoleGameController;

class WhacAMole : public Scene
{
	using Super = Scene;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

	void TimeToComingMole(float time);

	void ChangeGameState(GameState state);
	GameState GetGameState() { return _gameState; }

private:
	vector<MoleActor*> _mole;
	vector<MoleHouseActor*> _moleHouse;
	HammerActor* _hammer = nullptr;

	int _point = 0;
	float _time = 0;
	int _used = 13;//여러번 TimeToComingMole()호출 했을 때, Random 숫자 중복 방지

private:
	GameState _gameState = GameState::None;
	float _playTime = 0;

	WhacAMoleGameController* _whacAMoleGameController = nullptr;
};

// 3 X 3 판을 만든다 - 배경
// 두더지가 나타난다 - 두더지
//		- 랜덤하게 draw를 조절?
// 마우스로 클릭한다
//		- 마우스좌표를 따라다니는 네모 상자가 있음