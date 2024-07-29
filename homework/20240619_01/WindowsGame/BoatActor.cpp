#include "pch.h"
#include "BoatActor.h"
#include "CircleCollider.h"
#include "TowerDefenseScene.h"
#include "SpriteActor.h"
#include "Sprite.h"
#include "Flipbook.h"
#include "Texture.h"
#include "BulletActor.h"
#include "BulletActorController.h"
#include "GameWave.h"

void BoatActor::Init()
{	
	this->SetState(_state);
	this->SetName("Enemy");
	_collider = new CircleCollider();
	_collider->SetCollision(Vector2::Zero(), 10);
	_collider->Init(); 
	_collider->SetCollisionLayer(CollisionLayerType::CLT_ENEMY); // �ٽ� ����
	_collider->ResetCollisionFlag();
	_collider->AddCollisionFlagLayer(CollisionLayerType::CLT_BEHICLE);
	_collider->AddCollisionFlagLayer(CollisionLayerType::CLT_ITEM);
	this->AddComponent(_collider);

	// HP
	_hpBackground = Resource->GetSprite(L"S_HP_Background"); // HP ü�¹� ���
	_bpBar = Resource->GetSprite(L"S_HP_Bar"); // HP ü�¹�

	// Bomb
	_bomb = Resource->GetFlipbook(L"FB_Bomb"); // bomb
	
	{
		TowerDefenseScene* towerDefenseScene = static_cast<TowerDefenseScene*>(CurrentScene);
		_bulletActorController = towerDefenseScene->GetBulletActorController();
	}

	Super::Init();
}
void BoatActor::Render(HDC hdc)
{
	Super::Render(hdc); // Enemy Render

	// ������� Sprite Render
	{//_hpBackground
		if (_hpBackground == nullptr) return;

		Vector2Int size = _hpBackground->GetSize();

		Vector2Int cameraPos = CurrentScene->GetCameraPos();
		Vector2Int ScreenSizeHalf = Vector2Int(WIN_SIZE_X / 2, WIN_SIZE_Y / 2);
		Vector2Int renderPos = Vector2Int(
			static_cast<int>(_body.pos.x - size.x / 2 - cameraPos.x + ScreenSizeHalf.x),
			static_cast<int>(_body.pos.y - 20 - size.y / 2 - cameraPos.y + ScreenSizeHalf.y)
		);
		::TransparentBlt(hdc,
			renderPos.x,
			renderPos.y,
			size.x,
			size.y,
			_hpBackground->GetDC(),
			_hpBackground->GetPos().x,
			_hpBackground->GetPos().y,
			size.x,
			size.y,
			_hpBackground->GetTransparent()//�����
		);
	}

	{//_bpBar
		Vector2Int size = _bpBar->GetSize();

		Vector2Int cameraPos = CurrentScene->GetCameraPos();
		Vector2Int ScreenSizeHalf = Vector2Int(WIN_SIZE_X / 2, WIN_SIZE_Y / 2);
		Vector2Int renderPos = Vector2Int(
			static_cast<int>(_body.pos.x - size.x / 2 - cameraPos.x + ScreenSizeHalf.x),
			static_cast<int>(_body.pos.y - 20 - size.y / 2 - cameraPos.y + ScreenSizeHalf.y)
		);
		::TransparentBlt(hdc,
			renderPos.x,
			renderPos.y,
			size.x * (_hp / _staticHp),
			size.y,
			_bpBar->GetDC(),
			_bpBar->GetPos().x,
			_bpBar->GetPos().y,
			size.x,
			size.y,
			_bpBar->GetTransparent()//�����
		);
	}

	if(_die == true)
	{
		const FlipbookInfo& info = _bomb->GetInfo();
		Vector2Int cameraPos = CurrentScene->GetCameraPos();
		Vector2Int ScreenSizeHalf = Vector2Int(WIN_SIZE_X / 2, WIN_SIZE_Y / 2);
		Vector2Int renderPos = Vector2Int(
			static_cast<int>(_body.pos.x - info.size.x / 2 - cameraPos.x + ScreenSizeHalf.x),
			static_cast<int>(_body.pos.y - info.size.y / 2 - cameraPos.y + ScreenSizeHalf.y)
		);
		::TransparentBlt(hdc,
			renderPos.x,
			renderPos.y,
			info.size.x,
			info.size.y,
			info.texture->GetDC(),
			_index * info.size.x, // index ���� 1, 2, 0�� �۵� ��.
			info.line * info.size.y,
			info.size.x,
			info.size.y,
			info.texture->GetTransparent()
		);
	}
}
void BoatActor::Update()
{
	Super::Update();
	if (0 < _hp)
	{
		UpdateHpImage(_nextHp);
	}

	// XXX : <- �̽� ����
	switch (_state)
	{
	case BoatState::Move:
		UpdateMove();
		break;
	case BoatState::Idle:
		UpdateIdle();
		break;
	case BoatState::Goal:
		FinishedBoatState();
		break;
	case BoatState::Die:
		DeathEffect();
		break;
	case BoatState::None:
		_time = 0.6f;
		break;
	default:
		break;
	}
}

