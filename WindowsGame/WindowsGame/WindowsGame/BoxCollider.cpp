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

	//fill 투명화
	HBRUSH emptyBrush = GetStockBrush(NULL_BRUSH);
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, emptyBrush);//이전에 쓰던 브러쉬 정보

	Vector2 cameraPos = CurrentScene->GetCameraPos();
	Vector2 ScreenSizeHalf = Vector2(WIN_SIZE_X / 2, WIN_SIZE_Y / 2);
	Vector2 renderPos = Vector2(
		static_cast<int>(this->GetCollision().pos.x - GetOwner()->GetBody().pos.x / 2 - cameraPos.x + ScreenSizeHalf.x),
		static_cast<int>(this->GetCollision().pos.y - GetOwner()->GetBody().pos.y /2 - cameraPos.y + ScreenSizeHalf.y)
		//- (this->_owner->GetPos().y / 2) - cameraPos.y + ScreenSizeHalf.y
	);

	CenterRect tempColliderBox = CenterRect(renderPos, this->GetCollision().width, this->GetCollision().height);

	tempColliderBox.Draw(hdc);
	//collider가 잘 붙어있는지 그려줌
	//this->GetCollision().Draw(hdc); // 여기에서 window사이즈 빼줘야함. flipbookactor에서 처럼!
	SelectObject(hdc, oldBrush);//그림을 그리고 나면 브러쉬 정보 롤백
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

//자식에서 부모 생성자 사용 가능
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