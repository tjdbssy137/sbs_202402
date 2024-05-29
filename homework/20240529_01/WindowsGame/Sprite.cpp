#include "pch.h"
#include "Sprite.h"
#include "Texture.h"

Sprite::Sprite(Texture* texture, int x, int y, int cx, int cy)
	 : _texture(texture), _x(x), _y(y), _cx(cx), _cy(cy)
{
	//_texture = texture;
	//_x = x;
	//_y = y;
	//_cx = cx;
	//_cy = cy;
}
Sprite::~Sprite()
{

}
HDC Sprite::GetDC()
{
	return _texture->GetDC();
}
int32 Sprite::GetTransparent()
{
	return _texture->GetTransparent();
}
Vector2Int Sprite::GetPos()
{
	return Vector2Int(_x, _y);
}
Vector2Int Sprite::GetSize()
{
	return Vector2Int(_cx, _cy);
}