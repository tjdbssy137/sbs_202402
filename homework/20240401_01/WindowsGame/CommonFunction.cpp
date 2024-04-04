#include "pch.h"
#include "CommonFunction.h"
namespace Collision
{
	bool PtInRect(POINT pt, RECT rect)
	{
		if (rect.left <= pt.x && pt.x <= rect.right &&
			rect.top <= pt.y && pt.y <= rect.bottom)
		{
			return true;
		}
		return false;
	}
	// 오버라이드 : 클래스에서의 상속 개념, 자식 클래스를 호출
	// 오버로딩 : 함수명은 같은데 매개변수가 다름
	bool PtInRect(int ptX, int ptY, int x1, int y1, int x2, int y2)
	{
		if (x1 <= ptX && ptX <= x2 &&
			y1 <= ptY && ptY <= y2)
		{
			return true;
		}
		return false;
	}
	bool RectInRect(RECT rect1, RECT rect2)
	{
		{
			POINT pt1 = { rect1.left, rect1.top };
			POINT pt2 = { rect1.right, rect1.top };
			POINT pt3 = { rect1.left, rect1.bottom };
			POINT pt4 = { rect1.right, rect1.bottom };

			POINT pt5 = { rect2.left, rect2.top };
			POINT pt6 = { rect2.right, rect2.top };
			POINT pt7 = { rect2.left, rect2.bottom };
			POINT pt8 = { rect2.right, rect2.bottom };


			return PtInRect(pt1, rect2) || PtInRect(pt2, rect2) || PtInRect(pt3, rect2) || PtInRect(pt4, rect2) ||
				PtInRect(pt5, rect1) || PtInRect(pt6, rect1) || PtInRect(pt7, rect1) || PtInRect(pt8, rect1);
		}
	}
}