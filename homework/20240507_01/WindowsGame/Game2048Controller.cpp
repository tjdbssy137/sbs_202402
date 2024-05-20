#include "pch.h"
#include "Game2048Controller.h"
#include "NumberBlockActor.h"
#include "BoxCollider.h"

void Game2048Controller::Init(vector<NumberBlockActor*> numberBlocks)
{
	_numberBlocks = numberBlocks;

	//위치 초기화
	NumberBlockToZero();
	InitIsFull();
}
void Game2048Controller::Update()
{	
	{
		//왜인지 상하좌우 반전 -> 배열의 방향이 0 1 2 3 이 아니라 0 4 8 12 일지도??
		//									 4 5 6 8		  1 5 8 13
		
		if (Input->GetKeyDown(KeyCode::Down))
		{
			//numberBlock->ChangeDirectionState(NumberBlockDirState::Down);
			// 한 줄(4개)이 모두 같은 숫자면 합쳐지지 않고 전부 삭제 됨. -> 왤까..
			this->SetPressKeyState(PressKey::Down);
		}
		else if (Input->GetKeyDown(KeyCode::Up))
		{
			//numberBlock->ChangeDirectionState(NumberBlockDirState::Up);
			this->SetPressKeyState(PressKey::Up);
		}
		else if (Input->GetKeyDown(KeyCode::Left))
		{
			//numberBlock->ChangeDirectionState(NumberBlockDirState::Left);
			this->SetPressKeyState(PressKey::Left);
		}
		else if (Input->GetKeyDown(KeyCode::Right))
		{
			//numberBlock->ChangeDirectionState(NumberBlockDirState::Right);
			this->SetPressKeyState(PressKey::Right);
		}
	}
}

void Game2048Controller::InitIsFull()
{
	int count = 0;
	for (int i = 0; i < 4; i ++)
	{
		for (int j = 0; j < 4; j++)
		{
			_blocksInfo[i][j] = _numberBlocks[count++]->GetNumber();
		}
	}
}

void Game2048Controller::NumberBlockToZero()
{
	for (int i = 0; i < 2; i++)
	{
		int random = Random->GetRandomInt(0, 15);
		while(_numberBlocks[random]->GetNumber() != 0)//빈자리 찾기
		{
			random = Random->GetRandomInt(0, 15);
		}
		_numberBlocks[random]->SetNumber(2);
		_numberBlocks[random]->ChangeImage(_numberBlocks[random]->GetNumber());
	}
}

void Game2048Controller::SetPressKeyState(PressKey state)
{
	switch (state)
	{
	case Down: 
	{
		this->MoveRight();
		this->SubtractTenThousand();
		this->SumNumberBlocks();
		this->CheckCreateNumberBlock();
		this->CreateNumberBlock();
		this->SetPressKeyState(PressKey::None);
	}
		break;
	case Up:
	{
		this->MoveLeft();
		this->SubtractTenThousand();
		this->SumNumberBlocks();
		this->CheckCreateNumberBlock();
		this->CreateNumberBlock();
		this->SetPressKeyState(PressKey::None);
	}
		break;
	case Left:
	{
		this->MoveUp();
		this->SubtractTenThousand();
		this->SumNumberBlocks();
		this->CheckCreateNumberBlock();
		this->CreateNumberBlock();
		this->SetPressKeyState(PressKey::None);
	}
		break;
	case Right:
	{
		this->MoveDown();
		this->SubtractTenThousand();
		this->SumNumberBlocks();
		this->CheckCreateNumberBlock();
		this->CreateNumberBlock();
		this->SetPressKeyState(PressKey::None);
	}
		break;
	default:
		break;
	}
}

