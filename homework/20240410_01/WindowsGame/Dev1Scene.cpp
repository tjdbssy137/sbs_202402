#include "pch.h"
#include "Dev1Scene.h"
#include "PlayerActor.h"
#include "BoxCollider.h"
void Dev1Scene::Init()
{
	Super::Init();

	{
		PlayerActor* _ball = new PlayerActor();

		_ball->Init();
		_ball->SetName("Ball");
		BoxCollider* collider = new BoxCollider();
		collider->SetCollision(Shape::MakeCenterRect(0, 0, 30, 30));
		_ball->AddComponent(collider);
		_ball->SetBody(Shape::MakeCenterRect(550, 400, 30, 30));
		this->SpawnActor(_ball);
	}

	{
		PlayerActor* _player = new PlayerActor();

		_player->Init();
		// object의 이름 설정
		_player->SetName("Player");
		// collider 설정
		BoxCollider* collider = new BoxCollider();
		collider->SetCollision(Shape::MakeCenterRect(0, 0, 120, 20));
		_player->AddComponent(collider);
		// player object의 transform 설정
		_player->SetBody(Shape::MakeCenterRect(550, 500, 120, 20));
		// spawn
		this->SpawnActor(_player);
	}

}
void Dev1Scene::Render(HDC hdc) {
	Super::Render(hdc);

	wstring str = L"Homework21";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());
}
void Dev1Scene::Update()
{
	Super::Update();
	
	
	
}
void Dev1Scene::Release()
{
	Super::Release();
}