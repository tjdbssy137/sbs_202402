#pragma once
class HammerActor;
class MoleActor;

// 64자가 넘는 게 아닌 이상 변수나 클래스 네임은 줄이지 않는다.
class PlayerHammerController
{
public:
	void Init(HammerActor* playerHammer, vector<MoleActor*> moles);
	void Update();
public:
	void CatchMole();

	// 통상적으로 누구나 알아볼 수 있는 건 줄여도 됨 e.g.) hp, ex, pos etc
	void ChangePlayerHammerPos();
private:
	HammerActor* _playerHammer = nullptr;
	vector<MoleActor*> _mole;
};