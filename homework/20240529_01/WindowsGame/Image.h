#pragma once
#include "UI.h"
class Sprite;
class Image : public UI
{
	DECLARE_CHILD(Image, UI);

public:
	void SetSprite(Sprite* sprite) { _sprite = sprite; }
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

protected:
	Sprite* _sprite = nullptr;
};

