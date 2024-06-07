#include "pch.h"
#include "Board.h"
#include "Player.h"
void Board::Init(int size, Player* player)
{
	_player = player;
	_size = size;

	_exitPos = { _size - 2, _size - 2 };
	for (int y = 0; y < _size; y++)
	{
		vector<TileType> lines;
		for (int x = 0; x < _size; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
			{
				lines.push_back(TileType::WALL);
			}
			else
			{
				lines.push_back(TileType::EMPTY);
			}
		}
		_tiles.push_back(lines);
	}


	for (int y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			//�ʷϻ� ���� ���� Ȯ��
			if (x % 2 == 0 || y % 2 == 0)
			{
				continue;
			}

			//��ǥ�������� Ȯ��
			if (y == _size - 2 && x == _size - 2)
			{
				continue;
			}

			//�ϴܿ� �����ߴ��� Ȯ��
			if (y == _size - 2)
			{
				_tiles[y][x + 1] = TileType::EMPTY;
				continue;
			}

			//������ �����ߴ��� Ȯ��
			if (x == _size - 2)
			{
				_tiles[y + 1][x] = TileType::EMPTY;
				continue;
			}

			int randValue = rand() % 2;
			if (randValue == 0)
			{
				_tiles[y][x + 1] = TileType::EMPTY;
			}
			else if (randValue == 1)
			{
				_tiles[y + 1][x] = TileType::EMPTY;
			}
		}
	}

	//�̷� ����

}
void Board::Render()
{
	ConsoleHelper::SetCursorPosition(0, 0);
	for (int y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			if (this->GetExitPos() == Vector2Int{x, y})
			{
				ConsoleHelper::SetCursorColor(ConsoleColor::BLUE, ConsoleColor::BLACK);
				cout << TILE;
			}
			else if (_player->GetPos() == Vector2Int{ x, y })
			{
				ConsoleHelper::SetCursorColor(ConsoleColor::YELLOW, ConsoleColor::BLACK);
				cout << TILE;
			}
			else if (this->GetEnterPos() == Vector2Int{ x, y })
			{
				ConsoleHelper::SetCursorColor(ConsoleColor::MAGENTA, ConsoleColor::BLACK);
				cout << TILE;
			}
			else
			{
				switch (_tiles[y][x])
				{
				case TileType::EMPTY:
					ConsoleHelper::SetCursorColor(ConsoleColor::GREEN, ConsoleColor::BLACK);
					cout << TILE;
					break;
				case TileType::WALL:
					ConsoleHelper::SetCursorColor(ConsoleColor::RED, ConsoleColor::BLACK);
					cout << TILE;
					break;
				}
			}
			 
		}
		cout << endl;
	}
}

bool Board::CanGo(Vector2Int pos)
{
	return _tiles[pos.y][pos.x] == TileType::EMPTY;
}