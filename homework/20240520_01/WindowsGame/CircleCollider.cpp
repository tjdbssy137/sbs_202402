#include "pch.h"
#include "CircleCollider.h"
#include "Actor.h"
#include "BoxCollider.h"
#include "Scene.h"
CircleCollider::CircleCollider() : Collider(ColliderType::Circle)
{
	_pos = {};
	_radius = 0;
}

CircleCollider::~CircleCollider()
{
}

Vector2 CircleCollider::GetCollisionPos()
{
	Vector2 pos;
	pos.x = this->_pos.x + this->_owner->GetBody().pos.x;
	pos.y = this->_pos.y + this->_owner->GetBody().pos.y;

	return pos;
}

void CircleCollider::Init()
{
	Super::Init();
}
void CircleCollider::Render(HDC hdc)
{
	Super::Render(hdc);

	HBRUSH emptyBrush = GetStockBrush(NULL_BRUSH);
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, emptyBrush);

	Vector2Int cameraPos = CurrentScene->GetCameraPos();
	Vector2Int ScreenSizeHalf = Vector2Int(WIN_SIZE_X / 2, WIN_SIZE_Y / 2);

	Vector2 pos = this->GetCollisionPos();
	Ellipse(hdc, pos.x  - _radius - cameraPos.x + ScreenSizeHalf.x,
		pos.y  - _radius - cameraPos.y + ScreenSizeHalf.y,
		pos.x  + _radius - cameraPos.x + ScreenSizeHalf.x,
		pos.y  + _radius - cameraPos.y + ScreenSizeHalf.y);

	SelectObject(hdc, oldBrush);
	DeleteObject(emptyBrush);
}
void CircleCollider::Update()
{
	Super::Update();
}
void CircleCollider::Release()
{
	Super::Release();
}

bool CircleCollider::CheckCollision(Collider* other)
{
	switch (other->GetColliderType())
	{
	case ColliderType::Circle:
	{
		CircleCollider* otherCollider = static_cast<CircleCollider*>(other);
		Vector2 circlePos1 = this->GetCollisionPos();
		float circleRadius1 = this->GetRadius();

		Vector2 circlePos2 = otherCollider->GetCollisionPos();
		float circleRadius2 = otherCollider->GetRadius();
		return Collision::CircleInCircle(circlePos1, circleRadius1, circlePos2, circleRadius2);
	}
	break;
	case ColliderType::Box:
	{
		BoxCollider* otherCollider = static_cast<BoxCollider*>(other);
		Vector2 circlePos = this->GetCollisionPos();
		float circleRadius = this->GetRadius();
		return Collision::RectInCircle(otherCollider->GetCollision(), circlePos, circleRadius);
	}
	break;
	default:
		return false;
		break;
	}

	return false;
}