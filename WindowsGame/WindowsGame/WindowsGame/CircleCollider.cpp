#include "pch.h"
#include "CircleCollider.h"
#include "Actor.h"
#include "BoxCollider.h"

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

float CircleCollider::GetRadius()
{

}

void CircleCollider::Init()
{
	Super::Init();
}
void CircleCollider::Render(HDC hdc)
{
	Super::Render(hdc);

	//fill 투명화
	HBRUSH emptyBrush = GetStockBrush(NULL_BRUSH);
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, emptyBrush);//이전에 쓰던 브러쉬 정보

	Vector2 pos = this->GetCollisionPos();
	Ellipse
	//collider가 잘 붙어있는지 그려줌
	this->GetCollision().Draw(hdc); // 여기에서 window사이즈 빼줘야함. flipbookactor에서 처럼!
	SelectObject(hdc, oldBrush);//그림을 그리고 나면 브러쉬 정보 롤백
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
