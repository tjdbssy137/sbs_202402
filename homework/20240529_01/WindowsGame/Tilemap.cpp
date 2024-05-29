#include "pch.h"
#include "Tilemap.h"

void Tilemap::LoadFile(const wstring& path)
{
	wifstream ifs;
	ifs.open(path);

	ifs >> _mapSize.x;
	ifs >> _mapSize.y;

	for (int y = 0; y < _mapSize.y; y++)
	{
		wstring line;
		ifs >> line;

		for (int x = 0; x < _mapSize.x; x++)
		{
			int value10 = line[x * 2] - L'0';
			int value1 = line[x * 2 + 1] - L'0';

			_tiles[y][x].value = value10 * 10 + value1;
		}
	}
	ifs.close();
}
void Tilemap::SaveFile(const wstring& path)
{
	wofstream ofs;
	ofs.open(path);

	// 저장할 포맷
	// MapSizeX (28)
	// MapSizeY (21)
	// 00001212000012121200
	// 00001212000012121200
	// 00001212000012121200

	ofs << _mapSize.x << endl;
	ofs << _mapSize.y << endl;

	for (int y = 0; y < _mapSize.y; y++)
	{
		for (int x = 0; x < _mapSize.x; x++)
		{
			ofs << _tiles[y][x].value / 10;
			ofs << _tiles[y][x].value % 10;
		}
		ofs << endl;
	}
	ofs.close();
}
Tile* Tilemap::GetTileAt(Vector2Int pos)
{
	if (pos.x < 0) return nullptr;
	if (pos.y < 0) return nullptr;
	if (_mapSize.x <= pos.x) return nullptr;
	if (_mapSize.y <= pos.y) return nullptr;

	return &_tiles[pos.y][pos.x];
}