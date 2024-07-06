#include "pch.h"
#include "RedBlockController.h"
#include "RedBlockActor.h"
#include "TilemapScene.h"
#include "Tilemap.h"
#include "TilemapActor.h"
#include "Dev2Scene.h"
#include "InstallPanel.h"
#include "InstallSubmarinePanel.h"
void RedBlockController::SetLink(RedBlockActor* block)
{
	assert(block != nullptr);
	_block = block;
}

void RedBlockController::Update()
{
	if (Input->GetKeyDown(KeyCode::A))
	{
		_block->SetSprite(Resource->GetSprite(L"S_RedTile"));
		_mouseState = MouseState::Move;
	}

	if (Input->GetKeyDown(KeyCode::D))
	{
		_mouseState = MouseState::Nothing;
	}

	switch (_mouseState)
	{
	case MouseState::Move:
		CanInstallBehicle();
		break;
	case MouseState::ClickGround:
		DoInstallGround();
		break;
	case MouseState::ClickOcean:
		DoInstallOcean();
		break;
	case MouseState::Nothing:
		_block->SetSprite(nullptr);
		break;
	default:
		break;
	}
}
void RedBlockController::DoInstallGround()
{
	Dev2Scene* dev2Scene = dynamic_cast<Dev2Scene*>(CurrentScene);
	InstallPanel* installPanel = dev2Scene->GetInstallPanel();
	installPanel->Show();
	_mouseState = MouseState::Nothing;
}
void RedBlockController::DoInstallOcean()
{
	Dev2Scene* dev2Scene = dynamic_cast<Dev2Scene*>(CurrentScene);
	InstallSubmarinePanel* installSubmarinePanel = dev2Scene->GetInstallSubmarinePanel();
	installSubmarinePanel->Show();
	_mouseState = MouseState::Nothing;
}
void RedBlockController::CanInstallBehicle()
{
	TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);
	assert(scene != nullptr);
	if (scene == nullptr)
	{
		return;
	}
	TilemapActor* tilemapActor = scene->GetTilemapActor();
	assert(tilemapActor != nullptr);
	if (tilemapActor == nullptr)
	{
		return;
	}
	Vector2Int pos = tilemapActor->GetTileIndexByPos(Input->GetMousePos());
	//cout << "pos.x : " << pos.x << "	pos.y : " << pos.y << endl;
	//int x = pos.x; // ÀÌ¹Ì 32¸¦ °öÇØÁÖ°í ÀÖÀ½! ±×·¡¼­ ¾ÈÇØÁàµµ µÊ.
	//int y = pos.y;
	//cout << "x : " << x << "	y : " << y << endl;
	_block->SetCellPos(pos, true);

	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		Tilemap* tilemap = tilemapActor->GetTileMap();
		assert(tilemap != nullptr);
		
		Tile* tile = tilemap->GetTileAt(pos);
		if (tile->value == 4 || (14 <= tile->value && tile->value <= 45))
		{
			cout << "°Ç¼³ µÊ" << endl;
			_pos = pos;
			_mouseState = MouseState::ClickGround;
		}
		else if (46 <= tile->value && tile->value < 62) // 51ÀÌ ¹°
		{
			// ONLY submrine 
			cout << "°Ç¼³ µÊ" << endl;
			_pos = pos;
			_mouseState = MouseState::ClickOcean;
		}
		else
		{
			cout << "°Ç¼³ ¾È µÊ" << endl;
		}
	}
}