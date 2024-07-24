#include "pch.h"
#include "SceneManager.h"
#include "Scene.h"
#include "TowerDefenseScene.h"
void SceneManager::Init()
{

}
void SceneManager::Render(HDC hdc)
{
	if (_scene)
	{
		_scene->Render(hdc);
	}
}
void SceneManager::Update()
{
	if (_scene)
	{
		_scene->Update();
	}
	if (_nextSceneType == SceneType::None) //_nextSceneType != SceneType::None ����
	{
		return;
	}

	// -----------------
	// Scene Change
	// -----------------
	if (_scene)
	{
		_scene->Release();
	}
	Scene* newScene = nullptr;
	switch (_nextSceneType)
	{
	case SceneType::None:
		break;
	case SceneType::TowerDefenseScene:
		newScene = new TowerDefenseScene();
		break;
	default:
		break;
	}

	SAFE_DELETE(_scene);
	_scene = newScene;
	_sceneType = _nextSceneType;
	_nextSceneType = SceneType::None;
	newScene->Init();
}
void SceneManager::Release()
{
	if (_scene)
	{
		_scene->Release();
	}
}

void SceneManager::ChangeScene(SceneType sceneType)
{
	if (_sceneType == sceneType)
	{
		return;
	}
	_nextSceneType = sceneType;
}
