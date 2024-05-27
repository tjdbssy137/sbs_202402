#pragma once
#include "ResourceBase.h"

struct Tile
{
	// 추후에 타일에 대한 정보가 추가되면, 여기에 값을 추가해주면 됨
	int value = 0;
};
class Tilemap : public ResourceBase
{
	DECLARE_CHILD(Tilemap, ResourceBase);
public:
	virtual void LoadFile(const wstring& path);
	virtual void SaveFile(const wstring& path);
public:
	Vector2Int GetMapSize() { return _mapSize; }
	int GetTileSize() { return _tileSize; }
	void SetTiles(vector<vector<Tile>> tiles) { _tiles = tiles; }
	vector<vector<Tile>>& GetTiles() { return _tiles; }
	Tile* GetTileAt(Vector2Int pos);

	void SetMapSize(Vector2Int mapSize) { _mapSize = mapSize; }
	void SetTileSize(int tileSize) { _tileSize = tileSize; }

protected:
	Vector2Int _mapSize = {};
	int _tileSize = 0; // 항상 정사각형이기에
	vector<vector<Tile>> _tiles;
};