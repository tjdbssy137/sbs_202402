#pragma once

//즐겨쓰는 함수들을 추가해줄거에요.

namespace Collision
{
	bool PtInRect(POINT pt, RECT rect);
	bool PtInRect(int ptX, int ptY, int x1, int y1, int x2, int y2);
	bool RectInRect(RECT rect1, RECT rect2);
}