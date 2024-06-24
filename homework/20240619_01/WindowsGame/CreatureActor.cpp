#include "pch.h"
#include "CreatureActor.h"
#include "BoxCollider.h"
#include "Dev2Scene.h"

void CreatureActor::Init()
{
	Super::Init();
	// IDLE
	wstring direction[eCreatureDirection::END] 
		= { L"Down", L"Left", L"Right", L"Up", L"DownNLeft", L"DownNRight", L"UpNLeft", L"UpNRight" };
	for (int i = 0; i < eCreatureDirection::END; i++)
	{
		_moveFlipbook[i] = Resource->GetFlipbook(L"FB_EnemyBoat1_" + direction[i]);
	}

	//cout << "_state : " << static_cast<int>(this->GetState()) << endl;
	this->SetState(_state);
}
void CreatureActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void CreatureActor::Update()
{
	Super::Update();

	// XXX : <- �̽� ����
	switch (_state)
	{
	case CreatureState::Move:
		UpdateMove();
		break;
	case CreatureState::Idle:
		UpdateIdle();
		break;
	default:
		break;
	}

	// _velocity
	// 0���� Ű�� ������ ������ ���� ��ü �ӵ��� ������. �ִ� 1����

	// Input�� ���� �̵��ӵ�����(velocity)�� �����Ѵ�
	// state�� ���� �Ǵ��� ���ش�
	// velocity�� 0�̸�, Idle
	// �׷��� ������ Move ���·� �ٲ��ش�.
}

void CreatureActor::Release()
{
	Super::Release();
}

void CreatureActor::SetState(CreatureState state)
{
	//FSM ���ѻ��¸ӽ�
	//if (_state == state) return; << �̰� ������ �������� �ʴ� �̻� Creature�� �� ���� --

	_state = state;

	switch (_state)
	{
	case CreatureState::Move:
		this->SetFlipbook(_moveFlipbook[_dir]);
	case CreatureState::Idle:
		this->SetFlipbook(_moveFlipbook[_dir]);
		break;
	default:
		break;
	}
}

void CreatureActor::ChangeDirection(eCreatureDirection dir)
{
	// ���࿡ ������ �ٲ��, setFlipbook�� ���ش�/

	if (_dir == dir) return;

	_dir = dir;
	switch (_state)
	{
	case CreatureState::Move:
		this->SetFlipbook(_moveFlipbook[_dir]);
		break;
	}
}

void CreatureActor::UpdateIdle()
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
			this->SetState(CreatureState::Move);
		}
	}
}

void CreatureActor::UpdateMove()
{
	// _destPos�� ���ؼ� �����̰� ��
	// ���� �� �������� _destPos�� �ٸ��� �� dir �������� ��� �����δ�.

	if (HasRechedDest())
	{
		this->SetState(CreatureState::Idle);
		this->SetPos(_destPos);// 10�ȼ� ���Ϸ� �ϸ� �����ǿ��� ��߳��ϱ� �ٽ� ����
	}
	else
	{
		Vector2 dirVec = _destPos - this->GetPos();
		dirVec = dirVec.Normalize();
		_body.pos += dirVec * 250 * Time->GetDeltaTime();

		// �����¿쿡 ���� ĳ���� ������ ������.
		Vector2 directions[8] = {
			Vector2::Up(),            // UP
			Vector2::Right(),         // RIGHT
			Vector2::Down(),          // DOWN
			Vector2::Left(),          // LEFT
			Vector2::UpNLeft(), // UP_RIGHT
			Vector2::UpNRight(), // DOWN_RIGHT
			Vector2::DownNLeft(), // DOWN_LEFT
			Vector2::DownNRight()  // UP_LEFT
		};

		// ��Ʈ ��ǰ ���
		float dotValues[8];
		for (int i = 0; i < 8; i++) {
			dotValues[i] = dirVec.Dot(directions[i]);
		}

		// �ִ� ��Ʈ ��ǰ �� ã��
		int maxIndex = 0;
		float cos45 = cos(Deg2Rad(45));
		for (int i = 0; i < 8; i++) {
			if (cos45 < dotValues[i]) {
				maxIndex = i;
			}
		}

		// ���� ��ȯ
		switch (maxIndex) {
		case 0:
			this->ChangeDirection(eCreatureDirection::UP);
			break;
		case 1:
			this->ChangeDirection(eCreatureDirection::RIGHT);
			break;
		case 2:
			this->ChangeDirection(eCreatureDirection::DOWN);
			break;
		case 3:
			this->ChangeDirection(eCreatureDirection::LEFT);
			break;
		case 4:
			this->ChangeDirection(eCreatureDirection::UP_LEFT);
			break;
		case 5:
			this->ChangeDirection(eCreatureDirection::UP_RIGHT);
			break;
		case 6:
			this->ChangeDirection(eCreatureDirection::DOWN_LEFT);
			break;
		case 7:
			this->ChangeDirection(eCreatureDirection::DOWN_RIGHT);
			break;
		}
	}
}

void CreatureActor::SetCellPos(Vector2Int cellPos, bool teleport)
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
Vector2Int CreatureActor::GetCellPos()
{
	return _cellPos;
}
bool CreatureActor::HasRechedDest()
{
	//_destPos�� �� ��ġ�� ���� < 10px���� �۴�.
	return (_destPos - this->GetPos()).Length() < 10.0f;
}

bool CreatureActor::CanMove()
{
	if (this->_state == CreatureState::Move)
	{
		return false;
	}

	return true;
}

void CreatureActor::SetPath(vector<Vector2Int> path)
{
	_path = path;
	_pathIndex = 0;

	// _path[0] �������� �ڷ���Ʈ
	if (0 < _path.size())
	{
		//this->SetCellPos(_path[0], true);
	}
}