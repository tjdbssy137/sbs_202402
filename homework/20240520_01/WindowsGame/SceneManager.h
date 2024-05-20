#pragma once
class Scene; // 헤더에서 헤더를 불러오는 것보단, 클래스 전방선언으로 *변수만 사용할 수 있게 함.
class SceneManager
{
	DECLARE_SINGLE(SceneManager);

public:
	void Init();
	void Render(HDC hdc);
	void Update();
	void Release();

public :
	void ChangeScene(SceneType sceneType);

private:
	SceneType _sceneType = SceneType::None;
	SceneType _nextSceneType = SceneType::None;

private:
	Scene* _scene = nullptr;

public:
	Scene* GetCurrentScene() { return _scene; }
};

