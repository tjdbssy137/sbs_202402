#include "pch.h"
#include "BallActor.h"
#include "BoxCollider.h"
#include "InGameScene.h"
void BallActor::Init()
{
	Super::Init();
	this->SetName("Ball");

	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 30, 30));
	this->AddComponent(collider);
	this->SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y - 110, 30, 30));

	_speed = 500;
}
void BallActor::Render(HDC hdc)
{
	Super::Render(hdc);
	_body.Draw(hdc);
}
void BallActor::Update()
{
	Super::Update();
	
	Vector2 prevPos = _body.pos;
	
	this->Move();

	// Collision Check
	if (this->_body.pos.x <= 15)
	{
		this->_moveDir.x = -this->_moveDir.x;
		_body.pos = prevPos;
	}
	if (WIN_SIZE_X - 15 <= this->_body.pos.x)
	{
		this->_moveDir.x = -this->_moveDir.x;
		_body.pos = prevPos;
	}
	if (this->_body.pos.y <= 15)
	{
		this->_moveDir.y = -this->_moveDir.y;
		_body.pos = prevPos;
	}
	if (WIN_SIZE_Y - 15 <= this->_body.pos.y)
	{
		InGameScene* currentScene = dynamic_cast<InGameScene*>(GET_SINGLE(SceneManager)->GetCurrentScene());
		if (currentScene != nullptr)
		{
			s
		}
	}


}
void BallActor::Release()
{
	Super::Release();
}

void BallActor::Move()
{
	_body.pos += _moveDir * Time->GetDeltaTime() * _speed;
}

void BallActor::SetPos(Vector2 position)
{
	this->_body.pos = position;
}

void BallActor::OnTriggerEnter(Collider* collider, Collider* other)
{
	Super::OnTriggerEnter(collider, other);
	if (other->GetOwner()->GetName() == "Paddle")
	{
		//�浹���� üũ
		RECT myRect = static_cast<BoxCollider*>(collider)->GetCollision().ToRect();
		myRect.left -= 1;
		myRect.top -= 1;
		myRect.right += 1;
		myRect.bottom += 1;
		RECT otherRect = static_cast<BoxCollider*>(other)->GetCollision().ToRect();
		RECT temp = {};

		if (IntersectRect(&temp, &myRect, &otherRect))
		{

			int width = temp.right - temp.left;
			int height = temp.bottom - temp.top;

			if (width < height)
			{
				//�����ʿ��� ��������
				if (temp.left == myRect.left)
				{
					_moveDir.x = -_moveDir.x;
					_body.pos.x += temp.right - temp.left;
				}
				//���ʿ��� ����������
				if (temp.right == myRect.right)
				{
					_moveDir.x = -_moveDir.x;
					_body.pos.x -= temp.right - temp.left;
				}
			}
			else
			{
				//�Ʒ����� ����
				if (temp.top == myRect.top)
				{
					//�׷��Ͼ�
					_moveDir.y = -_moveDir.y;
					_body.pos.y += temp.bottom - temp.top;
				}
				//������ �Ʒ���
				if (temp.bottom == myRect.bottom)
				{
					_moveDir.y = -_moveDir.y;
					_body.pos.y -= temp.bottom + temp.top;
				}
			}
		}
	}
}