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
	/*for (int i = 0; i < _actors.size(); i++)
	{
		_actors[i]->Render(hdc);
	}*/

	//ranged-base
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
		ui->Release();
		SAFE_DELETE(ui);
	}
	_uis.clear();

	GET_SINGLE(CollisionManager)->ClearCollider();
}

void Scene::SpawnActor(Actor* actor)
{
	if (actor == nullptr) return;

	_actors[actor->GetLayerInt()].push_back(actor);
}
void Scene::DespawnActor(Actor* actor)
{
	if (actor == nullptr) return;

	vector<Actor*>& actors = _actors[actor->GetLayerInt()];

	//삭제할 객체찾기
	auto findIt = find(actors.begin(), actors.end(), actor);

	if (findIt != actors.end())
	{
		(*findIt)->Release();
		Actor* deleteActor = (*findIt);
		SAFE_DELETE(deleteActor);
		actors.erase(findIt);
	}
}