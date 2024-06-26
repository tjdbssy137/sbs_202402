#pragma once
class BoatActor;
class Dev2Scene;
class BoatController
{
private:
	BoatActor* _actor = nullptr;
	float _trueTime = 0.135f;
	Dev2Scene* _currentScene = nullptr;
public:
	void SetLink(BoatActor* actor);
	void Update();
public:
	vector<Vector2Int> Calculator_Astar(Vector2Int startPos, Vector2Int endPos);
private:
	Vector2Int _start = {};
	Vector2Int _goal = {};
};

