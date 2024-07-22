#pragma once
#include "Actor.h"

class BehicleController;
// ��� ��Ʈ�ѷ����̾���ϳ�?
// �� ���� �ʿ� ����
class InstallBehicle : public Actor
{
public:
	DECLARE_CHILD(InstallBehicle, Actor);
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void InstallBehicleFunc(Vector2Int pos);

public:
	void SetBehicleTypeState(int type) { _type = type; }

private:
	int _type = 0;

};

