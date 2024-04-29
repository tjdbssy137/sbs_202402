#pragma once
class HammerActor;
class MoleActor;

// 64�ڰ� �Ѵ� �� �ƴ� �̻� ������ Ŭ���� ������ ������ �ʴ´�.
class PlayerHammerController
{
public:
	void Init(HammerActor* playerHammer, vector<MoleActor*> moles);
	void Update();
public:
	void CatchMole();

	// ��������� ������ �˾ƺ� �� �ִ� �� �ٿ��� �� e.g.) hp, ex, pos etc
	void ChangePlayerHammerPos();
private:
	HammerActor* _playerHammer = nullptr;
	vector<MoleActor*> _mole;
};