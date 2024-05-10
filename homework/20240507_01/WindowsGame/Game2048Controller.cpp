#include "pch.h"
#include "Game2048Controller.h"
#include "NumberBlockActor.h"

void Game2048Controller::Init(vector<NumberBlockActor*> numberBlocks)
{
	_numberBlocks = numberBlocks;
}
void Game2048Controller::Update()
{
	{
		for (NumberBlockActor* numberBlock : _numberBlocks)
		{
			if (Input->GetKeyDown(KeyCode::Down))
			{
				numberBlock->ChangeDirectionState(NumberBlockDirState::Down);
				numberBlock->SlideActor();
				//numberBlock->SetPos(Vector2(numberBlock->GetPos().x, numberBlock->GetPos().y + 100));
				//numberBlock->SetPos(Vector2(numberBlock->GetPos().x, numberBlock->GetPos().y + 100));

			}
			else if (Input->GetKeyDown(KeyCode::Up))
			{
				numberBlock->ChangeDirectionState(NumberBlockDirState::Up);
				numberBlock->SlideActor(); 
				//numberBlock->SetPos(Vector2(numberBlock->GetPos().x, numberBlock->GetPos().y - 100));
				//->SetPos(Vector2(numberBlock->GetPos().x, numberBlock->GetPos().y - 100));
			}
			else if (Input->GetKeyDown(KeyCode::Left))
			{
				numberBlock->ChangeDirectionState(NumberBlockDirState::Left);
				numberBlock->SlideActor(); 
				//numberBlock->SetPos(Vector2(numberBlock->GetPos().x - 100, numberBlock->GetPos().y));
				//numberBlock->SetPos(Vector2(numberBlock->GetPos().x - 100, numberBlock->GetPos().y));
			}
			else if (Input->GetKeyDown(KeyCode::Right))
			{
				numberBlock->ChangeDirectionState(NumberBlockDirState::Right);
				numberBlock->SlideActor(); 
				//numberBlock->SetPos(Vector2(numberBlock->GetPos().x + 100, numberBlock->GetPos().y));
				//numberBlock->SetPos(Vector2(numberBlock->GetPos().x + 100, numberBlock ->GetPos().y));
			}
		}
		
	}
}