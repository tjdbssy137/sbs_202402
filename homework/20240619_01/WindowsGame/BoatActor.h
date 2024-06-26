#include "FlipbookActor.h"
#include "ITilemapActor.h"
class BoxCollider;
class Flipbook;

enum eBoatDirection
{
	DOWN,
	LEFT,
	RIGHT,
	UP,
	DOWN_LEFT,
	DOWN_RIGHT,
	UP_LEFT,
	UP_RIGHT,
	END
};

enum class BoatState
{
	Move,
	Idle
};

class BoatActor : public FlipbookActor, public ITilemapActor
{
public:
	using Super = FlipbookActor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public: // 상속받은 인터페이스의 함수를 만들지 않으면 오류가 남.
	virtual void SetCellPos(Vector2Int cellPos, bool teleport = false) override;
	virtual Vector2Int GetCellPos() override;

public:
	void SetState(BoatState state);
	BoatState GetState() { return _state; }

	void ChangeDirection(eBoatDirection dir);

	void SetDestPos(Vector2 destPos) { _destPos = destPos; }
	Vector2 GetDestPos() { return _destPos; }

public:
	bool HasRechedDest();
	bool CanMove();
public:
	void SetBoatSpeed(int boatSpeed) { _boatSpeed = boatSpeed; }
	int GetBoatSpeed() { return _boatSpeed; }

	void SetBoatType(wstring boatType) { _boatType = boatType; }
	wstring GetBoatType() { return _boatType; }

public: // Astar 관련
	void SetPath(vector<Vector2Int> path);


public:
	void UpdateMove();
	void UpdateIdle();

private:
	BoatState _state = BoatState::Move;
	eBoatDirection _dir = eBoatDirection::DOWN;
	Flipbook* _moveFlipbook[eBoatDirection::END] = {};

	BoxCollider* collider = nullptr;

private: // scene 에서 정리
	int _boatSpeed = 100;
	wstring _boatType = L"FB_EnemyBoat1_";

private:
	Vector2 _destPos = {};
	Vector2Int _cellPos = {};
private:// Astar 관련
	vector<Vector2Int> _path = {};
	int _pathIndex = 0;
};