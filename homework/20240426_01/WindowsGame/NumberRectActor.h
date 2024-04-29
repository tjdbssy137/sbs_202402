#pragma once
#include "SpriteActor.h"
enum class NumberState
{
	Number2,
	Number4,
	Number8,
	Number16,
	Number32,
	Number64,
	Number128,
	Number256,
	Number512,
	Number1024,
	Number2048,

	None
};

enum class MoveDirectionState
{
	Down,
	Up,
	Left,
	Right,

	None
};
class NumberRectActor : public SpriteActor
{
public:
	using Super = SpriteActor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void SlideActor();
	void ChangeImage(int sum);
	void ChangeDirectionState(MoveDirectionState directionState);

	int GetValue() { return _myValue; }
	void SetValue(int value) { _myValue = value; }

private:
	NumberState _state = NumberState::None;
	MoveDirectionState _directionState = MoveDirectionState::None;
	int _myValue = 2;
	Vector2 _direcion = Vector2::Zero();
	float _speed = 0;
};

