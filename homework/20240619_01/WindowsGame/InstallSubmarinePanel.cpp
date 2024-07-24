#include "pch.h"
#include "InstallSubmarinePanel.h"
#include "Image.h"
#include "Button.h"
#include "TowerDefenseScene.h"
#include "RedBlockController.h"
#include "BehicleController.h"
#include "BehicleActor.h"
#include "Tilemap.h"
#include <queue>

void InstallSubmarinePanel::Init()
{
	Super::Init();
	{
		this->LoadResource();

		Panel* iconListPanel = new Panel();
		{
			iconListPanel->SetRect(Shape::MakeCenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y / 2, 100, 40));
			this->AddChild(iconListPanel);
		}

		{
			Image* image1 = new Image();
			image1->SetRect(Shape::MakeCenterRect(0, 0, 0, 0));
			image1->SetSprite(Resource->GetSprite(L"S_Button_S"));
			image1->Init();
			iconListPanel->AddChild(image1);
		}

		{
			Button* submarineButton = new Button();
			submarineButton->SetRect(Shape::MakeCenterRect(0, 0, 32, 32));
			submarineButton->SetSprite(ButtonState::Default, Resource->GetSprite(L"S_Submarine_Default"));
			submarineButton->SetSprite(ButtonState::Hover, Resource->GetSprite(L"S_Submarine_Hover"));
			submarineButton->SetSprite(ButtonState::Pressed, Resource->GetSprite(L"S_Submarine_Pressed"));
			submarineButton->SetSprite(ButtonState::Disabled, Resource->GetSprite(L"S_Submarine_Disabled"));
			submarineButton->AddOnClickDelegate(this, &InstallSubmarinePanel::OnClick_GoToInstallSubmarine);
			submarineButton->Init();
			iconListPanel->AddChild(submarineButton);
			_buttons.push_back(submarineButton);
		}
	}
}

void InstallSubmarinePanel::Render(HDC hdc)
{
	Super::Render(hdc);
}
void InstallSubmarinePanel::Update()
{
	Super::Update();
	switch (_state)
	{
	case ePanelState::Show:
	{
		for (Button* button : _buttons)
		{
			button->SetState(ButtonState::Default);
		}
		_state = ePanelState::None;
	}
	break;
	case ePanelState::Hide:
	{
		for (Button* button : _buttons)
		{
			button->SetState(ButtonState::Disabled);
		}
		_state = ePanelState::None;
	}
	break;
	case ePanelState::None:
		break;
	default:
		break;
	}
}
void InstallSubmarinePanel::Release()
{
	Super::Release();
}

void InstallSubmarinePanel::OnClick_GoToInstallSubmarine()
{
	TowerDefenseScene* towerDefenseScene = dynamic_cast<TowerDefenseScene*>(CurrentScene);
	RedBlockController* redBlockController = towerDefenseScene->GetRedBlockController();
	Vector2Int pos = redBlockController->GetInstallBehiclePos();

	bool isFind = Check_Astar(STARTPOS, DESTPOS, pos);

	if (Datas->GetBehicleData(7).InstallGold <= towerDefenseScene->GetGold())
	{
		if (isFind == false)
		{
			// 설치 안됐으니까 RedBlockController에 있는 pos에서 다시 삭제해야함.
			// ActionButtons의 Delete코드 참고
			cout << "Not Create Behicle" << endl;

			vector<Vector2Int> alreadyInstallBehicle = redBlockController->GetAlreadyInstallBehicle();

			auto findIt = find(alreadyInstallBehicle.begin(), alreadyInstallBehicle.end(), pos);
			if (findIt != alreadyInstallBehicle.end())
			{
				alreadyInstallBehicle.erase(findIt);
				redBlockController->SetAlreadyInstallBehicle(alreadyInstallBehicle);
			}
		}
		else
		{
			BehicleController* behicleController = new BehicleController();
			{
				cout << "Create Behicle" << endl;
				BehicleActor* behicle = new BehicleActor();
				behicle->SetLayer(LayerType::Character);
				behicleController->SetLink(behicle);
				behicleController->IsSetting(true);
				behicleController->SetBehicleTypeState(static_cast<int>(BehicleTypeState::Submarine));
				behicle->Init();
				towerDefenseScene->SpawnActor(behicle);
				behicle->SetCellPos(pos, true);
				towerDefenseScene->SetBehicleActor(behicle);
			}
			towerDefenseScene->SetBehicleController(behicleController); //_behicleControllers.push_back
			towerDefenseScene->PayGold(Datas->GetBehicleData(7).InstallGold);
		}
	}
	else
	{
		vector<Vector2Int> alreadyInstallBehicle = redBlockController->GetAlreadyInstallBehicle();

		auto findIt = find(alreadyInstallBehicle.begin(), alreadyInstallBehicle.end(), pos);
		if (findIt != alreadyInstallBehicle.end())
		{
			alreadyInstallBehicle.erase(findIt);
			redBlockController->SetAlreadyInstallBehicle(alreadyInstallBehicle);
		}
	}

	_state = ePanelState::Hide;
	this->Hide();
}

