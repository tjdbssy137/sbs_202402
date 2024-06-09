#pragma once
class CreatureActor;
class Dev2Scene;
class CreatureController
{
private:
	CreatureActor* _actor = nullptr;
	float _trueTime = 0.135f;
	Dev2Scene* _currentScene = nullptr;
public:
	void SetLink(CreatureActor* actor);
	void Update();
public:
	void Calculate_BFS();
private:
	Vector2Int _start = {};
	Vector2Int _goal = {};
};