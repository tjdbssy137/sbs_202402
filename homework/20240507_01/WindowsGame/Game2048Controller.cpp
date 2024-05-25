#include "pch.h"
#include "Game2048Controller.h"
#include "NumberBlockActor.h"
#include "BoxCollider.h"
#include "Scene.h"

void Game2048Controller::Init(vector<NumberBlockActor*> numberBlocks)
{
	_numberBlocks = numberBlocks;
	//위치 초기화
	NumberBlockToZero();
	InitIsFull();

	for (int i = 0; i < 16; i++)
	{
		NumberBlockActor* tempBlock = new NumberBlockActor();
		tempBlock->Init();
		_tempNumberBlocks.push_back(tempBlock);
		CurrentScene->SpawnActor(_tempNumberBlocks.back());
	}
}
void Game2048Controller::Update()
{	
	if(_gameState == Game2048State::Release)
	{
		//왜인지 상하좌우 반전 -> 배열의 방향이 0 1 2 3 이 아니라 0 4 8 12 임
		//									 4 5 6 8		  1 5 8 13
		if (Input->GetKeyDown(KeyCode::Down))
		{
			// 한 줄(4개)이 모두 같은 숫자면 합쳐지지 않고 전부 삭제 됨. -> 왤까..
			// 네개가 합쳐지면서 전부 10000을 갖게 되고 그래서 또 합쳐짐. 2222->88이 아니라 16이 됨
			// 2번 키를 누를 때 동안 안 보임. -> 20000을 뺼 수 없어서 10000을 2턴 동안 빼기 때문임
			this->SetPressKeyState(PressKey::Down);
		}
		else if (Input->GetKeyDown(KeyCode::Up))
		{
			this->SetPressKeyState(PressKey::Up);
		}
		else if (Input->GetKeyDown(KeyCode::Left))
		{
			this->SetPressKeyState(PressKey::Left);
		}
		else if (Input->GetKeyDown(KeyCode::Right))
		{
			this->SetPressKeyState(PressKey::Right);
		}
	}
	else if (_gameState == Game2048State::Animation)
	{
		// 몇초뒤 다시 GS_RELEAS로 변경
		_time -= Time->GetDeltaTime();
		if (_time <= 0)
		{
			this->SumNumberBlocks();
			this->CheckCreateNumberBlock();
			this->CreateNumberBlock();
			this->SetGame2048State(Game2048State::Release);
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
		while (_numberBlocks[random]->GetNumber() != 0)//빈자리 찾기
		{
			random = Random->GetRandomInt(0, 15);
		}
		_numberBlocks[random]->SetNumber(2);
		_numberBlocks[random]->ChangeImage(_numberBlocks[random]->GetNumber());
	}
	/*
	_numberBlocks[3]->SetNumber(4);
	_numberBlocks[3]->ChangeImage(_numberBlocks[3]->GetNumber());
	_numberBlocks[11]->SetNumber(4);
	_numberBlocks[11]->ChangeImage(_numberBlocks[11]->GetNumber());
	_numberBlocks[13]->SetNumber(4);
	_numberBlocks[13]->ChangeImage(_numberBlocks[13]->GetNumber());
	// 처음에는 무조건 잘 됨 -> Temp를 update에서 init해서 생겼던 문제 같음. 그래서 처음엔 잘되고 그 이후로 꼬인듯???
	*/
}
void Game2048Controller::SetGame2048State(Game2048State gameState)
{
	_gameState = gameState;

	switch (gameState)
	{
	case Game2048State::Release:
	{
		for (NumberBlockActor* _tempNumberBlock : _tempNumberBlocks)
		{
			_tempNumberBlock->SetMoveCount(0);
			_tempNumberBlock->ChangeImage(0);
		}
	}
		break;
	case Game2048State::Animation:
	{
		_time = RELEASE_TIME;
		//잠시 원본 블럭을 지움
		for (NumberBlockActor* _numberBlock : _numberBlocks)
		{
			_numberBlock->ChangeImage(0);
		}
		
		//임시 애니메이션 블럭 생성 및 이동
		for (int i = 0; i < 16; i++)
		{
			{			
				int posX = (i / 4) * 100 - 200;
				int posY = (i % 4) * 100 - 200;
				_tempNumberBlocks[i]->SetPos(Vector2(posX, posY));
				_tempNumberBlocks[i]->SetNumber(_numberBlocks[i]->GetNumber());
				_tempNumberBlocks[i]->ChangeImage(_numberBlocks[i]->GetNumber());
			}
		}

		cout << "\n_tempNumberBlocks" << endl;
		for (int i = 0; i < 16; i++)
		{
			cout << _tempNumberBlocks[i]->GetNumber() << " ";
		}
	}
		break;
	case Game2048State::None:
	{
		GET_SINGLE(SceneManager)->ChangeScene(SceneType::Dev2Scene);
		break;
	}
	default:
		break;
	}
}

void Game2048Controller::SetPressKeyState(PressKey state)
{
	_state = state;
	this->SetGame2048State(Game2048State::Animation);
	switch (state)
	{
	case PressKey::Down:
	{
		this->MoveDown();
		for (NumberBlockActor* _tempBlock : _tempNumberBlocks)
		{
			_tempBlock->ChangeDirectionState(NumberBlockDirState::Down);
		}
	}
		break;
	case PressKey::Up:
	{
		this->MoveUp();
		for (NumberBlockActor* _tempBlock : _tempNumberBlocks)
		{
			_tempBlock->ChangeDirectionState(NumberBlockDirState::Up);
		}
	}
		break;
	case PressKey::Left:
	{
		this->MoveLeft();
		for (NumberBlockActor* _tempBlock : _tempNumberBlocks)
		{
			_tempBlock->ChangeDirectionState(NumberBlockDirState::Left);
		}
	}
		break;
	case PressKey::Right:
	{
		this->MoveRight();
		for (NumberBlockActor* _tempBlock : _tempNumberBlocks)
		{
			_tempBlock->ChangeDirectionState(NumberBlockDirState::Right);
		}
	}
		break;
	default:
		break;
	}
	this->SubtractTenThousand();
	
}

void Game2048Controller::MoveRight()
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
							_isMove = true;
							_tempNumberBlocks[(i * 4 + j % 4) - 4]->AddMoveCount();
						}
						else if(_blocksInfo[k][j] == _blocksInfo[k - 1][j])
						{
							_blocksInfo[k][j] += _blocksInfo[k - 1][j];
							_gameScore += _blocksInfo[k][j]; // 점수
							_blocksInfo[k][j] += 20000;
							_blocksInfo[k - 1][j] = 0;
							_isMove = true; // 이동했는지
							_tempNumberBlocks[(i * 4 + j % 4) - 4]->AddMoveCount();
						}
					}
				}
			}
			else if (_blocksInfo[i][j] == _blocksInfo[i - 1][j])
			{
				_blocksInfo[i][j] += _blocksInfo[i - 1][j];
				_gameScore += _blocksInfo[i][j];
				_blocksInfo[i][j] += 10000;
				_blocksInfo[i - 1][j] = 0;
				_isMove = true;
				_tempNumberBlocks[(i * 4 + j % 4) - 4]->AddMoveCount();
			}
		}
	}
}
void Game2048Controller::MoveLeft()
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
							_isMove = true;
							_tempNumberBlocks[(i * 4 + j % 4) + 4]->AddMoveCount();
						}
						else if (_blocksInfo[k][j] == _blocksInfo[k + 1][j])
						{
							_blocksInfo[k][j] += _blocksInfo[k + 1][j];
							_gameScore += _blocksInfo[k][j];
							_blocksInfo[k][j] += 20000;
							_blocksInfo[k + 1][j] = 0;
							_isMove = true;
							_tempNumberBlocks[(i * 4 + j % 4) + 4]->AddMoveCount();
						}
					}
				}
			}
			else if (_blocksInfo[i][j] == _blocksInfo[i + 1][j])
			{
				_blocksInfo[i][j] += _blocksInfo[i + 1][j];
				_gameScore += _blocksInfo[i][j];
				_blocksInfo[i][j] += 10000;
				_blocksInfo[i + 1][j] = 0;
				_isMove = true;
				_tempNumberBlocks[(i * 4 + j % 4) + 4]->AddMoveCount();
			}
		}
	}
}
void Game2048Controller::MoveUp()
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
							_isMove = true;
							_tempNumberBlocks[(i * 4 + j % 4) + 1]->AddMoveCount();
						}
						else if (_blocksInfo[i][k] == _blocksInfo[i][k + 1])
						{
							_blocksInfo[i][k] += _blocksInfo[i][k + 1];
							_gameScore += _blocksInfo[i][k];
							_blocksInfo[i][k] += 20000;
							_blocksInfo[i][k + 1] = 0;
							_isMove = true;
							_tempNumberBlocks[(i * 4 + j % 4) + 1]->AddMoveCount();
						}
					}
				}
			}
			else if (_blocksInfo[i][j] == _blocksInfo[i][j + 1])
			{
				_blocksInfo[i][j] += _blocksInfo[i][j + 1];
				_gameScore += _blocksInfo[i][j];
				_blocksInfo[i][j] += 10000;
				_blocksInfo[i][j + 1] = 0;
				_isMove = true;
				_tempNumberBlocks[(i * 4 + j % 4) + 1]->AddMoveCount();
			}
		}
	}
}
void Game2048Controller::MoveDown()
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
							_isMove = true;
							_tempNumberBlocks[(i * 4 + j % 4) - 1]->AddMoveCount();
						}
						else if (_blocksInfo[i][k] == _blocksInfo[i][k - 1])
						{
							_blocksInfo[i][k] += _blocksInfo[i][k - 1];
							_gameScore += _blocksInfo[i][k];
							_blocksInfo[i][k] += 20000;
							_blocksInfo[i][k - 1] = 0;
							_isMove = true;
							_tempNumberBlocks[(i * 4 + j % 4) - 1]->AddMoveCount();
						}
					}
				}
			}
			else if (_blocksInfo[i][j] == _blocksInfo[i][j - 1])
			{
				_blocksInfo[i][j] += _blocksInfo[i][j - 1];
				_gameScore += _blocksInfo[i][j];
				_blocksInfo[i][j] += 10000;
				_blocksInfo[i][j - 1] = 0;
				_isMove = true;
				_tempNumberBlocks[(i * 4 + j % 4) - 1]->AddMoveCount();
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
			_blocksInfo[i / 4][i % 4] %= 10000;
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
		_isMove = false;
	}

	cout << "\n_numberBlocks" << endl;
	for (int i = 0; i < 16; i++)
	{
		cout << _numberBlocks[i]->GetNumber() << " ";
	}
	cout << "\n_blocksInfo" << endl;
	for (int i = 0; i < 16; i++)
	{
		cout << _blocksInfo[i / 4][i % 4] << " ";
	}
}
void Game2048Controller::CheckCreateNumberBlock()
{
	int count = 0;
	if(_isMove == true)
	//이동을 한 경우에만 생성 여부 체크
	{
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
			//game over
			_checkCreateNumberBlock = false;
			SetGame2048State(Game2048State::None);
		}
		else //if (count < 16)
		{
			_checkCreateNumberBlock = true;
		}
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