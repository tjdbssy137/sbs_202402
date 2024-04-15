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

// 3 X 3 ���� ����� - ���
// �δ����� ��Ÿ���� - �δ���
//		- �����ϰ� draw�� ����?
// ���콺�� Ŭ���Ѵ�
//		- ���콺��ǥ�� ����ٴϴ� �׸� ���ڰ� ����