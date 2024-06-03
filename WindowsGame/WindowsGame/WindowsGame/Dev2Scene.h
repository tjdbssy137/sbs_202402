#pragma once
#include "TilemapScene.h" // �갡 �̹� Scene�� ��� �ް� ����

class MapToolController;
class CreatureController;
class Panel;
class TilemapActor;
class Dev2Scene : public TilemapScene
{
	using Super = Scene;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void LoadResource();

public:
	virtual Vector2 GetTilemapPos(Vector2Int cellPos) override;
	virtual bool CanGo(Actor* actor, Vector2Int cellPos) override;

private:
	//Panel* panel = nullptr;
	TilemapActor* _tilemapActor = nullptr;
	MapToolController* _mapToolController = nullptr;
	CreatureController* _creatureController = nullptr;
};