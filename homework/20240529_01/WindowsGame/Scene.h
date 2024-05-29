#pragma once
class Actor;
class UI;
class Scene
{
protected:
	//_actors[LayerType::Background] => vector<Actor*>
	//_actors[LayerType::Object] => vector<Actor*>
	//_actors[LayerType::Character] => vector<Actor*>
	vector<Actor*> _actors[static_cast<int>(LayerType::End)];
	Vector2 _cameraPosition = {};
	vector<UI*> _uis;

//-----------------------------
//  ## 기본함수 
//-----------------------------
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	//Actor 조작함수
	void SpawnActor(Actor* actor);
	void DespawnActor(Actor* actor);

public:
	//Camera 조작함수
	void SetCameraPos(Vector2 pos) { _cameraPosition = pos; }
	Vector2 GetCameraPos() { return _cameraPosition; }
};

