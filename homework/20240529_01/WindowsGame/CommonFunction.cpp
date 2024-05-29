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

	//�������̵� : Ŭ���������� ��Ӱ��� (virtual)
	//				�ڽ�Ŭ������ ȣ���ϵ����ϴ�
	
	//�����ε� : �Լ����� ������ �ŰԺ����� �ٸ���
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


	bool CircleInCircle(Vector2 pos1, float radius1, Vector2 pos2, float radius2)
	{
		//Circle <-> Circle
		// Circle1, Circle2 => �߽���ǥ
		// �߽���ǥ�� ���� <= (Circle1 ������ + Circle2 ������)

		Vector2 lengthVector = pos2 - pos1;
		float length_sq = lengthVector.LengthSqrt();

		if (length_sq <= (radius1 + radius2) * (radius1 + radius2))
		{
			return true;
		}

		return false;
	}

	bool RectInCircle(CenterRect rect, Vector2 circlePos, float radius)
	{
		// �簢���� �߽ɰ� ���� �߽� ������ �Ÿ�
		// abs(����)
		float dx = abs(rect.pos.x - circlePos.x);
		float dy = abs(rect.pos.y - circlePos.y);

		// �簢���� ���� �߽� ������ �Ÿ��� ���
		float distX = dx - rect.width / 2;
		float distY = dy - rect.height / 2;

		//1. ���� ũ�� �簢��ȭ �ص� �浹�� �����ʴ� ���
		if (distX > radius || distY > radius)
		{
			return false;
		}

		//2. �簢���� ���� �߽����� �����ϰ��ִ� ���
		if (distX <= 0 || distY <= 0)
		{
			return true;
		}

		//3. �簢���� �������� ���� �߽� ������ �Ÿ��� ���������� �������
		float cornerDistanceSqrt = (distX * distX) + (distY * distY);

		return cornerDistanceSqrt <= (radius * radius);

	}
}