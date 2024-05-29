#include "pch.h"
#include "BallActor.h"

#include "BoxCollider.h"
#include "InGameScene.h"
#include "BrickActor.h"

void BallActor::Init()
{
	Super::Init();


	Resource->LoadTexture(L"T_ball", L"BrickGame/ball.bmp");
	Resource->CreateSprite(L"S_ball", Resource->GetTexture(L"T_ball"));


	this->SetSprite(Resource->GetSprite(L"S_ball"));

	this->SetName("Ball");

	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 18, 18));
	this->AddComponent(collider);
	this->SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y - 70 - 26, 23, 21));

	_speed = 500;
}

void BallActor::Render(HDC hdc)
{
	Super::Render(hdc);

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
		//게임오버
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


	if (other->GetOwner()->GetName() == "Paddle")
	{
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
		BrickActor* brickActor = dynamic_cast<BrickActor*>(other->GetOwner());

		if (brickActor == nullptr)
		{
			printf("[warning] is not BrickActor !\n");
			return;
		}

		brickActor->SetEnable(false);

		RECT myRect = static_cast<BoxCollider*>(collider)->GetCollision().ToRect();

		myRect.left -= 1;
		myRect.top -= 1;
		myRect.right += 1;
		myRect.bottom += 1;
		RECT otherRect = static_cast<BoxCollider*>(other)->GetCollision().ToRect();

		Bounce(myRect, otherRect);
	}
}


void BallActor::Bounce(RECT myRect, RECT otherRect)
{

	RECT temp = {};

	if (IntersectRect(&temp, &myRect, &otherRect))
	{

		int width = temp.right - temp.left;
		int height = temp.bottom - temp.top;
		if (width < height)
		{
			//오른쪽에서 왼쪽으로 충돌되었다.
			if (temp.left == myRect.left)
			{
				_moveDir.x = -_moveDir.x;
				_body.pos.x += temp.right - temp.left;
			}

			//왼쪽에서 오른쪽으로 충돌되었다.
			if (temp.right == myRect.right)
			{
				_moveDir.x = -_moveDir.x;
				_body.pos.x -= temp.right - temp.left;
			}
		}
		else
		{
			//아래에서 위로 충돌되었다.
			if (temp.top == myRect.top)
			{
				_moveDir.y = -_moveDir.y;
				_body.pos.y += temp.bottom - temp.top;
			}


			//위에서 아래로 충돌되었다.
			if (temp.bottom == myRect.bottom)
			{
				_moveDir.y = -_moveDir.y;
				_body.pos.y -= temp.bottom - temp.top;
			}
		}

	}
}