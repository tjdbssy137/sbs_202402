#pragma once
#include "Collider.h"
class BoxCollider : public Collider
{
public:
	using Super = Collider;
private:
	CenterRect _collision;

public:
	CenterRect GetCollision();
	void SetCollision(CenterRect collision) { _collision = collision; }

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	virtual bool CheckCollision(Collider* other);

public:
	BoxCollider();
	virtual ~BoxCollider();
};

