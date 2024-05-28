#include "pch.h"
#include "BoxCollider.h"
#include "Actor.h"
#include "Scene.h"
#include "CircleCollider.h"
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
	//this->GetCollision().Draw(hdc); // ���⿡�� window������ �������. flipbookactor���� ó��!
	{
		Vector2 cameraPos = CurrentScene->GetCameraPos();
		Vector2 ScreenSizeHalf = Vector2(WIN_SIZE_X / 2, WIN_SIZE_Y / 2);
		CenterRect renderRect = this->GetCollision();

		renderRect.pos.x = renderRect.pos.x - cameraPos.x + ScreenSizeHalf.x;
		renderRect.pos.y = renderRect.pos.y - cameraPos.y + ScreenSizeHalf.y;
		/*
		Vector2 renderPos = Vector2(
			static_cast<int>(this->GetOwner()->GetBody().pos.x + this->_collision.pos.x - cameraPos.x + ScreenSizeHalf.x),
			static_cast<int>(this->GetOwner()->GetBody().pos.y + this->_collision.pos.y - cameraPos.y + ScreenSizeHalf.y)

		);
		CenterRect resize = { renderPos, this->GetCollision().width, this->GetCollision().height };
		*/
		renderRect.Draw(hdc);
	}

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
	if (Super::CheckCollision(other) == false) return false;//�θ��� CheckCollision�� ���� CheckCollision�� �ص� �Ǵ� �� Ȯ��

	switch (other->GetColliderType())
	{
	case ColliderType::Circle:
	{
		CircleCollider* otherCollider = static_cast<CircleCollider*>(other);
		Vector2 otherCirclePos = otherCollider->GetCollisionPos();
		float otherCircleRadius = otherCollider->GetRadius();

		return Collision::RectInCircle(this->GetCollision(), otherCirclePos, otherCircleRadius);
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