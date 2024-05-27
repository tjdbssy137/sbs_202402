#include "pch.h"
#include "TilemapActor.h"
#include "Tilemap.h"
#include "Sprite.h"
void TilemapActor::Init()
{
	Super::Init();
}
void TilemapActor::Render(HDC hdc)
{
	Super::Render(hdc);

	//타일맵을 한칸씩 루프돌면서 한칸한칸 그리기.
	Tilemap* tileMap = this->GetTileMap();

	if (tileMap == nullptr) return;


	Vector2Int mapSize = tileMap->GetMapSize();
	vector<vector<Tile>>& tiles = tileMap->GetTiles();

	int tileSize = tileMap->GetTileSize();

	for (int y = 0; y < mapSize.y; y++)
	{
		for (int x = 0; x < mapSize.x; x++)
		{
			if (_sprites.size() <= tiles[y][x].value)
				continue;

			Sprite* renderSprite = _sprites[tiles[y][x].value];
			//x,y 에 따라서 renderPos가 달라짐.
			::TransparentBlt(hdc,
				_body.pos.x + x * tileSize,
				_body.pos.y + y * tileSize,
				tileSize,
				tileSize,
				renderSprite->GetDC(),
				renderSprite->GetPos().x,
				renderSprite->GetPos().y,
				tileSize,
				tileSize,
				renderSprite->GetTransparent()
			);
		}
	}
}

void TilemapActor::Update()
{
	Super::Update();
}
void TilemapActor::Release()
{
	Super::Release();
}
