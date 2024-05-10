#pragma once
class Actor; // 전방선언

class Scene
{

protected:
	vector<Actor*> _actors;

	Vector2 _cameraPosition = {};
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

	// Camera 조작 함수
	void SetCameraPos(Vector2 pos) { _cameraPosition = pos; }
	Vector2 GetCameraPos() { return _cameraPosition; }
};

