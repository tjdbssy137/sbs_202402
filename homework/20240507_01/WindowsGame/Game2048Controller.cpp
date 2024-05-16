#include "pch.h"
#include "Game2048Controller.h"
#include "NumberBlockActor.h"
#include "BoxCollider.h"

void Game2048Controller::Init(vector<NumberBlockActor*> numberBlocks)
{
	_numberBlocks = numberBlocks;


	//��ġ �ʱ�ȭ
	//ResetIsFull();
	InitIsFull();
	SumNumberBlocks();
}
void Game2048Controller::Update()
{
	
	{//�ѹ� ������ ���� ���� ������ ���� ��ȯ ���ϵ��� ����
		//������ �����¿� ����
		for (NumberBlockActor* numberBlock : _numberBlocks)
		{
			if (Input->GetKeyDown(KeyCode::Down))
			{
				this->MoveRight();
				this->SumNumberBlocks();
				this->CanCreateNumberBlock();
				this->CreateNumberBlock();
				//numberBlock->ChangeDirectionState(NumberBlockDirState::Down);
			}
			else if (Input->GetKeyDown(KeyCode::Up))
			{
				this->MoveLeft();
				this->SumNumberBlocks();
				this->CanCreateNumberBlock();
				this->CreateNumberBlock();
				//numberBlock->ChangeDirectionState(NumberBlockDirState::Up);				
			}
			else if (Input->GetKeyDown(KeyCode::Left))
			{
				this->MoveUp();
				this->SumNumberBlocks();
				this->CanCreateNumberBlock();
				this->CreateNumberBlock();
				//numberBlock->ChangeDirectionState(NumberBlockDirState::Left);				
			}
			else if (Input->GetKeyDown(KeyCode::Right))
			{
				this->MoveDown();
				this->SumNumberBlocks();
				this->CanCreateNumberBlock();
				this->CreateNumberBlock();
				//numberBlock->ChangeDirectionState(NumberBlockDirState::Right);
			}
		}
	}
}
void Game2048Controller::ResetIsFull()
{
	for (int i = 0; i < MAX_BLOCK_COUNT; i++)
	{
		_isFull[i] = 0;
	}
}
void Game2048Controller::InitIsFull()
{
	for (NumberBlockActor* numberBlock : _numberBlocks)
	{
		float posX = numberBlock->GetPos().x;
		float posY = numberBlock->GetPos().y;
		for (int check = 0; check < MAX_BLOCK_COUNT; check += 4)
		{
			if (posX == -200 + (check % 4) * 100)
			{
				if (posY == -200)
				{
					_isFull[check] = numberBlock->GetNumber();
				}
				else if (posY == -100)
				{
					_isFull[check + 1] = numberBlock->GetNumber();
				}
				else if (posY == 0)
				{
					_isFull[check + 2] = numberBlock->GetNumber();
				}
				else if (posY == 100)
				{
					_isFull[check + 3] = numberBlock->GetNumber();
				}
			}
		}
	}
}

void Game2048Controller::NumberBlockToZero()
{

}

void Game2048Controller::MoveDown()
{
	for (int i = 11; 0 <= i; i--)
	{
		if (_isFull[i] == 0)
		{
			continue;
		}
		else if (_isFull[i + 4] == 0)
		{
			int temp = _isFull[i];
			_isFull[i] = _isFull[i + 4];
			_isFull[i + 4] = temp;
		}
		else if (_isFull[i] == _isFull[i + 4])
		{
			_isFull[i + 4] += _isFull[i];
			_isFull[i] = 0;
		}
	}
}
void Game2048Controller::MoveUp()
{
	for (int i = 4; i < MAX_BLOCK_COUNT; i++)
	{
		if (_isFull[i] == 0)
		{
			continue;
		}
		else if (_isFull[i - 4] == 0)
		{
			int temp = _isFull[i];
			_isFull[i] = _isFull[i - 4];
			_isFull[i - 4] = temp;
		}
		else if (_isFull[i] == _isFull[i - 4])
		{
			_isFull[i - 4] += _isFull[i];
			_isFull[i] = 0;
		}
	}
}
void Game2048Controller::MoveLeft()
{
	for (int i = 0; i < MAX_BLOCK_COUNT; i++)
	{
		if (i % 4 == 0)
		{
			continue;
		}
		else
		{
			if (_isFull[i] == 0)
			{
				continue;
			}
			else if (_isFull[i - 1] == 0)
			{
				int temp = _isFull[i];
				_isFull[i] = _isFull[i - 1];
				_isFull[i - 1] = temp;
			}
			else if (_isFull[i] == _isFull[i - 1])
			{
				_isFull[i - 1] += _isFull[i];
				_isFull[i] = 0;
			}
		}
	}
}
void Game2048Controller::MoveRight()
{
	for (int i = 0; i < MAX_BLOCK_COUNT; i++)
	{
		if (i % 4 == 3)
		{
			continue;
		}
		else
		{
			if (_isFull[i] == 0)
			{
				continue;
			}
			else if (_isFull[i + 1] == 0)//0�� �ÿ��� �Ѿ��
			{
				int temp = _isFull[i];
				_isFull[i] = _isFull[i + 1];
				_isFull[i + 1] = temp;
			}
			else if (_isFull[i] == _isFull[i + 1])//������ ���ϱ�
			{
				_isFull[i + 1] += _isFull[i];
				_isFull[i] = 0;
			}
		}
	}
}
void Game2048Controller::SumNumberBlocks()
{
	for (int i = 0; i < MAX_BLOCK_COUNT; i++)
	{
		//cout << "_isFull[" << i << "]" << _isFull[i] << endl;
		_numberBlocks[i]->SetNumber(_isFull[i]);
		_numberBlocks[i]->ChangeImage(_numberBlocks[i]->GetNumber());
		//cout << "_numberBlocks[" << i << "]" << _numberBlocks[i]->GetNumber() << endl;
	}
	//this->InitIsFull();
}
void Game2048Controller::CreateNumberBlock()
{
	if (_canCreateNumberBlock == true)
	{
		// ����ִ��ڸ�ã��
		int random = Random->GetRandomInt(0, 16);
		while (_isFull[random] != 0)
		{
			random = Random->GetRandomInt(0, 16);
		}

		// ������ ���� ���ϱ�
		switch (Random->GetRandomInt(1, 5))
		{
		case 1 : // 4�� 20%�� ����
		{
			_isFull[random] = 4;
			_numberBlocks[random]->SetNumber(_isFull[random]);
			_numberBlocks[random]->ChangeImage(_numberBlocks[random]->GetNumber());
		}
		break;
		default:
		{
			_isFull[random] = 2;
			_numberBlocks[random]->SetNumber(_isFull[random]);
			_numberBlocks[random]->ChangeImage(_numberBlocks[random]->GetNumber());
		}
		break;
		}
		_canCreateNumberBlock = false;
	}

}
void Game2048Controller::CanCreateNumberBlock()
{
	int count = 0;
	for (int i = 0; i < 16; i++) {
		if (_isFull[i] != 0)
		{
			count++;
		}
	}
	if (count == 16)
	{
		_canCreateNumberBlock = false;
		//game over
	}
	else
	{
		_canCreateNumberBlock = true;
	}

}