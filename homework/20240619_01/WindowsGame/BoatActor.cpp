#include "pch.h"
#include "BoatActor.h"
#include "CircleCollider.h"
#include "Dev2Scene.h"

void BoatActor::Init()
{
	Super::Init();
	//wprintf(GetBoatType().c_str());
	wstring direction[eDirection::END]
		= { L"Down", L"Left", L"Right", L"Up", L"DownNLeft", L"DownNRight", L"UpNLeft", L"UpNRight" };
	for (int i = 0; i < eDirection::END; i++)
	{
		_moveFlipbook[i] = Resource->GetFlipbook(GetBoatType() + direction[i]);
	}

	this->SetState(_state);

	collider = new CircleCollider();
	collider->SetCollision(Vector2::Zero(), 10);
	this->AddComponent(collider);
}
void BoatActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void BoatActor::Update()
{
	Super::Update();

	// XXX : <- �̽� ����
	switch (_state)
	{
	case BoatState::Move:
		UpdateMove();
		break;
	case BoatState::Idle:
		UpdateIdle();
		break;
	default:
		break;
	}
}

void BoatActor::Release()
{
	Super::Release();
}

void BoatActor::SetState(BoatState state)
{
	//FSM ���ѻ��¸ӽ�

	_state = state;

	this->SetFlipbook(_moveFlipbook[_dir]);
}

void BoatActor::ChangeDirection(eDirection dir)
{
	// ���࿡ ������ �ٲ��, setFlipbook�� ���ش�/

	if (_dir == dir) return;

	_dir = dir;
	this->SetFlipbook(_moveFlipbook[_dir]);
}

void BoatActor::UpdateIdle()
{
	if (_pathIndex != _path.size())
	{
		Vector2Int cellPos = _path[_pathIndex++];

		TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);
		assert(scene != nullptr);
		if (scene == nullptr)
		{
			return;
		}

		if (scene->CanGo(this, cellPos))
		{
			this->SetCellPos(cellPos);
			this->SetState(BoatState::Move);
		}
	}
}

void BoatActor::UpdateMove()
{
	// _destPos�� ���ؼ� �����̰� ��
	// ���� �� �������� _destPos�� �ٸ��� �� dir �������� ��� �����δ�.

	if (HasRechedDest())
	{
		this->SetState(BoatState::Idle);
		this->SetPos(_destPos);// 10�ȼ� ���Ϸ� �ϸ� �����ǿ��� ��߳��ϱ� �ٽ� ����
	}
	else
	{
		Vector2 dirVec = _destPos - this->GetPos();
		dirVec = dirVec.Normalize();
		_body.pos += dirVec * _boatSpeed * Time->GetDeltaTime();

		// �����¿쿡 ���� ĳ���� ������ ������.
		Vector2 directions[4] = {
			Vector2::Up(),            // UP
			Vector2::Right(),         // RIGHT
			Vector2::Down(),          // DOWN
			Vector2::Left()          // LEFT
		};

		float dotValues[4];
		for (int i = 0; i < 4; i++) {
			dotValues[i] = dirVec.Dot(directions[i]);
		}

		// �ִ� �� ã��
		int maxIndex = 0;
		float cos45 = cos(Deg2Rad(45));
		for (int i = 0; i < 4; i++) {
			if (cos45 < dotValues[i]) {
				maxIndex = i;
			}
		}

		// ���� ��ȯ
		switch (maxIndex) {
		case 0:
			this->ChangeDirection(eDirection::UP);
			break;
		case 1:
			this->ChangeDirection(eDirection::RIGHT);
			break;
		case 2:
			this->ChangeDirection(eDirection::DOWN);
			break;
		case 3:
			this->ChangeDirection(eDirection::LEFT);
			break;
		default:
			break;
		}
	}
}

void BoatActor::SetCellPos(Vector2Int cellPos, bool teleport)
{
	_cellPos = cellPos;
	//_destPos�� ��Ȯ�ϰ� ¤���� ��
	// ���� �ʿ� �ִ� Tilemap�� �ҷ��ͼ� �ش� ���� �ִ� 
	// _destPos = Tile ��ǥ�� �����´�.

	TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);

	if (scene == nullptr)
	{
		return;
	}
	// �̷л� ���� Ÿ�ϸ��� �ֱ⿡ ���� ������ �� �־�� ��.
	// Ư�� Ŭ������ Actor���� ���� �ְų� ��򰡿� �ִ� ���𰡸� ���;��ϴ� ��Ȳ�� �ǰ� ���� �߻�
	// �׶� �� �������� ������ �Ұ���.
	Vector2 destPos = scene->GetTilemapPos(cellPos);
	_destPos = destPos;

	// �ڿ������� �̵��ؼ� �� ���������� ��������, �����̵� ���Ѽ� 1�����Ӹ�(���)�� �̵���ų ���̳�.
	if (teleport)
	{
		this->SetPos(_destPos);
	}
}
Vector2Int BoatActor::GetCellPos()
{
	return _cellPos;
}
bool BoatActor::HasRechedDest()
{
	//_destPos�� �� ��ġ�� ���� < 10px���� �۴�.
	return (_destPos - this->GetPos()).Length() < 10.0f;
}

bool BoatActor::CanMove()
{
	if (this->_state == BoatState::Move)
	{
		return false;
	}

	return true;
}

void BoatActor::SetPath(vector<Vector2Int> path)
{
	_path = path;
	_pathIndex = 0;
}