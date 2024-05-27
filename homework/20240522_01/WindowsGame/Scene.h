#pragma once
class Actor; // ���漱��
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
	void SetCameraPos(Vector2 pos) { _cameraPosition = pos; }
	Vector2 GetCameraPos() { return _cameraPosition; }
};
