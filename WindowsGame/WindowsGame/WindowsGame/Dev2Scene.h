#pragma once
#include "Scene.h"

class MapToolController;
class CreatureController;
class Panel;
class Dev2Scene : public Scene
{
	using Super = Scene;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void LoadResource();
	int GetTileSize() { return _tileSize; }
private:
	//Panel* panel = nullptr;
	MapToolController* _mapToolController = nullptr;
	CreatureController* _creatureController = nullptr;
	int _tileSize = 88;
};