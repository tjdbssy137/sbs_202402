#include "pch.h"
#include "Dev1Scene.h"
#include "BoxCollider.h"
#include "CreatureActor.h"
#include "UserCharacterController.h"
void Dev1Scene::Init()
{
	Super::Init();
	{
		_creature = new CreatureActor();
		_creature->SetPos(Vector2(WIN_SIZE_X / 2, WIN_SIZE_Y / 2));
		_creature->Init();
		SpawnActor(_creature);
	}

	{
		_userCharacterController = new UserCharacterController();
		_userCharacterController->Init(_creature);
	}
}

void Dev1Scene::Render(HDC hdc)
{
	Super::Render(hdc);

	wstring str = L"Dev1Scene";
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