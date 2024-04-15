#pragma once

//��ܾ��� �Լ����� �߰����ٰſ���.

namespace Collision
{
	bool PtInRect(POINT pt, RECT rect);
	bool PtInRect(int ptX, int ptY, int x1, int y1, int x2, int y2);
	bool RectInRect(RECT rect1, RECT rect2);
}

namespace Shape
{
	// ���� �ڷ��� ���� �� �ַ� ���� namespace
	
	// inline Ű����� #define (��ũ�� �� �Ͱ� ���� �ӵ��� ���� ���ؼ� ���)
	// inline�� ���� : ��������� �����ؾ���. == ��ũ ������ �߻��� Ȯ���� ����.
	inline RECT MakeRect(int x, int y, int width, int height)
	{
		RECT rc;
		rc.left = x - static_cast<int>(width / 2);
		rc.right = x + static_cast<int>(width / 2);
		rc.top = y - static_cast<int>(height / 2);
		rc.bottom = y + static_cast<int>(height / 2);

		return rc;
	}

	inline CenterRect MakeCenterRect(float x, float y, float width, float height)
	{
		CenterRect rc;
		rc.pos.x = x;
		rc.pos.y = y;
		rc.width = width;
		rc.height = height;
		return rc;
	}

	inline CenterRect MakeCenterRectLTRB(float left, float top, float right, float bottom)
	{
		CenterRect rc;
		rc.pos.x = (left + right) / 2;
		rc.pos.y = (top + bottom) / 2;
		rc.width = right - left;
		rc.height = bottom - top;
		return rc;
	}

	inline CenterRect MakeCenterRectLTWH(float left, float top, float width, float height)
	{
		CenterRect rc;
		rc.pos.x = (left + width) / 2;
		rc.pos.y = (top + height) / 2;
		rc.width = width;
		rc.height = height;
		return rc;
	}


	inline void ChangeToNormalValue(RECT& rc)
	{
		if (rc.right < rc.left)
		{
			LONG temp = rc.left;
			rc.left = rc.right;
			rc.right = temp;
		}

		if (rc.bottom < rc.top)
		{
			LONG temp = rc.top;
			rc.top = rc.bottom;
			rc.bottom = temp;
		}
	}
}