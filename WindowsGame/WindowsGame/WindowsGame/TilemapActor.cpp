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

	//Ÿ�ϸ��� ��ĭ�� �������鼭 ��ĭ��ĭ �׸���.
	Tilemap* tileMap = this->GetTileMap();

	if (tileMap == nullptr) return;


	Vector2Int mapSize = tileMap->GetMapSize();
	vector<vector<Tile>>& tiles = tileMap->GetTiles();

	int tileSize = tileMap->GetTileSize();


	Vector2Int cameraPos = CurrentScene->GetCameraPos();
	Vector2Int ScreenSizeHalf = Vector2Int(WIN_SIZE_X / 2, WIN_SIZE_Y / 2);
	// �� Ÿ���� ī�޶� ���̸� �׸��� �׸���
	// �� Ÿ���� ī�޶� ���̸� continue; �Ѵ�

	int startX = 0, startY = 0;
	int endX = 0, endY = 0;

	// ���� ����
	int left = static_cast<int>(cameraPos.x - ScreenSizeHalf.x);
	int top = static_cast<int>(cameraPos.y - ScreenSizeHalf.y);
	int right = static_cast<int>(cameraPos.x + ScreenSizeHalf.x);
	int bottom = static_cast<int>(cameraPos.y + ScreenSizeHalf.y);

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
			//x,y �� ���� renderPos�� �޶���.

			Vector2Int renderPos = Vector2Int(
				static_cast<int>(_body.pos.x - tileSize / 2 - cameraPos.x + ScreenSizeHalf.x),
				static_cast<int>(_body.pos.y - tileSize / 2 - cameraPos.y + ScreenSizeHalf.y)
			);

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
