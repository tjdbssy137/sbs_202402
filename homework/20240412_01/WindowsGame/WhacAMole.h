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
	int _used = 13;//������ TimeToComingMole()ȣ�� ���� ��, Random ���� �ߺ� ����

private:
	GameState _gameState = GameState::None;
	float _playTime = 0;

	WhacAMoleGameController* _whacAMoleGameController = nullptr;
};

// 3 X 3 ���� ����� - ���
// �δ����� ��Ÿ���� - �δ���
//		- �����ϰ� draw�� ����?
// ���콺�� Ŭ���Ѵ�
//		- ���콺��ǥ�� ����ٴϴ� �׸� ���ڰ� ����