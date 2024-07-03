#pragma once
#include "UI.h"
class Sprite;

class UISpriteNumber : public UI
{
	DECLARE_CHILD(UISpriteNumber, UI);
public:
	int _number = 0;
	Sprite* _sprites[10] = {};

public:
	void SetNumber(int number);
	// resourceName : S_SpriteNumber
	// _sprites[0] : S_SpriteNumber_0
	void SetSprites(wstring resourceName);
	void SetSprite(Sprite* sprite, int number);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};

