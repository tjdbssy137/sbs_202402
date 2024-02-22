#include <iostream>
#include <time.h>
using namespace std;

int _attack = 3;
int _upgradeAttck = 1;
int _hp = 100;
int _x = 0;
int _y = 0;
int moveCount = 0;
int _monsterHp = 0;
int _monsterAttack = 0;
int _bossMonsterHp = 0;
int _bossMonsterAttack = 0;
bool _goal = 0;
bool _end = 0;
int input;
int _attckRandom = 0;

int monster = 0;
int player = 0;

int judge() {
	monster = rand() % 3;
	while (1)
	{
		cout << "����(0)����(1)��(2)�� �Է��ϼ��� >> ";
		cin >> player;
		if (player >= 0 && player < 3) break;
	}

	if (player > monster || (player == 0 && monster == 2))
	{
		cout << "���ݱ��� �����Խ��ϴ�." << endl;
		return 0;
	}
	else if ((player == 2 && monster == 0) || (player < monster))
	{
		cout << "���ݱ��� ���Ұ���ϴ�." << endl;
		return 1;
	}
	else if (player == monster)
	{
		cout << "�ٽ� ������������ �ؾ��մϴ�." << endl;
		return 2;
	}
}

void GameEnd(int hp) {
	if (hp > 0)
	{
		printf(" _____________________________________\n");
		printf("|                                     |\n");
		printf("|             ~~THE END~~             |\n");
		printf("|_____________________________________|\n");
	}
	else
	{
		printf(" _____________________________________\n");
		printf("|                                     |\n");
		printf("|             try again...            |\n");
		printf("|_____________________________________|\n");
		_end = 1;
	}
}
void BattleBossMonster() {
	_bossMonsterHp = 50;
	cout << "|| system || ���� ���Ϳ� �����ƽ��ϴ�." << endl;

	while (_hp > 0 && _bossMonsterHp > 0)
	{
		switch (judge()) 
		{
			case 0:
				_attckRandom = rand() % _attack + _upgradeAttck;
				cout << "���� ���͸� " << _attckRandom << "��ŭ �����߽��ϴ�.." << endl;
				_bossMonsterHp -= _attckRandom;
				if (_bossMonsterHp <= 0)
				{
					cout << "���� ���͸� óġ�߽��ϴ�." << endl;
					cout << "���� : 20HP ġ��, ���ݷ� 5 ����... ����� HP : ";
					_hp + 20 > 100 ? _hp = 100 : _hp += 20;
					cout << _hp << endl;
					_upgradeAttck += 5;
				}
				else
					cout << "���� ������ ���� ü����.. " << _bossMonsterHp << endl;
				break;
		case 1:
			_bossMonsterAttack = rand() % 6 + 15;
			cout << "���� ���Ͱ� ����� " << _bossMonsterAttack << "��ŭ �����߽��ϴ�" << endl;
			_hp -= _bossMonsterAttack;
			cout << "����� ���� ü����.. " << _hp << endl;
			break;
		case 2:
			break;
		}
	}
	if (_hp < 0) GameEnd(_hp);
}
void BattleMonster()
{
	_monsterHp = rand() % 5 + 6;
	cout << "|| system || ���Ϳ� �����ƽ��ϴ�." << endl;
	
	while (_hp > 0 && _monsterHp > 0)
	{
		switch(judge())
		{
		case 0:
			_attckRandom = rand() % _attack + _upgradeAttck;
			cout << "���͸� " << _attckRandom << "��ŭ �����߽��ϴ�.." << endl;
			_monsterHp -= _attckRandom;
			if (_monsterHp <= 0) 
			{
				cout << "���͸� óġ�߽��ϴ�." << endl;
				cout << "���� : 10HP ġ��, ���ݷ� 2 ����... ����� HP : ";
				_hp + 10 > 100 ? _hp = 100 : _hp += 10;
				cout << _hp << endl;
				_upgradeAttck += 2;
			}
			else 
				cout << "������ ���� ü����.. " << _monsterHp << endl;
			break;
		case 1:
			_monsterAttack = rand() % 9 + 1;
			cout << "���Ͱ� ����� " << _monsterAttack << "��ŭ �����߽��ϴ�" << endl;
			_hp -= _monsterAttack;
			cout << "����� ���� ü����.. " << _hp << endl;
			break;
		case 2:
			break;
		}
	}
	if (_hp < 0) GameEnd(_hp);
}
void MovePlayer()
{
	cout << "�÷��̾ ������ ������ ����ּ��� (0 : ��, 1 : ��, 2 : ��, 3 : ��)" << endl;
	cout << "���� ����� ��ġ�� x(" << _x << "), y(" << _y << ")" << endl;
	cin >> input;
	switch (input) {
	case 0:
		_y++;
		break;
	case 1:
		_y--;
		break;
	case 2:
		_x--;
		break;
	case 3:
		_x++;
		break;
	default:
		break;
	}
	if (_x == 1 && _y == 1) BattleBossMonster();
	else if (_x == 2 && _y == 1) _goal = 1;
	else BattleMonster();
	moveCount++;
}
void PrintGameStartScene()
{
	printf(" _____________________________________\n");
	printf("|                                     |\n");
	printf("|             Game Start              |\n");
	printf("|_____________________________________|\n");
}

void main() {
	PrintGameStartScene();
	while (moveCount < 5)
	{
		MovePlayer();
		if (_end) break;
	}
	if (moveCount >= 5 || _goal)GameEnd(_hp);
}