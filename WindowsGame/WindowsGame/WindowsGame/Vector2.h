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


	// 내적은 주로 두 Vector 사이의 각도를 계산할 때 많이 쓰인다.
	// A Dot B = A.x * B.x + A.y * B.y
	// A Dot B = |A| * |B| * cos(theta)
	// -> A B 둘다 길이가 1이면 A Dot B = cos(theta)
	// -> cos(theta)는 두 벡터가 이루는 각도를 나타낸다.
	// -> 즉, 내적은 두 벡터가 이루는 각도를 구할 때 사용한다.

	// Tip1.
	//	- cos 그래프는 
	//	- 0도 일 때1, 90도 일 때 0, 180도 일 때 -1 이다.
	// Tip2.
	// - 내적(두 벡터 사이의 각도)으로는 180도가 넘는 각도가 존재할 수 없다.
	// Tip3.
	// - other 벡터가 내 뒤에 있는지 확인하려면
	// - 내적이 0보다 작으면 내 뒤에 있다(90도가 넘어갔다는 뜻)
	float Dot(Vector2 other);

	Vector2 Reflect(Vector2 normal);
	static Vector2 Reflect(Vector2 originVector, Vector2 normal);

	static Vector2 Zero()
	{
		return Vector2(0, 0);
	}
	static Vector2 Up()
	{
		return Vector2(0, -1);
	}
	static Vector2 Down()
	{
		return Vector2(0, 1);
	}
	static Vector2 Right()
	{
		return Vector2(1, 0);
	}
	static Vector2 Left()
	{
		return Vector2(-1, 0);
	}

};

