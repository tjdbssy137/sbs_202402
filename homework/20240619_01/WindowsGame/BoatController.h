#pragma once
class BoatActor;
class Dev2Scene;

class BoatController
{
private:
	BoatActor* _boat = nullptr;
	Dev2Scene* _currentScene = nullptr;
public:
	void SetLink(BoatActor* boat);
	void Update();
public:
	vector<Vector2Int> Calculator_Astar(Vector2Int startPos, Vector2Int endPos);
	void Arrive();
private:
	Vector2Int _start = {};
	Vector2Int _goal = {};
};

