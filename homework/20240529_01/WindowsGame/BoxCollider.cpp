#include "pch.h"
#include "BoxCollider.h"
#include "Actor.h"
#include "CircleCollider.h"
#include "Scene.h"
void BoxCollider::Init()
{
	Super::Init();
}
void BoxCollider::Render(HDC hdc)
{
	Super::Render(hdc);

	HBRUSH emptyBrush = GetStockBrush(NULL_BRUSH);
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, emptyBrush);

	CenterRect renderRect = this->GetCollision();
	Vector2Int cameraPos = CurrentScene->GetCameraPos();
	Vector2Int screenSizeHalf = Vector2Int(WIN_SIZE_X / 2, WIN_SIZE_Y / 2);
	renderRect.pos.x = renderRect.pos.x - cameraPos.x + screenSizeHalf.x;
	renderRect.pos.y = renderRect.pos.y - cameraPos.y + screenSizeHalf.y;

	renderRect.Draw(hdc);
	SelectObject(hdc, oldBrush);
	DeleteObject(emptyBrush);

	//_collision.Draw(hdc);
}
void BoxCollider::Update()
{
	Super::Update();
}
void BoxCollider::Release()
{
	Super::Release();
}

bool BoxCollider::CheckCollision(Collider* other)
{
	if (Super::CheckCollision(other) == false) return false;

	switch (other->GetColliderType())
	{
	case ColliderType::Circle:
	{
		CircleCollider* otherCollider = static_cast<CircleCollider*>(other);
		Vector2 otherCollisionPos = otherCollider->GetCollisionPos();
		float otherCircleRadius = otherCollider->GetRadius();
		return Collision::RectInCircle(this->GetCollision(), otherCollisionPos, otherCircleRadius);
	}
		break;
	case ColliderType::Box:
	{
		BoxCollider* otherCollider = static_cast<BoxCollider*>(other);
		CenterRect otherCollision = otherCollider->GetCollision();
		return Collision::RectInRect(this->GetCollision().ToRect(), otherCollision.ToRect());
	}
		break;
	default:
		return false;
		break;
	}

	return false;
}

//자식에서 부모생성자 사용가능.
BoxCollider::BoxCollider() : Collider(ColliderType::Box)
{
	_collision = {};
}

BoxCollider::~BoxCollider()
{
}

CenterRect BoxCollider::GetCollision()
{
	CenterRect rect;
	rect.pos.x = this->_collision.pos.x + this->_owner->GetBody().pos.x;
	rect.pos.y = this->_collision.pos.y + this->_owner->GetBody().pos.y;
	rect.width = this->_collision.width;
	rect.height = this->_collision.height;

	return rect;
}