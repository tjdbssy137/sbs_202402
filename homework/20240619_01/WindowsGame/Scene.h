#pragma once
class Actor; // 전방선언
class UI;
class Scene
{
protected:
	//_acotrs[LayerType::Background] => vector<Actor*>
	vector<Actor*> _actors[static_cast<int>(LayerType::End)];

	Vector2 _cameraPosition = {};

	vector<UI*> _uis;
public:
	//---------------
	// 기본 함수
	//---------------
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	// Actor 조작 함수
	void SpawnActor(Actor* actor);
	void DespawnActor(Actor* actor);

	//UI 추가함수
	void AddUI(UI* ui);
	void RemoveUI(UI* ui);

	// Camera 조작 함수
	void SetCameraPos(Vector2 pos) { _cameraPosition = pos; }
	Vector2 GetCameraPos() { return _cameraPosition; }
};

