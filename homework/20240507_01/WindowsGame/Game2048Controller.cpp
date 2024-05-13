#include "pch.h"
#include "Game2048Controller.h"
#include "NumberBlockActor.h"
#include "BoxCollider.h"

void Game2048Controller::Init(vector<NumberBlockActor*> numberBlocks)
{
	_numberBlocks = numberBlocks;

	//위치 초기화
	ResetIsFull();
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
}
void Game2048Controller::ResetIsFull()
{
	for (int i = 0; i < MAX_BLOCK_COUNT; i++)
	{
		_isFull[i] = false;
	}
}
void Game2048Controller::InitIsFull()
{
	int check = 0;
	for (NumberBlockActor* numberBlock : _numberBlocks)
	{
		float posX = numberBlock->GetPos().x;
		float posY = numberBlock->GetPos().y;
		if (posX < -150 + (check % 4) * 100)
		{
			if (posY < -150)
			{
				_isFull[check] = true;
			}
			else if (posY < -50)
			{
				_isFull[check + 1] = true;
			}
			else if (posY < 50)
			{
				_isFull[check + 2] = true;
			}
			else if (posY < 150)
			{
				_isFull[check + 3] = true;
			}
		}
		check += 4;
	}
}
void Game2048Controller::ChangeIsFull()
{
	if (Input->GetKeyDown(KeyCode::Down))
	{
		for (int i = 11; 0 <= i; i--)
		{
			_isFull[i] = false;
			_isFull[i + 4] = true;
		}
	}
	else if (Input->GetKeyDown(KeyCode::Up))
	{
		for (int i = 4; i < MAX_BLOCK_COUNT; i++)
		{
			_isFull[i] = false;
			_isFull[i - 4] = true;
		}
	}
	else if (Input->GetKeyDown(KeyCode::Left))
	{
		for (int i = 0; i < MAX_BLOCK_COUNT; i++)
		{
			if (i % 4 == 0)
			{
				return;
			}
			else
			{
				_isFull[i] = false;
				_isFull[i - 1] = true;
			}
		}
	}
	else if (Input->GetKeyDown(KeyCode::Right))
	{
		for (int i = 0; i < MAX_BLOCK_COUNT; i++)
		{
			if (i % 4 == 3)
			{
				return;
			}
			else
			{
				_isFull[i] = false;
				_isFull[i + 1] = true;
			}
		}
	}
}
void Game2048Controller::SumNumberBlocks()
{
	
}