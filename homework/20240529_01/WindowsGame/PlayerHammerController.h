#pragma once
class HammerActor;
class MoleActor;
class PlayerHammerController
{
public:
	void Init(HammerActor* playerHammer, vector<MoleActor*> moles);
	void Update();

	//플레이어 해머를 마우스 위치로 변경시킨다.
	void ChangePlayerHammerPos();

	// - 마우스를 클릭하면, 플레이어 해머와 두더지가 충돌되어있으면 점수가 오른다.
	// 두더지는 죽는다.
	void CatchMole();

private:
	HammerActor* _playerHammer;
	vector<MoleActor*> _moles;
};

