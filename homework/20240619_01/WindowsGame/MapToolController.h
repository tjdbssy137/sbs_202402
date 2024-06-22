#pragma once
class MapToolTilemapActor;
class MapToolController
{
private:
	MapToolTilemapActor* _mapToolActor = nullptr;
public:
	void SetLink(MapToolTilemapActor* mapToolActor);
	void Update();

public:
	//Vector2Int GetStartPos() { return _start; }
	Vector2Int GetGoalPos() { return _goal; }
private:
	//Vector2Int _start = {};
	Vector2Int _goal = {};

};

