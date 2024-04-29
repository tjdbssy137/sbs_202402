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
			if (numberRects2->GetPos() == Vector2(numberRects->GetPos().x + x, numberRects->GetPos().y + y)) //오른쪽
			{
				if (numberRects->GetValue() == numberRects2->GetValue())
				{
					numberRects->SlideActor();
					numberRects->ChangeDirectionState(_dirState);
					// numberRects가 이동하고 삭제 되어야함.
					numberRects2->ChangeImage(numberRects2->GetValue() * 2);
					numberRects->ChangeImage(0);//삭제
				}
			}
		}
	}
	
	//최대 두번 숫자가 맞으면 겹쳐져야 하고
	//가장자리에 있는 것은 이동하면 안되고
	//이동은 한번에 한 방향으로 끝에서 끝까지 해야함.
	//.....
}
*/