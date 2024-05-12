#include "pch.h"
#include "Game2048Controller.h"
#include "NumberBlockActor.h"
#include "BoxCollider.h"

void Game2048Controller::Init(vector<NumberBlockActor*> numberBlocks)
{
	_numberBlocks = numberBlocks;
}
void Game2048Controller::Update()
{
	{//한번 누르면 끝에 닿을 때까지 방향 전환 못하도록 막기
		for (NumberBlockActor* numberBlock : _numberBlocks)
		{
			if (Input->GetKeyDown(KeyCode::Down))
			{
				numberBlock->ChangeDirectionState(NumberBlockDirState::Down);
			}
			else if (Input->GetKeyDown(KeyCode::Up))
			{
				numberBlock->ChangeDirectionState(NumberBlockDirState::Up);				
			}
			else if (Input->GetKeyDown(KeyCode::Left))
			{
				numberBlock->ChangeDirectionState(NumberBlockDirState::Left);				
			}
			else if (Input->GetKeyDown(KeyCode::Right))
			{
				numberBlock->ChangeDirectionState(NumberBlockDirState::Right);
			}
		}
	}
	//this->SumNumberBlocks();
}

void Game2048Controller::SumNumberBlocks()
{
	//블럭이 하나 있고
	//그외의 블럭들과 충돌했는지 비교

	int repeatCount = _numberBlocks.size();
	int repeatCount2 = _numberBlocks.size() - 1;
	for (int i = 0; i < repeatCount; i++)
	{
		NumberBlockActor* prevNumberBlock = _numberBlocks[i];
		_numberBlocks.erase(_numberBlocks.begin());
		
		for (int j = 0; j < repeatCount2; j++)
		{
			BoxCollider* prevNumberBlockCollider = prevNumberBlock->GetComponent<BoxCollider>();
			BoxCollider* otherumberBlockCollider = _numberBlocks[j]->GetComponent<BoxCollider>();
			if (Collision::RectInRect(prevNumberBlockCollider->GetCollision().ToRect(), otherumberBlockCollider->GetCollision().ToRect()))
			{
				if (prevNumberBlock->GetNumber() == _numberBlocks[j]->GetNumber())
				{
					prevNumberBlock->SetNumber();
					prevNumberBlock->ChangeImage(prevNumberBlock->GetNumber());
					_numberBlocks.erase(_numberBlocks.begin() + j);
				}
			}
		}
		_numberBlocks.push_back(prevNumberBlock);
	}

}