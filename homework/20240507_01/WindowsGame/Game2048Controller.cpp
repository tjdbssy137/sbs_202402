#include "pch.h"
#include "Game2048Controller.h"
#include "NumberBlockActor.h"
#include "BoxCollider.h"

void Game2048Controller::Init(vector<NumberBlockActor*> numberBlocks)
{
	_numberBlocks = numberBlocks;

	//��ġ �ʱ�ȭ
	//ResetIsFull();
	NumberBlockToZero();
	InitIsFull();
	//SumNumberBlocks();
	{
		for (NumberBlockActor* numberBlock : _numberBlocks)
		{
			cout << numberBlock->GetNumber() << endl;
		}
	}
}
void Game2048Controller::Update()
{
	
	{//�ѹ� ������ ���� ���� ������ ���� ��ȯ ���ϵ��� ����
		//������ �����¿� ���� -> �迭�� ������ 0 1 2 3 �� �ƴ϶� 0 4 8 12 ������??
		//									 4 5 6 8		  1 5 8 13
		
		if (Input->GetKeyDown(KeyCode::Down))
		{
			//numberBlock->ChangeDirectionState(NumberBlockDirState::Down);
			//cout << "hi" << endl; // 16�� ȣ���
			//��ĭ���� �̵���
			this->MoveRight();

			this->SumNumberBlocks();
			this->CheckCreateNumberBlock();
			this->CreateNumberBlock();
		}
		else if (Input->GetKeyDown(KeyCode::Up))
		{
			//numberBlock->ChangeDirectionState(NumberBlockDirState::Up);
			this->MoveLeft();
			this->SumNumberBlocks();
			this->CheckCreateNumberBlock();
			this->CreateNumberBlock();
		}
		else if (Input->GetKeyDown(KeyCode::Left))
		{
			//numberBlock->ChangeDirectionState(NumberBlockDirState::Left);
			this->MoveUp();
			this->SumNumberBlocks();
			this->CheckCreateNumberBlock();
			this->CreateNumberBlock();
		}
		else if (Input->GetKeyDown(KeyCode::Right))
		{
			//numberBlock->ChangeDirectionState(NumberBlockDirState::Right);
			this->MoveDown();
			this->SumNumberBlocks();
			this->CheckCreateNumberBlock();
			this->CreateNumberBlock();
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
	for (int i = 0; i < 2; i++)
	{
		int random = Random->GetRandomInt(0, 15);
		while(_numberBlocks[random]->GetNumber() != 0)//���ڸ� ã��
		{
			random = Random->GetRandomInt(0, 15);
		}
		_numberBlocks[random]->SetNumber(2);
		_numberBlocks[random]->ChangeImage(_numberBlocks[random]->GetNumber());
	}
}

void Game2048Controller::MoveDown()
{
	for (int i = 0; i < 12; i++)
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
	for (int i = MAX_BLOCK_COUNT - 1; 4 <= i ; i--)
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
	for (int i = MAX_BLOCK_COUNT - 1; 0 <= i; i--)
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
	if (_checkCreateNumberBlock == true)
	{
		// ����ִ��ڸ�ã��
		int random = Random->GetRandomInt(0, 15);
		while (_isFull[random] != 0)
		{
			random = Random->GetRandomInt(0, 15);
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
		_checkCreateNumberBlock = false;
	}

}
void Game2048Controller::CheckCreateNumberBlock()
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
		_checkCreateNumberBlock = false;
		//game over
	}
	else
	{
		_checkCreateNumberBlock = true;
	}

}