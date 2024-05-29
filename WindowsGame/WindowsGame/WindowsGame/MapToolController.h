#pragma once
class MapToolTilemapActor;
class MapToolController
{
private:
	MapToolTilemapActor* _mapToolActor = nullptr;
public:
	void SetLink(MapToolTilemapActor* mapToolActor);
	void Update();
};

