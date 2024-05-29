#include "pch.h"
#include "TilemapActor.h"
#include "Tilemap.h"
#include "Sprite.h"
#include "Scene.h"
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

	Vector2Int cameraPos = CurrentScene->GetCameraPos();
	Vector2Int screenSizeHalf = Vector2Int(WIN_SIZE_X / 2, WIN_SIZE_Y / 2);

	//이 타일이 카메라 안이면 그림을 그리고
	//이 타일이 카메라 밖이면 continue; 한다.

	int startX = 0, startY = 0;
	int endX = 0, endY = 0;

	// 수학공식
	int left = static_cast<int>(cameraPos.x - screenSizeHalf.x);
	int top = static_cast<int>(cameraPos.y - screenSizeHalf.y);
	int right = static_cast<int>(cameraPos.x + screenSizeHalf.x);
	int bottom = static_cast<int>(cameraPos.y + screenSizeHalf.y);

	startX = (left - this->_body.pos.x) / tileSize;
	startX = max(startX, 0);
	startY = (top - this->_body.pos.y) / tileSize;
	startY = max(startY, 0);
	endX = (right - this->_body.pos.x) / tileSize;
	endX = min(endX + 1, mapSize.x);

	endY = (bottom - this->_body.pos.y) / tileSize;
	endY = min(endY + 1, mapSize.y);



	for (int y = startY; y < endY; y++)
	{
		for (int x = startX; x < endX; x++)
		{
			if (_sprites.size() <= tiles[y][x].value)
				continue;

			Sprite* renderSprite = _sprites[tiles[y][x].value];
			//x,y 에 따라서 renderPos가 달라짐.

			Vector2Int renderPos = Vector2Int(
				static_cast<int>(_body.pos.x + x * tileSize - cameraPos.x + screenSizeHalf.x),
				static_cast<int>(_body.pos.y + y * tileSize - cameraPos.y + screenSizeHalf.y)
			);



			::TransparentBlt(hdc,
				renderPos.x,
				renderPos.y,
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
