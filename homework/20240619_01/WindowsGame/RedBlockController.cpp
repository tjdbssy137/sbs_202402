#include "pch.h"
#include "RedBlockController.h"
#include "RedBlockActor.h"
#include "TilemapScene.h"
#include "Tilemap.h"
#include "TilemapActor.h"
#include "Dev2Scene.h"
#include "InstallPanel.h"
#include "InstallSubmarinePanel.h"
#include "ActionButtonsPanel.h"
#include "BehicleActor.h"

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
		Dev2Scene* dev2Scene = dynamic_cast<Dev2Scene*>(CurrentScene);
		
		InstallPanel* installPanel = dev2Scene->GetInstallPanel();
		installPanel->SetState(InstallButtonManagState::Hide);
		installPanel->Hide();
		
		InstallSubmarinePanel* installSubmarinePanel = dev2Scene->GetInstallSubmarinePanel();
		installSubmarinePanel->SetState(InstallSubmarineButtonManagState::Hide);
		installSubmarinePanel->Hide();

		ActionButtonsPanel* actionPanel = dev2Scene->GetActionButtonsPanel();
		actionPanel->SetState(ActionButtonsButtonManagState::Hide);
		actionPanel->Hide();
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
	case MouseState::UpgradeDelete:
		DoUpgradeDeleteBehicle();
		break;
	case MouseState::Nothing:
		_block->SetSprite(nullptr);
		break;
	default:
		break;
	}
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
	//int x = pos.x; // 이미 32를 곱해주고 있음! 그래서 안해줘도 됨.
	//int y = pos.y;
	//cout << "x : " << x << "	y : " << y << endl;
	_block->SetCellPos(pos, true);

	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		Tilemap* tilemap = tilemapActor->GetTileMap();
		assert(tilemap != nullptr);
		
		Tile* tile = tilemap->GetTileAt(pos);

		{//이미 설치가 되어있으면, 걔를 조회하고
			auto findIt = find(_alreadyInstallBehicle.begin(), _alreadyInstallBehicle.end(), pos);
			if (findIt != _alreadyInstallBehicle.end())
			{
				cout << "Upgrade or Delete" << endl;
				_pos = pos;
				_mouseState = MouseState::UpgradeDelete; // 업그레이드 & 삭제 판넬을 띄운다.
			}
			else
			{
				if (tile->value == 4 || (14 <= tile->value && tile->value <= 45))
				{
					_alreadyInstallBehicle.push_back(pos);

					cout << "건설 됨" << endl;
					_pos = pos;
					_mouseState = MouseState::ClickGround;
				}
				else if (46 <= tile->value && tile->value < 62) // 51이 물
				{
					// ONLY submrine 
					_alreadyInstallBehicle.push_back(pos);

					cout << "건설 됨" << endl;
					_pos = pos;
					_mouseState = MouseState::ClickOcean;
				}
				else
				{
					cout << "건설 안 됨" << endl;
				}
			}
		}
	}
}
void RedBlockController::DoInstallGround()
{
	Dev2Scene* dev2Scene = dynamic_cast<Dev2Scene*>(CurrentScene);
	InstallPanel* installPanel = dev2Scene->GetInstallPanel();
	installPanel->SetState(InstallButtonManagState::Show);
	installPanel->Show();
	_mouseState = MouseState::Nothing;
}
void RedBlockController::DoInstallOcean()
{
	Dev2Scene* dev2Scene = dynamic_cast<Dev2Scene*>(CurrentScene);
	InstallSubmarinePanel* installSubmarinePanel = dev2Scene->GetInstallSubmarinePanel();
	installSubmarinePanel->SetState(InstallSubmarineButtonManagState::Show);
	installSubmarinePanel->Show();
	_mouseState = MouseState::Nothing;
}
void RedBlockController::DoUpgradeDeleteBehicle()
{
	// 타일을 누른다.
	// 이미 설치가 되어있으면, 걔를 조회하고
	// 업그레이드 & 삭제 판넬을 띄운다.
	Dev2Scene* dev2Scene = dynamic_cast<Dev2Scene*>(CurrentScene);
	ActionButtonsPanel* actionPanel = dev2Scene->GetActionButtonsPanel();
	vector<BehicleActor*> _behicles = dev2Scene->GetBehicleActor();
	
	_Index = 0;
	for (BehicleActor* behicle : _behicles)
	{
		if (behicle->GetCellPos() == _pos)
		{
			break;
		}
		_Index++;
	}
	actionPanel->SetState(ActionButtonsButtonManagState::Show);
	actionPanel->Show();
	_mouseState = MouseState::Nothing;

}