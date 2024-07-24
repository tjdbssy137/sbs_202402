#include "pch.h"
#include "RedBlockActor.h"
#include "TowerDefenseScene.h"

void RedBlockActor::Init()
{
	Super::Init();
	//this->SetSprite(Resource->GetSprite(L"S_RedTile"));
}
void RedBlockActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void RedBlockActor::Update()
{
	Super::Update();
}
void RedBlockActor::Release()
{
	Super::Release();
}
void RedBlockActor::SetCellPos(Vector2Int cellPos, bool teleport)
{
	_cellPos = cellPos;
	
	TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);

	if (scene == nullptr)
	{
		return;
	}
	Vector2 destPos = scene->GetTilemapPos(cellPos);
	_destPos = destPos;
	
	if (teleport)
	{
		this->SetPos(_destPos);
	}
}
Vector2Int RedBlockActor::GetCellPos()
{
	return _cellPos;
}