#pragma once
#include "Scene.h"
class Pumpkin;
class SpriteActor;

#define PUMPKIN_MAX 20
class PooGame : public Scene
{
	using Super = Scene;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void PlayerMove();
	void IsCollisionEnter();

private:
	SpriteActor* _player = nullptr;
	vector<Pumpkin*> _pumpkin;

private: // pumpkin
	float _time = 0;	
	float _throwTime = 0;
	int _pumpkinOrder = 0;
	
private: // player
	float _speed = 0.0f;

};

