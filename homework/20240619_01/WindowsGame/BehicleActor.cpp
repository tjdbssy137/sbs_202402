#include "pch.h"
#include "BehicleActor.h"
#include "Dev2Scene.h"

void BehicleActor::Init()
{
	Super::Init();

	wstring direction[eDirection::END]
		= { L"Down", L"Left", L"Right", L"Up", L"DownNLeft", L"DownNRight", L"UpNLeft", L"UpNRight" };
	for (int i = 0; i < eDirection::END; i++)
	{
		_idleFlipbook[i] = Resource->GetFlipbook(GetBehicleType() + direction[i]);
	}

	this->SetState(_state);
}
void BehicleActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void BehicleActor::Update()
{
	Super::Update();

	// XXX : <- 이슈 위험
	switch (_state)
	{
	case BehicleState::Attack:
		UpdateAttack();
		break;
	case BehicleState::Idle:
		UpdateIdle();
		break;
	default:
		break;
	}
}

void BehicleActor::Release()
{
	Super::Release();
}

void BehicleActor::SetState(BehicleState state)
{
	//FSM 유한상태머신

	_state = state;

	this->SetFlipbook(_idleFlipbook[_dir]);
}

void BehicleActor::ChangeDirection(eDirection dir)
{
	// 만약에 방향이 바뀌면, setFlipbook을 해준다/

	if (_dir == dir) return;

	_dir = dir;
	this->SetFlipbook(_idleFlipbook[_dir]);
}

void BehicleActor::UpdateIdle()
{
	
}

void BehicleActor::UpdateAttack()
{
	Vector2 dirVec = _targetPos - this->GetPos();
	dirVec = dirVec.Normalize();
	

}

void BehicleActor::LookAtTarget() // target을 바라보기
{
	// target은 가장 가까운 거리에 있는 애 바라보는 걸로.
	// 적들을 다 받아와서 적들과의 거리를 계산?
	// 콜라이더 사용?
	Vector2 dirVec = _targetPos - this->GetPos();
	dirVec = dirVec.Normalize();
	
	Vector2 directions[eDirection::END] =
	{
		Vector2::Up(),				// UP
		Vector2::Right(),			// RIGHT
		Vector2::Down(),			// DOWN
		Vector2::Left(),			// LEFT
		Vector2::UpNLeft(),			// UP_RIGHT
		Vector2::UpNRight(),		// DOWN_RIGHT
		Vector2::DownNLeft(),		// DOWN_LEFT
		Vector2::DownNRight()		// UP_LEFT
	};

	float dotValues[eDirection::END];
	for (int i = 0; i < eDirection::END; i++) {
		dotValues[i] = dirVec.Dot(directions[i]);
	}

	// 최대 값 찾기
	int targetDir = 0;
	float cos45 = cos(Deg2Rad(45));
	for (int i = 0; i < eDirection::END; i++) {
		if (cos45 < dotValues[i]) {
			targetDir = i;
		}
	}

	switch (targetDir) {
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
	case 4:
		this->ChangeDirection(eDirection::UP_LEFT);
		break;
	case 5:
		this->ChangeDirection(eDirection::UP_RIGHT);
		break;
	case 6:
		this->ChangeDirection(eDirection::DOWN_LEFT);
		break;
	case 7:
		this->ChangeDirection(eDirection::DOWN_RIGHT);
		break;
	}
}
void BehicleActor::SetCellPos(Vector2Int cellPos, bool teleport)
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
Vector2Int BehicleActor::GetCellPos()
{
	return _cellPos;
}