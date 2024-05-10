#pragma once
#include "SpriteActor.h"
class NumberBlockActor : public SpriteActor
{
public:
	using Super = SpriteActor;
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void ChangeImage(int sum);

	int GetNumber() { return _number; }
	void SetNumber() { _number *= 2; }
private:
	int _number = 0;

};

