#pragma once
#include "TilemapActor.h"
class MapToolTilemapActor : public TilemapActor
{
	DECLARE_CHILD(MapToolTilemapActor, TilemapActor);
public:
	// 타일이 클릭되었을 때 반응
	void Update_Picking();
	void Save();
	void Load();
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};

