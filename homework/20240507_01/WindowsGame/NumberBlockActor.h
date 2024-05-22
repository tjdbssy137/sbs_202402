#pragma once
#include "SpriteActor.h"

enum class NumberBlockDirState
{
	Down,
	Up,
	Left,
	Right,

	None
};
class NumberBlockActor : public SpriteActor
{
public:
	using Super = SpriteActor;
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
	//virtual void OnTriggerEnter(Collider* collider, Collider* other) override;
public:
	void ChangeImage(int sum);
	void ChangeDirectionState(NumberBlockDirState _directionState);
	void SlideActor();

	int GetNumber() { return _number; }
	void SetNumber(int number) { _number = number; }

	int GetMoveCount() { return _moveCount; }
	void AddMoveCount() { _moveCount++; }
	void SetMoveCount(int moveCount) { _moveCount = moveCount; }

private:
	int _number = 0;
	NumberBlockDirState _directionState = NumberBlockDirState::None;
	Vector2 _direction = Vector2::Zero();

	Vector2 _startPos = Vector2::Zero();
	float _sumTime = 0;
	float _speed = 10;

	int _moveCount = 0;
};

