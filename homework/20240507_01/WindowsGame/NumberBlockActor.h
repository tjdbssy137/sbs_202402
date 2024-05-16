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

private:
	int _number = 2;
	NumberBlockDirState _directionState = NumberBlockDirState::None;
	Vector2 _direction = Vector2::Zero();
	float _speed = 0;
};

