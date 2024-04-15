#pragma once
#include "Scene.h"
#include "MoleActor.h"
#include "MoleHouseActor.h"
#include "HammerActor.h"

class WhacAMole : public Scene
{
	using Super = Scene;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

private:
	vector<MoleActor*> _mole;
	vector<MoleHouseActor*> _moleHouse;
	HammerActor* _hammer = nullptr;

	int _point = 0;
	float _time = 0;
};

// 3 X 3 판을 만든다 - 배경
// 두더지가 나타난다 - 두더지
//		- 랜덤하게 draw를 조절?
// 마우스로 클릭한다
//		- 마우스좌표를 따라다니는 네모 상자가 있음