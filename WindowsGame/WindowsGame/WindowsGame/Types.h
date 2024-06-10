#pragma once
// 타입들을 추가해줄거에요.

using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;
using uint8 = unsigned __int8;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;

#include "Vector2.h"
#include "CenterRect.h"
#include "Vector2Int.h"


struct PQNode
{
	int Cost;
	Vector2Int Vertex;

	int G;

	bool operator<(const PQNode& other) const
	{
		return Cost < other.Cost;
	}
	bool operator>(const PQNode& other) const
	{
		return Cost > other.Cost;
	}
};