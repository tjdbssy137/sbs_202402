#include "pch.h"
#include "Scene.h"
#include "Actor.h"
#include "UI.h"
void Scene::Init()
{
	for (UI* ui : _uis)
	{
		ui->Init();
	}
}
void Scene::Render(HDC hdc) 
{
	for (const vector<Actor*> actors : _actors)
	{
		for (Actor* actor : actors)
		{
			actor->Render(hdc);
		}
	}
	for (UI* ui : _uis)
	{
		ui->Render(hdc);
	}
}
void Scene::Update()
{
	for (const vector<Actor*> actors : _actors)
	{
		for (Actor* actor : actors)
		{
			actor->Update();
		}
	}
	for (UI* ui : _uis)
	{
		ui->Update();
	}
}
void Scene::Release()
{
	for (vector<Actor*>& actors : _actors)
	{
		for (Actor* actor : actors)
		{
			actor->Release();
			SAFE_DELETE(actor);
		}
		actors.clear();
	}

	for (UI* ui : _uis)
	{
		ui->Init();
		SAFE_DELETE(ui);
	}
	_uis.clear();

	GET_SINGLE(CollisionManager)->ClearCollider();
}

void Scene::SpawnActor(Actor* actor)
{
	if (actor == nullptr) return;
	//actor->Init();
	_actors[actor->GetLayerInt()].push_back(actor);
	//actor의 레이어가 object면 object로 들어갈 거고, background면 background로 들어가게 끔
}
void Scene::DespawnActor(Actor* actor)
{
	if (actor == nullptr) return;
	//삭제할 객체 찾기
	vector<Actor*>& actors = _actors[actor->GetLayerInt()];// 지우는 것엔 &를 붙여주어야 함
	
	auto findIt = find(actors.begin(), actors.end(), actor);
	if (findIt != actors.end())
	{
		(*findIt)->Release();
		Actor* deleteActor = (*findIt);
		SAFE_DELETE(deleteActor);
		actors.erase(findIt);
	}
}