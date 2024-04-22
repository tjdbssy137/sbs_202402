#include "pch.h"
#include "BallActor.h"

#include "BoxCollider.h"
#include "InGameScene.h"
#include "BrickActor.h"

void BallActor::Init()
{
	Super::Init();

	this->SetName("Ball");

	Resource->LoadTexture(L"T_Ball", L"BrickGame/ball.bmp");//Ȯ���ڸ��� ���� ���� �� �ƴ�.
	Resource->CreateSprite(L"S_Ball", Resource->GetTexture(L"T_Ball"));

	this->SetSprite(Resource->GetSprite(L"S_Ball"));

	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 18, 18));
	this->AddComponent(collider);
	this->SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y - 70 - 26, 21, 21));

	_speed = 500;
}

void BallActor::Render(HDC hdc)
{
	Super::Render(hdc);

	//_body.Draw(hdc);
}

void BallActor::Update()
{
	Super::Update();

	Vector2 prevPos = _body.pos;
	this->Move();

	//Collision Check
	if (this->_body.pos.x <= 10)
	{
		this->_moveDir.x = -this->_moveDir.x;
		_body.pos = prevPos;
	}
	if (this->_body.pos.x >= WIN_SIZE_X - 10)
	{
		this->_moveDir.x = -this->_moveDir.x;
		_body.pos = prevPos;
	}
	if (this->_body.pos.y <= 10)
	{
		this->_moveDir.y = -this->_moveDir.y;
		_body.pos = prevPos;
	}
	if (this->_body.pos.y >= WIN_SIZE_Y - 10)
	{
		//���ӿ���
		InGameScene* currentScene = dynamic_cast<InGameScene*>(GET_SINGLE(SceneManager)->GetCurrentScene());
		if (currentScene != nullptr)
		{
			currentScene->ChangeGameState(GameState::Wait);
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

	BrickActor* brick = new BrickActor();
	
	if (other->GetOwner()->GetName() == "Paddle")
	{	
		//�浹����üũ
		RECT myRect = static_cast<BoxCollider*>(collider)->GetCollision().ToRect();

		myRect.left -= 1;
		myRect.top -= 1;
		myRect.right += 1;
		myRect.bottom += 1;

		RECT otherRect = static_cast<BoxCollider*>(other)->GetCollision().ToRect();

		Bounce(myRect, otherRect);
		
	}
	if (other->GetOwner()->GetName() == "Brick")
	{
		RECT myRect = static_cast<BoxCollider*>(collider)->GetCollision().ToRect();

		myRect.left -= 1;
		myRect.top -= 1;
		myRect.right += 1;
		myRect.bottom += 1;

		RECT otherRect = static_cast<BoxCollider*>(other)->GetCollision().ToRect();

		Bounce(myRect, otherRect);

		BrickActor* brickActor = dynamic_cast<BrickActor*>(other->GetOwner());
		if (brickActor == nullptr)
		{
			cout << "error" << endl;
			return;
		}
		brickActor->SetEnable(false);

		// �Լ��� ����ϴ� ����
		// - 1. ������
		// - 2. �ڵ� ��Ȱ��(��������)
	}
}

void BallActor::Bounce(RECT myCollision, RECT otherCollision)
{
	RECT temp = {};

	if (IntersectRect(&temp, &myCollision, &otherCollision))
	{
		int width = temp.right - temp.left;
		int height = temp.bottom - temp.top;
		if (width < height)
		{
			//�����ʿ��� �������� �浹�Ǿ���.
			if (temp.left == myCollision.left)
			{
				_moveDir.x = -_moveDir.x;
				_body.pos.x += temp.right - temp.left;
			}

			//���ʿ��� ���������� �浹�Ǿ���.
			if (temp.right == myCollision.right)
			{
				_moveDir.x = -_moveDir.x;
				_body.pos.x -= temp.right - temp.left;
			}
		}
		else
		{
			//�Ʒ����� ���� �浹�Ǿ���.
			if (temp.top == myCollision.top)
			{
				_moveDir.y = -_moveDir.y;
				_body.pos.y += temp.bottom - temp.top;
			}


			//������ �Ʒ��� �浹�Ǿ���.
			if (temp.bottom == myCollision.bottom)
			{
				_moveDir.y = -_moveDir.y;
				_body.pos.y -= temp.bottom - temp.top;
			}
		}
	}
}