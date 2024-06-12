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

	// dijikstra처럼 best노드가 없어도 여기 아래서 Cost비교를 알아서 해줌. 그게 우선순위큐의 장점임.
	bool operator<(const PQNode& other) const
	{
		return Cost < other.Cost;
	}
	bool operator>(const PQNode& other) const
	{
		return Cost > other.Cost;
	}
};