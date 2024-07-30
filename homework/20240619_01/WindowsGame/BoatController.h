#pragma once
class BoatActor;
class EffectActor;

class BoatController
{
private:
	BoatActor* _boat = nullptr;
public:
	void SetLink(BoatActor* boat);
	void Update();
public:
	vector<Vector2Int> Calculator_Astar(Vector2Int startPos, Vector2Int endPos);
	void Arrive();
	void Depart();
	void FinishedBoatState();
	void DeathEffect();

private:
	Vector2Int _start = {};
	Vector2Int _goal = {};

private:
	EffectActor* _effect;
};

