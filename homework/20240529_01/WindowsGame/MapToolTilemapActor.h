#pragma once
#include "TilemapActor.h"
class MapToolTilemapActor : public TilemapActor
{
	DECLARE_CHILD(MapToolTilemapActor, TilemapActor);

public:
	void Save();
	void Load();

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};