bool InstallSubmarinePanel::Check_Astar(Vector2Int startPos, Vector2Int endPos, Vector2Int SubmarinePos)
{
	vector<Vector2Int> result;
	TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);
	assert(scene != nullptr);
	if (scene == nullptr)
	{
		return false;
	}

	Tilemap* tilemap = scene->GetTilemap();
	assert(tilemap != nullptr);
	if (tilemap == nullptr)
	{
		return false;
	}

	priority_queue<PQNode, vector<PQNode>, greater<PQNode>> queue;

	Vector2Int dest = endPos;
	PQNode node;
	node.Vertex = startPos;
	node.G = 0;
	node.Cost = node.G + (dest - startPos).Length();
	queue.push(node);

	Vector2Int mapSize = tilemap->GetMapSize();
	vector<vector<bool>> visited(mapSize.y, vector<bool>(mapSize.x, false));
	vector<vector<float>> best(mapSize.y, vector<float>(mapSize.x, 999999));

	// parent[y][x] = pos (xy는 pos에 의해 발견된 곳)
	vector<vector<Vector2Int>> parent(mapSize.y, vector<Vector2Int>(mapSize.x, Vector2Int(-1, -1)));

	parent[startPos.y][startPos.x] = startPos;
	while (false == queue.empty())
	{
		PQNode current = queue.top();
		queue.pop();
		//방문했다 체크

		visited[current.Vertex.y][current.Vertex.x] = true;

		if (current.Vertex == endPos)
		{
			//갈수있다/없다.
			return true;
		}

		Vector2Int dir[4] =
		{
			Vector2Int(0, -1), //Up
			Vector2Int(1, 0), // Right
			Vector2Int(0, 1), //Down
			Vector2Int(-1, 0) //Left

		};

		int moveCost[4] =
		{
			1,
			1,
			1,
			1
		};
		for (int i = 0; i < 4; i++)
		{
			Vector2Int nextPos = current.Vertex + dir[i];
			// 다음지점이 갈 수 있는 지점이면,
			if (scene->CanGo(nextPos) && SubmarinePos != nextPos && visited[nextPos.y][nextPos.x] == 0)
			{
				// nextPos는 curren로부터 왔습니다.
				PQNode newNode;
				newNode.Vertex = nextPos;
				newNode.G = current.G + moveCost[i];
				newNode.Cost = newNode.G + (dest - nextPos).Length();
				
				if (newNode.Cost < best[nextPos.y][nextPos.x])
				{
					parent[nextPos.y][nextPos.x] = current.Vertex; // parent는 경로를 연결함.
					best[nextPos.y][nextPos.x] = newNode.Cost;
				}
				queue.push(newNode);
			}
		}
	}
	return false;
}

void InstallSubmarinePanel::LoadResource()
{
	auto a = Resource->GetTexture(L"T_Submarine");
	Resource->CreateSprite(L"S_Submarine_Default", a, 0, 0, 32, 32);
	Resource->CreateSprite(L"S_Submarine_Hover", a, 0, 32, 32, 32);
	Resource->CreateSprite(L"S_Submarine_Pressed", a, 0, 64, 32, 32);
	Resource->CreateSprite(L"S_Submarine_Disabled", a, 0, 96, 32, 32);
}