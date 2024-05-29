#pragma once
#include "Collider.h"
class CircleCollider : public Collider
{
public:
	using Super = Collider;
private:
	Vector2 _pos;
	float _radius;

public:
	Vector2 GetCollisionPos();
	float GetRadius() { return _radius; }
	void SetCollision(Vector2 pos, float radius) { _pos = pos; _radius = radius; }

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	virtual bool CheckCollision(Collider* other);

public:
	CircleCollider();
	virtual ~CircleCollider();
};


