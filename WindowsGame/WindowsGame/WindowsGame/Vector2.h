#pragma once
// struct : 정보를 담는 단위
// class : 큰.. 정보를 담는.. 어쩌고
struct Vector2
{
	float x = 0, y = 0;

	Vector2 operator-(const POINT pt);
	Vector2 operator-(const Vector2 other);
	void operator-=(const Vector2 other);
	Vector2 operator+(const POINT pt);
	Vector2 operator+(const Vector2 other);
	void operator+=(const Vector2 other);
	Vector2 operator*(const float other);
	void operator*=(const float other);
	Vector2 operator/(const float other);
	void operator/=(const float other);

	float Length();
	Vector2 Normalize(); // 벡터의 길이를 1로 만들어 준다
	
	Vector2(float x, float y);
	Vector2();
};

