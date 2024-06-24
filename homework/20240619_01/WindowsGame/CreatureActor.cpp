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

	// XXX : <- 이슈 위험
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
	// 0부터 키를 누르고 있으면 점점 전체 속도가 증가함. 최대 1까지

	// Input에 따라서 이동속도벡터(velocity)를 제어한다
	// state가 최종 판단을 해준다
	// velocity가 0이면, Idle
	// 그렇지 않으면 Move 상태로 바꿔준다.
}

void CreatureActor::Release()
{
	Super::Release();
}

void CreatureActor::SetState(CreatureState state)
{
	//FSM 유한상태머신
	//if (_state == state) return; << 이거 있으면 움직이지 않는 이상 Creature가 안 보임 --

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
	// 만약에 방향이 바뀌면, setFlipbook을 해준다/

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
	// _destPos랑 비교해서 움직이게 끔
	// 현재 내 포지션이 _destPos와 다르면 내 dir 방향으로 계속 움직인다.

	if (HasRechedDest())
	{
		this->SetState(CreatureState::Idle);
		this->SetPos(_destPos);// 10픽셀 이하로 하면 포지션에서 어긋나니까 다시 조정
	}
	else
	{
		Vector2 dirVec = _destPos - this->GetPos();
		dirVec = dirVec.Normalize();
		_body.pos += dirVec * 250 * Time->GetDeltaTime();

		// 상하좌우에 따라 캐릭터 방향을 돌려줌.
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

		// 도트 제품 계산
		float dotValues[8];
		for (int i = 0; i < 8; i++) {
			dotValues[i] = dirVec.Dot(directions[i]);
		}

		// 최대 도트 제품 값 찾기
		int maxIndex = 0;
		float cos45 = cos(Deg2Rad(45));
		for (int i = 0; i < 8; i++) {
			if (cos45 < dotValues[i]) {
				maxIndex = i;
			}
		}

		// 방향 전환
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
	//_destPos를 정확하게 짚어줄 것
	// 현재 맵에 있는 Tilemap을 불러와서 해당 셀에 있는 
	// _destPos = Tile 좌표를 가져온다.

	TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);

	if (scene == nullptr)
	{
		return;
	}
	// 이론상 씬에 타일맵이 있기에 값을 가져올 수 있어야 함.
	// 특정 클래스나 Actor에서 씬에 있거나 어딘가에 있는 무언가를 들고와야하는 상황이 되게 자주 발생
	// 그때 못 가져오면 개발이 불가능.
	Vector2 destPos = scene->GetTilemapPos(cellPos);
	_destPos = destPos;

	// 자연스럽게 이동해서 저 포지션으로 갈것인지, 순간이동 시켜서 1프레임만(즉시)에 이동시킬 것이냐.
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
	//_destPos와 내 위치의 길이 < 10px보다 작다.
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

	// _path[0] 지점으로 텔레포트
	if (0 < _path.size())
	{
		//this->SetCellPos(_path[0], true);
	}
}