void Game2048Controller::MoveDown()
{
	for (int i = 3; 0 < i; i--)
	{
		for (int j = 0; j < 4; j++)
		{
			if (_blocksInfo[i][j] == 0)
			{
				if (_blocksInfo[i - 1][j] != 0)
				{
					for (int k = i; k < 4; k++)
					{
						if (_blocksInfo[k][j] == 0)
						{
							_blocksInfo[k][j] = _blocksInfo[k - 1][j];
							_blocksInfo[k - 1][j] = 0;
						}
						else if(_blocksInfo[k][j] == _blocksInfo[k - 1][j])
						{
							_blocksInfo[k][j] += _blocksInfo[k - 1][j];
							_blocksInfo[k][j] += 10000;
							_blocksInfo[k - 1][j] = 0;
						}
					}
				}
			}
			else if (_blocksInfo[i][j] == _blocksInfo[i - 1][j])
			{
				_blocksInfo[i][j] += _blocksInfo[i - 1][j];
				_blocksInfo[i][j] += 10000;
				_blocksInfo[i - 1][j] = 0;
				/*
				for (int k = i; 0 < k; k--)
				{
					if (_blocksInfo[k - 1][j] == 0)
					{
						_blocksInfo[k][j] = _blocksInfo[k - 1][j];
						_blocksInfo[k - 1][j] = 0;
					}
				}
				*/
			}
		}
	}
}
void Game2048Controller::MoveUp()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (_blocksInfo[i][j] == 0)
			{
				if (_blocksInfo[i + 1][j] != 0)
				{
					for (int k = i; 0 <= k; k--)
					{
						if (_blocksInfo[k][j] == 0)
						{
							_blocksInfo[k][j] = _blocksInfo[k + 1][j];
							_blocksInfo[k + 1][j] = 0;
						}
						else if (_blocksInfo[k][j] == _blocksInfo[k + 1][j])
						{
							_blocksInfo[k][j] += _blocksInfo[k + 1][j];
							_blocksInfo[k][j] += 10000;
							_blocksInfo[k + 1][j] = 0;
						}
					}
				}
			}
			else if (_blocksInfo[i][j] == _blocksInfo[i + 1][j])
			{
				_blocksInfo[i][j] += _blocksInfo[i + 1][j];
				_blocksInfo[i][j] += 10000;
				_blocksInfo[i + 1][j] = 0;
			}
		}
	}
}
void Game2048Controller::MoveLeft()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (_blocksInfo[i][j] == 0)
			{
				if (_blocksInfo[i][j + 1] != 0)
				{
					for (int k = j; 0 <= k; k--)
					{
						if (_blocksInfo[i][k] == 0)
						{
							_blocksInfo[i][k] = _blocksInfo[i][k + 1];
							_blocksInfo[i][k + 1] = 0;
						}
						else if (_blocksInfo[i][k] == _blocksInfo[i][k + 1])
						{
							_blocksInfo[i][k] += _blocksInfo[i][k + 1];
							_blocksInfo[i][k] += 10000;
							_blocksInfo[i][k + 1] = 0;
						}
					}
				}
			}
			else if (_blocksInfo[i][j] == _blocksInfo[i][j + 1])
			{
				_blocksInfo[i][j] += _blocksInfo[i][j + 1];
				_blocksInfo[i][j] += 10000;
				_blocksInfo[i][j + 1] = 0;
			}
		}
	}
}
void Game2048Controller::MoveRight()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; 0 < j; j--)
		{
			if (_blocksInfo[i][j] == 0)
			{
				if (_blocksInfo[i][j - 1] != 0)
				{
					for (int k = j; k < 4; k++)
					{
						if (_blocksInfo[i][k] == 0)
						{
							_blocksInfo[i][k] = _blocksInfo[i][k - 1];
							_blocksInfo[i][k - 1] = 0;
						}
						else if (_blocksInfo[i][k] == _blocksInfo[i][k - 1])
						{
							_blocksInfo[i][k] += _blocksInfo[i][k - 1];
							_blocksInfo[i][k] += 10000;
							_blocksInfo[i][k - 1] = 0;
						}
					}
				}
			}
			else if (_blocksInfo[i][j] == _blocksInfo[i][j - 1])
			{
				_blocksInfo[i][j] += _blocksInfo[i][j - 1];
				_blocksInfo[i][j] += 10000;
				_blocksInfo[i][j - 1] = 0;
			}
		}
	}
}

void Game2048Controller::SubtractTenThousand()
{
	for (int i = 0; i < MAX_BLOCK_COUNT; i++)
	{
		if (10000 < _blocksInfo[i / 4][i % 4])
		{
			_blocksInfo[i / 4][i % 4] -= 10000;
		}
	}
}
void Game2048Controller::SumNumberBlocks()
{
	for (int i = 0; i < MAX_BLOCK_COUNT; i++)
	{
		_numberBlocks[i]->SetNumber(_blocksInfo[i / 4][i % 4]);
		_numberBlocks[i]->ChangeImage(_numberBlocks[i]->GetNumber());
	}
}
void Game2048Controller::CreateNumberBlock()
{
	if (_checkCreateNumberBlock == true)
	{
		// 비어있는자리찾기
		int random = Random->GetRandomInt(0, 15);
		while (_blocksInfo[random / 4][random % 4] != 0)
		{
			random = Random->GetRandomInt(0, 15);
		}

		// 생성될 숫자 구하기
		switch (Random->GetRandomInt(1, 5))
		{
		case 1 : // 4는 20%로 생성
		{
			_blocksInfo[random / 4][random % 4] = 4;
			_numberBlocks[random]->SetNumber(_blocksInfo[random / 4][random % 4]);
			_numberBlocks[random]->ChangeImage(_numberBlocks[random]->GetNumber());
		}
		break;
		default:
		{
			_blocksInfo[random / 4][random % 4] = 2;
			_numberBlocks[random]->SetNumber(_blocksInfo[random / 4][random % 4]);
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
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
		{
			if (_blocksInfo[i][j] != 0)
			{
				count++;
			}
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

int** Game2048Controller::ReverseArray(int inputArray[][4], int rows)
{
	int** temp = new int* [rows];
	for (int i = 0; i < rows; i++) {
		temp[i] = new int[4];
		for (int j = 0; j < 4; j++) {
			temp[i][j] = inputArray[j][i];
		}
	}
	return temp;
}