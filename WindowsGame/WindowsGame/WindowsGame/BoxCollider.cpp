#include "pch.h"
#include "BoxCollider.h"
#include "Actor.h"
void BoxCollider::Init()
{
	Super::Init();
}
void BoxCollider::Render(HDC hdc)
{
	Super::Render(hdc);

	//fill ����ȭ
	HBRUSH emptyBrush = GetStockBrush(NULL_BRUSH);
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, emptyBrush);//������ ���� �귯�� ����

	//collider�� �� �پ��ִ��� �׷���
	this->GetCollision().Draw(hdc); // ���⿡�� window������ �������. flipbookactor���� ó��!
	SelectObject(hdc, oldBrush);//�׸��� �׸��� ���� �귯�� ���� �ѹ�
	DeleteObject(emptyBrush);

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
	switch (other->GetColliderType())
	{
	case ColliderType::Circle:
		return false;
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

//�ڽĿ��� �θ� ������ ��� ����
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