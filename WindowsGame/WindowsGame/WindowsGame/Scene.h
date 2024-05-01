#pragma once
class Actor; // ���漱��

class Scene
{

protected:
	vector<Actor*> _actors;

	Vector2Int _cameraPosition = {};
public:
	//---------------
	// �⺻ �Լ�
	//---------------
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

public:
	// Actor ���� �Լ�
	void SpawnActor(Actor* actor);
	void DespawnActor(Actor* actor);

	// Camera ���� �Լ�
	void SetCameraPos(Vector2Int pos) { _cameraPosition = pos; }
	Vector2Int GetCameraPos() { return _cameraPosition; }
};

