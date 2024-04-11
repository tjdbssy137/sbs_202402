#pragma once
class Actor; // 전방선언

class Scene
{

protected:
	vector<Actor*> _actors;
public:
	//---------------
	// 기본 함수
	//---------------
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	void SpawnActor(Actor* actor);
	void DespawnActor(Actor* actor);
};

