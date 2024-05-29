#pragma once
#include "ResourceBase.h"

class Texture;
class Sprite : public ResourceBase
{
public:
	Sprite(Texture* texture, int x, int y, int cx, int cy);
	virtual ~Sprite();

public:
	HDC GetDC();
	int32 GetTransparent();
	Vector2Int GetPos();
	Vector2Int GetSize();

protected:
	Texture* _texture = nullptr;
	int _x;
	int _y;
	int _cx;
	int _cy;
};
