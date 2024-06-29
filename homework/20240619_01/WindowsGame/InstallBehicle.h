#pragma once
#include "Actor.h"

// ��� ��Ʈ�ѷ����̾���ϳ�?
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

private:
	int _index = 0;
};

