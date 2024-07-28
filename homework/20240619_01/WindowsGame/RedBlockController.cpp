#include "pch.h"
#include "RedBlockController.h"
#include "RedBlockActor.h"
#include "TilemapScene.h"
#include "Tilemap.h"
#include "TilemapActor.h"
#include "TowerDefenseScene.h"
#include "BehicleActor.h"
#include "GameStateController.h"
#include "TowerDefensePanel.h"

void RedBlockController::SetLink(RedBlockActor* block)
{
	assert(block != nullptr);
	_block = block;

	_mainPanel = new TowerDefensePanel();
	_mainPanel->Init();

	CurrentScene->AddUI(_mainPanel);

	// Add Event
	Events->AddEvent("RemoveInstallPos", new GameEvent<Vector2Int>());
	Events->GetEvent<Vector2Int>("RemoveInstallPos")
		->AddListen(this, &RedBlockController::RemoveAlreadyInstallPos);

	Events->AddEvent("OnMouse", new GameEvent<>());
	Events->GetEvent<>("OnMouse")
		->AddListen(this, &RedBlockController::OnMouse);

}

void RedBlockController::Update()
{
	// ��ġ ��� Ű
	if (Input->GetKeyDown(KeyCode::RightMouse))
	{
		// ���� Ŭ���� �ϴ� ���� pos�� �߰� ��.
		// �ƹ��͵� �� �� ���¿��� ������ Ŭ���� �ϸ� pos�� �����ؾ���.
		//	behicle�� ��ġ �Ǿ� ������ pos ���� �� �ؾ���.

		TowerDefenseScene* towerDefenseScene = dynamic_cast<TowerDefenseScene*>(CurrentScene);
		vector<BehicleActor*> _behicles = towerDefenseScene->GetBehicleActor();
		bool isThere = false;
		for (BehicleActor* behicle : _behicles)
		{
			if (behicle->GetCellPos() == _pos)
			{
				isThere = true;
				break;
			}
		}
		if (isThere == false)
		{
			RemoveAlreadyInstallPos(_pos);
		}
		this->OffMouse();
	}

	// ���� �ʱ�ȭ
	_textTimer -= Time->GetDeltaTime();
	if (_textTimer <= 0)
	{
		_mainPanel->SetText(L"");
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
void RedBlockController::OnMouse()
{
	_block->SetSprite(Resource->GetSprite(L"S_RedTile"));
	_mouseState = MouseState::Move;
}
void RedBlockController::OffMouse()
{
	cout << "OffMouse" << endl;
	_mouseState = MouseState::Nothing;
	GameEvent<ePanelState>* gameEvent = Events->GetEvent<ePanelState>("SetPanelState_ActionButtonsPanel");
	gameEvent->Invoke(ePanelState::HIDE);

	GameEvent<ePanelState>* gameEvent2 = Events->GetEvent<ePanelState>("SetPanelState_InstallSubmarinePanel");
	gameEvent2->Invoke(ePanelState::HIDE);

	GameEvent<ePanelState>* gameEvent3 = Events->GetEvent<ePanelState>("SetPanelState_InstallPanel");
	gameEvent3->Invoke(ePanelState::HIDE);
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
	//int x = pos.x; // �̹� 32�� �����ְ� ����! �׷��� �����൵ ��.
	//int y = pos.y;
	//cout << "x : " << x << "	y : " << y << endl;
	_block->SetCellPos(pos, true);

	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		Tilemap* tilemap = tilemapActor->GetTileMap();
		assert(tilemap != nullptr);
		
		Tile* tile = tilemap->GetTileAt(pos);

		{//�̹� ��ġ�� �Ǿ�������, �¸� ��ȸ�ϰ�
			auto findIt = find(_alreadyInstallBehicle.begin(), _alreadyInstallBehicle.end(), pos);
			if (findIt != _alreadyInstallBehicle.end())
			{
				//cout << "Upgrade or Delete" << endl;
				_pos = pos;
				_mouseState = MouseState::UpgradeDelete; // ���׷��̵� & ���� �ǳ��� ����.
			}
			else
			{
				if (tile->value == 4 || (14 <= tile->value && tile->value <= 45))
				{
					_alreadyInstallBehicle.push_back(pos);
					_pos = pos;
					_mouseState = MouseState::ClickGround;
				}
				else if (46 <= tile->value && tile->value < 62) // 51�� ��
				{
					TowerDefenseScene* towerDefenseScene = dynamic_cast<TowerDefenseScene*>(CurrentScene);
					GameStateController* gameStateController = towerDefenseScene->GetGameStateController();
					if (gameStateController->GetGameWaveState() == GameWaveState::Wave)
					{
						_mainPanel->SetText(L"������ ��Ÿ���� �߿��� ����� ��ġ�� �Ұ��մϴ�.");
						_textTimer = 2.0f;
					}
					else
					{
						_alreadyInstallBehicle.push_back(pos);
						_pos = pos;
						_mouseState = MouseState::ClickOcean;
					}
				}
			}
		}
	}
}
void RedBlockController::DoInstallGround()
{
	GameEvent<ePanelState>* gameEvent = Events->GetEvent<ePanelState>("SetPanelState_InstallPanel");
	gameEvent->Invoke(ePanelState::SHOW);

	_mouseState = MouseState::Nothing;
}
void RedBlockController::DoInstallOcean()
{
	GameEvent<ePanelState>* gameEvent = Events->GetEvent<ePanelState>("SetPanelState_InstallSubmarinePanel");
	gameEvent->Invoke(ePanelState::SHOW);

	_mouseState = MouseState::Nothing;
}
void RedBlockController::DoUpgradeDeleteBehicle()
{
	// Ÿ���� ������.
	// �̹� ��ġ�� �Ǿ�������, �¸� ��ȸ�ϰ�
	// ���׷��̵� & ���� �ǳ��� ����.
	TowerDefenseScene* towerDefenseScene = dynamic_cast<TowerDefenseScene*>(CurrentScene);
	vector<BehicleActor*> _behicles = towerDefenseScene->GetBehicleActor();
	
	_Index = 0;
	for (BehicleActor* behicle : _behicles)
	{
		if (behicle->GetCellPos() == _pos)
		{
			break;
		}
		_Index++;
	}
	GameEvent<ePanelState>* gameEvent = Events->GetEvent<ePanelState>("SetPanelState_ActionButtonsPanel");
	gameEvent->Invoke(ePanelState::SHOW);

	_mouseState = MouseState::Nothing;

}

void RedBlockController::RemoveAlreadyInstallPos(Vector2Int pos)
{
	auto findIt = find(_alreadyInstallBehicle.begin(), _alreadyInstallBehicle.end(), pos);
	if (findIt != _alreadyInstallBehicle.end())
	{
		_alreadyInstallBehicle.erase(findIt);
	}
}
