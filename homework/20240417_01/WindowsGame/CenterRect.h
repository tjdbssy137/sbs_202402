#pragma once
struct Vector2;
struct CenterRect
{
	Vector2 pos;
	float width, height;

	RECT ToRect();
	void Draw(HDC hdc);
};

