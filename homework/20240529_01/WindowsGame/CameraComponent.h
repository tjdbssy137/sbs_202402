#pragma once
#include "Component.h"
class Sprite;
struct CenterRect;
class CameraComponent : public Component
{
public:
	using Super = Component;

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;


public:
	CameraComponent() { }
	virtual ~CameraComponent() {}

public:
	//����� ������ �־��ش�.
	void SetLTWH(int left, int top, int width, int height);
	void SetLTWH(Sprite* backgroundSprite);
	void SetLTWH(CenterRect backgroundBody);

protected:
	int _minX = 0;
	int _maxX = 0;
	int _minY = 0;
	int _maxY = 0;

	float _sumTime = 0.0f;	// ���� ���� �������� üũ�ð�
	float _duration = 0.5f;	// �����ϴµ� �ɸ� �ð�,
	Vector2 _startPos = Vector2::Zero();
	Vector2 _endPos = Vector2::Zero();
};

