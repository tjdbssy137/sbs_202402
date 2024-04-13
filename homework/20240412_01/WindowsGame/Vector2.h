#pragma once
// struct : ������ ��� ����
// class : ū.. ������ ���.. ��¼��
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
	Vector2 Normalize(); // ������ ���̸� 1�� ����� �ش�
	
	Vector2(float x, float y);
	Vector2();


	// ������ �ַ� �� Vector ������ ������ ����� �� ���� ���δ�.
	// A Dot B = A.x * B.x + A.y * B.y
	// A Dot B = |A| * |B| * cos(theta)
	// -> A B �Ѵ� ���̰� 1�̸� A Dot B = cos(theta)
	// -> cos(theta)�� �� ���Ͱ� �̷�� ������ ��Ÿ����.
	// -> ��, ������ �� ���Ͱ� �̷�� ������ ���� �� ����Ѵ�.

	// Tip1.
	//	- cos �׷����� 
	//	- 0�� �� ��1, 90�� �� �� 0, 180�� �� �� -1 �̴�.
	// Tip2.
	// - ����(�� ���� ������ ����)���δ� 180���� �Ѵ� ������ ������ �� ����.
	// Tip3.
	// - other ���Ͱ� �� �ڿ� �ִ��� Ȯ���Ϸ���
	// - ������ 0���� ������ �� �ڿ� �ִ�(90���� �Ѿ�ٴ� ��)
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