void BoatActor::Release()
{
	Super::Release();
}

void BoatActor::SetActiveBoat()
{
	wstring direction[eDirection::END]
		= { L"Down", L"Left", L"Right", L"Up", L"DownNLeft", L"DownNRight", L"UpNLeft", L"UpNRight" };
	//cout << _data.Name << endl;
	wstring name = wstring().assign(_data.Name.begin(), _data.Name.end());
	for (int i = 0; i < eDirection::END; i++)
	{
		_moveFlipbook[i] = Resource->GetFlipbook(name + direction[i]);
	}
	_hp = _data.HP;
	_staticHp = _data.HP;
	_nextHp = _data.HP;
}
void BoatActor::ChangeDirection(eDirection dir)
{
	// ���࿡ ������ �ٲ��, setFlipbook�� ���ش�/

	if (_dir == dir) return;

	_dir = dir;
	this->SetFlipbook(_moveFlipbook[_dir]);
}

void BoatActor::FinishedBoatState()
{
	this->SetCellPos({ 54, 25 }, true);
	TowerDefenseScene* towerDefenseScene = static_cast<TowerDefenseScene*>(CurrentScene);
	towerDefenseScene->GetGameWave()->PushBoatActor(this);
	UserDatas->AddEnterEnemyCount();

	// state ����
	_state = BoatState::None;
}

void BoatActor::DeathEffect()
{
	_die = true;
	//_time -= Time->GetDeltaTime();
	if (_index == 0)
	{
		_die = false;
		this->SetCellPos({ 54, 25 }, true);
		TowerDefenseScene* towerDefenseScene = static_cast<TowerDefenseScene*>(CurrentScene);
		towerDefenseScene->GetGameWave()->PushBoatActor(this);
		UserDatas->MakeGold(_data.Gold);
		_state = BoatState::None;
	}
}

void BoatActor::UpdateHpImage(float nextHp)
{
	// ���ط� ������ ����ϱ�
	if (nextHp <= _hp) // hp �� tempHp�� ������ ���� �� ����
	{
		_hp = _hp + (nextHp - _hp) * 0.2f;
		if (0 <= _hp - nextHp && _hp - nextHp < 1) // ������ ������ �������� _hp = tempHp�Ѵ�.
		{
			_hp = nextHp;
		}
	}
	if (_hp <= 0)
	{
		_state = BoatState::Die;
	}
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

		if (scene->CanGo(cellPos))
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
		_body.pos += dirVec * _data.MoveSpeed * Time->GetDeltaTime();

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

void BoatActor::OnTriggerEnter(Collider* collider, Collider* other)
{
	Super::OnTriggerEnter(collider, other);

	if (other->GetOwner()->GetName() == "bullet")//bullet
	{
		BulletActor* behicleBullet = dynamic_cast<BulletActor*>(other->GetOwner());
		float getDamage = behicleBullet->GetBulletDamage();
		_nextHp = _hp - getDamage;
		behicleBullet->SetBulletState(BulletState::Done);
		_bulletActorController->PushBullet(behicleBullet);
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
	return (_destPos - this->GetPos()).Length() < 2.0f;
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