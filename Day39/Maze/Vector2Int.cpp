#include "pch.h"
#include "Vector2Int.h"

Vector2Int::Vector2Int() : x(0), y(0)
{
}
Vector2Int::Vector2Int(int x, int y) : x(x), y(y)
{

}
Vector2Int Vector2Int::operator+(const Vector2Int& other)
{
	return Vector2Int(other.x + this->x, other.y + this->y);
}
Vector2Int Vector2Int::operator-(const Vector2Int& other)
{
	return Vector2Int(this->x - other.x, this->y - other.y);
}
Vector2Int Vector2Int::operator*(const int32 value)
{
	return Vector2Int(this->x - value, this->y - value);
}
void Vector2Int::operator+=(const Vector2Int& other)
{
	this->x += other.x;
	this->y += other.y;
}
void Vector2Int::operator-=(const Vector2Int& other)
{
	this->x -= other.x;
	this->y -= other.y;
}
void Vector2Int::operator*=(int32 value)
{
	this->x *= value;
	this->y *= value;
}

float Vector2Int::Length()
{
	return sqrtf(this->x * this->x + this->y * this->y);
}

bool Vector2Int::operator==(const Vector2Int& other)
{
	return this->x == other.x && this->y == other.y;
}

bool Vector2Int::operator!=(const Vector2Int& other)
{
	return this->x != other.x || this->y != other.y;
}
bool Vector2Int::operator<=(const Vector2Int& other)
{
	return this->x <= other.x && this->y <= other.y;
}
bool Vector2Int::operator>=(const Vector2Int& other)
{
	return other.x <= this->x && other.y <= this->y;
}