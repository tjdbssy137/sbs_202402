#pragma once
#include "Actor.h"
class Tilemap;
class Sprite;
class TilemapActor : public Actor
{
	DECLARE_CHILD(TilemapActor, Actor);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	Tilemap* GetTileMap() { return _tilemap; }
	void SetTileMap(Tilemap* tilemap) { _tilemap = tilemap; }
	void SetTileSprites(vector<Sprite*> sprites) { _sprites = sprites; }
	vector<Sprite*>& GetTileSprites() { return _sprites; }

	Vector2Int GetTileIndexByPos(Vector2 checkPos);

	void LoadTilemap(wstring filename);
protected:
	Tilemap* _tilemap = nullptr;
	vector<Sprite*> _sprites;
};