#include "pch.h"
#include "BallActor.h"

#include "BoxCollider.h"
#include "InGameScene.h"
#include "BrickActor.h"

void BallActor::Init()
{
	Super::Init();

	this->SetName("Ball");

	Resource->LoadTexture(L"T_Ball", L"BrickGame/ball.bmp");//확장자명은 내가 쓰는 거 아님.
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

	BrickActor* brick = new BrickActor();
	
	if (other->GetOwner()->GetName() == "Paddle")
	{	
		//충돌로직체크
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

		// 함수를 사용하는 이유
		// - 1. 가독성
		// - 2. 코드 재활용(유지보수)
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
			//오른쪽에서 왼쪽으로 충돌되었다.
			if (temp.left == myCollision.left)
			{
				_moveDir.x = -_moveDir.x;
				_body.pos.x += temp.right - temp.left;
			}

			//왼쪽에서 오른쪽으로 충돌되었다.
			if (temp.right == myCollision.right)
			{
				_moveDir.x = -_moveDir.x;
				_body.pos.x -= temp.right - temp.left;
			}
		}
		else
		{
			//아래에서 위로 충돌되었다.
			if (temp.top == myCollision.top)
			{
				_moveDir.y = -_moveDir.y;
				_body.pos.y += temp.bottom - temp.top;
			}


			//위에서 아래로 충돌되었다.
			if (temp.bottom == myCollision.bottom)
			{
				_moveDir.y = -_moveDir.y;
				_body.pos.y -= temp.bottom - temp.top;
			}
		}
	}
}