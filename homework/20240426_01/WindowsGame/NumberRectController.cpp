#include "pch.h"
#include "NumberRectController.h"
#include "NumberRectActor.h"
void NumberRectController::Init(vector<NumberRectActor*> numberRects)
{
	_numberRects = numberRects;
}
void NumberRectController::Update()
{
	/*
	{
		if (Input->GetKeyDown(KeyCode::Down))
		{
			this->MoveNumberRect(0, 300, MoveDirectionState::Down);
		}
		else if (Input->GetKeyDown(KeyCode::Up))
		{
			this->MoveNumberRect(0, -300, MoveDirectionState::Up);
		}
		else if (Input->GetKeyDown(KeyCode::Left))
		{
			this->MoveNumberRect(300, 0, MoveDirectionState::Left);
		}
		else if (Input->GetKeyDown(KeyCode::Right))
		{
			this->MoveNumberRect(-300, 0, MoveDirectionState::Right);
		}
	}
	*/
}
/*
void NumberRectController::MoveNumberRect(int x, int y, MoveDirectionState _dirState)
{
	
	for (NumberRectActor* numberRects : _numberRects)
	{
		for (NumberRectActor* numberRects2 : _numberRects)
		{
			if (numberRects2->GetPos() == Vector2(numberRects->GetPos().x + x, numberRects->GetPos().y + y)) //������
			{
				if (numberRects->GetValue() == numberRects2->GetValue())
				{
					numberRects->SlideActor();
					numberRects->ChangeDirectionState(_dirState);
					// numberRects�� �̵��ϰ� ���� �Ǿ����.
					numberRects2->ChangeImage(numberRects2->GetValue() * 2);
					numberRects->ChangeImage(0);//����
				}
			}
		}
	}
	
	//�ִ� �ι� ���ڰ� ������ �������� �ϰ�
	//�����ڸ��� �ִ� ���� �̵��ϸ� �ȵǰ�
	//�̵��� �ѹ��� �� �������� ������ ������ �ؾ���.
	//.....
}
*/