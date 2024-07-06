#pragma once
#include "BehicleActor.h"
class SubmarineActor : public BehicleActor
{
public:
	DECLARE_CHILD(SubmarineActor, BehicleActor);
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public: // ��ӹ��� �������̽��� �Լ��� ������ ������ ������ ��.
	virtual void SetCellPos(Vector2Int cellPos, bool teleport = false) override;
	virtual Vector2Int GetCellPos() override;

public:
	/*void SetBehicleType(wstring behicleType) { _behicleType = behicleType; }
	wstring GetBehicleType() { return _behicleType; }*/
private:
	Vector2 _destPos = {};
	Vector2Int _cellPos = {};
private:
	BehicleState _state = BehicleState::Idle; 
	eDirection _dir = eDirection::DOWN;
	Flipbook* _idleFlipbook[8] = {};
	wstring _behicleType = L"FB_Submarine_";
};

