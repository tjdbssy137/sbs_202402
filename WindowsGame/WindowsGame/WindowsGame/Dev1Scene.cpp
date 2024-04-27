#include "pch.h"
#include "Dev1Scene.h"
#include "BoxCollider.h"
#include "CreatureActor.h"
#include "MonsterActor.h"
#include "UserCharacterController.h"
void Dev1Scene::Init()
{
	Super::Init();
	{
		_creature = new CreatureActor();
		_creature->SetPos(Vector2(WIN_SIZE_X / 2, WIN_SIZE_Y / 2));
		
		BoxCollider* collider = new BoxCollider();
		collider->SetCollision(Shape::MakeCenterRect(0, 0, 55, 60));
		_creature->AddComponent(collider);
		
		_creature->Init();
		SpawnActor(_creature);
	}
	{
		_monster = new MonsterActor();
		_monster->SetPos(Vector2(WIN_SIZE_X / 2, WIN_SIZE_Y / 2 - 60));

		BoxCollider* collider = new BoxCollider();
		collider->SetCollision(Shape::MakeCenterRect(0, 0, 28, 28));
		_monster->AddComponent(collider);
		
		_monster->Init();
		SpawnActor(_monster);
	}
	{
		_userCharacterController = new UserCharacterController();
		_userCharacterController->Init(_creature, _monster);
	}
}

void Dev1Scene::Render(HDC hdc)
{
	Super::Render(hdc);

	wstring str = L"Zelda";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());



}
void Dev1Scene::Update()
{
	Super::Update();
	_userCharacterController->Update();


}
void Dev1Scene::Release()
{
	Super::Release();

}