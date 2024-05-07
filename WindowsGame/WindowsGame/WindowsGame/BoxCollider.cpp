#include "pch.h"
#include "BoxCollider.h"
#include "Actor.h"
#include "Scene.h"
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

	Vector2 cameraPos = CurrentScene->GetCameraPos();
	Vector2 ScreenSizeHalf = Vector2(WIN_SIZE_X / 2, WIN_SIZE_Y / 2);
	Vector2 renderPos = Vector2(
		static_cast<int>(this->GetCollision().pos.x - GetOwner()->GetBody().pos.x / 2 - cameraPos.x + ScreenSizeHalf.x),
		static_cast<int>(this->GetCollision().pos.y - GetOwner()->GetBody().pos.y /2 - cameraPos.y + ScreenSizeHalf.y)
		//- (this->_owner->GetPos().y / 2) - cameraPos.y + ScreenSizeHalf.y
	);

	CenterRect tempColliderBox = CenterRect(renderPos, this->GetCollision().width, this->GetCollision().height);

	tempColliderBox.Draw(hdc);
	//collider�� �� �پ��ִ��� �׷���
	//this->GetCollision().Draw(hdc); // ���⿡�� window������ �������. flipbookactor���� ó��!
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