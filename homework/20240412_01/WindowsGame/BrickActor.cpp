#include "pch.h"
#include "BrickActor.h"

#include "BoxCollider.h"
void BrickActor::Init()
{
	Super::Init();
	this->SetName("Brick");
	this->SetBody(Shape::MakeCenterRect(0, 0, 100, 40));

	int a = 0, b = 1;
	for (int i = 0; i < COUNT; i++)
	{
		_bricks[i] = Shape::MakeCenterRect(0, 0, 100, 40);
		_bricks[i].pos.x += 100 * a + 100;
		_bricks[i].pos.y += 40 * b;
		a++;

		BoxCollider* collider = new BoxCollider();
		collider->SetCollision(Shape::MakeCenterRect(0, 0, 100, 40));
		this->AddComponent(collider);

		if ((i + 1) % 12 == 0)
		{
			a = 0;
			b++;
		}
	}

	for (int i = 0; i < COUNT; i++)
	{
		_isDestroy[i] = true;
	}
}
void BrickActor::Render(HDC hdc)
{
	Super::Render(hdc);

	for (int i = 0; i < COUNT; i++)
	{
		if (_isDestroy[i] == true)
		{
			_bricks[i].Draw(hdc);
		}
	}
}
void BrickActor::Update()
{
	Super::Update();

}
void BrickActor::Release()
{
	Super::Release();
}