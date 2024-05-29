#pragma once
#include "ResourceBase.h"

struct Tile
{
	//���Ŀ� Ÿ�Ͽ� ���� ������ �߰��Ǹ�, ���⿡ ���� �߰����ָ� ��
	int value = 0;
};

class Tilemap : public ResourceBase
{
	DECLARE_CHILD(Tilemap, ResourceBase)

public:
	virtual void LoadFile(const wstring& path);
	virtual void SaveFile(const wstring& path);

public:
	Vector2Int GetMapSize() { return _mapSize; }
	int GetTileSize() { return _tileSize; }
	void SetTiles(vector<vector<Tile>> tiles) { _tiles = tiles; }
	vector<vector<Tile>>& GetTiles() { return _tiles; }
	Tile* GetTileAt(Vector2Int pos);

	void SetMapSize(Vector2Int size) { _mapSize = size; }
	void SetTileSize(int size) { _tileSize = size; }

protected:
	Vector2Int _mapSize = {};
	int _tileSize = 0;	//�׻� ���簢�� ����̱⶧����.
	vector<vector<Tile>> _tiles;


};

