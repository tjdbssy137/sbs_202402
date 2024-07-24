#pragma once
class BoatActor;
class TowerDefenseScene;

class BoatController
{
private:
	BoatActor* _boat = nullptr;
	TowerDefenseScene* _currentScene = nullptr;
public:
	void SetLink(BoatActor* boat);
	void Update();
public:
	vector<Vector2Int> Calculator_Astar(Vector2Int startPos, Vector2Int endPos);
	void Arrive();
	void Depart();

private:
	Vector2Int _start = {};
	Vector2Int _goal = {};
};

