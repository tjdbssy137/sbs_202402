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

int _Heal = 10;


enum Hand
{
	_scissors, // 0
	_rock, // 1
	_paper // 2
};

int judge() {
	monster = rand() % 3;
	while (1)
	{
		cout << "가위(0)바위(1)보(2)를 입력하세요 >> ";
		cin >> player;
		if (0 <= player && player < 3) break;
	}
	int _answer;
	if (player == _rock)
	{
		if (monster == _rock)
		{
			_answer = 2;
		}
		else if (monster == _scissors)
		{
			_answer = 0;
		}
		else
		{
			_answer = 1;
		}
	}
	else if (player == _scissors)
	{
		if (monster == _rock)
		{
			_answer = 1;
		}
		else if (monster == _scissors)
		{
			_answer = 2;
		}
		else
		{
			_answer = 0;
		}
	}
	else
	{
		if (monster == _rock)
		{
			_answer = 0;
		}
		else if (monster == _scissors)
		{
			_answer = 1;
		}
		else
		{
			_answer = 2;
		}
	}
	switch (_answer)
	{
		case 0:
			cout << "공격권을 가져왔습니다." << endl;
			return 0;
			break;
		case 1:
			cout << "공격권을 빼았겼습니다." << endl;
			return 1;
			break;
		default:
			cout << "다시 가위바위보를 해야합니다." << endl;
			return 2;
			break;
	}
}

void GameEnd(int hp) {
	if (0 < hp)
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
	cout << "|| system || 보스 몬스터와 마주쳤습니다." << endl;

	while (0 < _hp && 0 < _bossMonsterHp)
	{
		switch (judge()) 
		{
			case 0:
				_attckRandom = rand() % _attack + _upgradeAttck;
				cout << "보스 몬스터를 " << _attckRandom << "만큼 가격했습니다.." << endl;
				_bossMonsterHp -= _attckRandom;
				if (_bossMonsterHp <= 0)
				{
					cout << "보스 몬스터를 처치했습니다." << endl;
					cout << "보상 : "<< _Heal*2 <<"HP 치유, 공격력 5 증가... 당신의 HP : ";
					100 < _hp + _Heal * 2 ? _hp = 100 : _hp += _Heal * 2;
					cout << _hp << endl;
					_upgradeAttck += 5;
				}
				else
					cout << "보스 몬스터의 남은 체력은.. " << _bossMonsterHp << endl;
				break;
		case 1:
			_bossMonsterAttack = rand() % 6 + 15;
			cout << "보스 몬스터가 당신을 " << _bossMonsterAttack << "만큼 가격했습니다" << endl;
			_hp -= _bossMonsterAttack;
			cout << "당신의 남은 체력은.. " << _hp << endl;
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
	cout << "|| system || 몬스터와 마주쳤습니다." << endl;
	
	while (0 < _hp &&  0 < _monsterHp)
	{
		switch(judge())
		{
		case 0:
			_attckRandom = rand() % _attack + _upgradeAttck;
			cout << "몬스터를 " << _attckRandom << "만큼 가격했습니다.." << endl;
			_monsterHp -= _attckRandom;
			if (_monsterHp <= 0) 
			{
				cout << "몬스터를 처치했습니다." << endl;
				cout << "보상 : "<< _Heal <<"HP 치유, 공격력 2 증가... 당신의 HP : ";
				100 < _hp + _Heal ? _hp = 100 : _hp += _Heal;
				cout << _hp << endl;
				_upgradeAttck += 2;
			}
			else 
				cout << "몬스터의 남은 체력은.. " << _monsterHp << endl;
			break;
		case 1:
			_monsterAttack = rand() % 9 + 1;
			cout << "몬스터가 당신을 " << _monsterAttack << "만큼 가격했습니다" << endl;
			_hp -= _monsterAttack;
			cout << "당신의 남은 체력은.. " << _hp << endl;
			break;
		case 2:
			break;
		}
	}
	if (_hp < 0) GameEnd(_hp);
}
void MovePlayer()
{
	cout << "플레이어가 움직일 방향을 골라주세요 (0 : 북, 1 : 남, 2 : 서, 3 : 동)" << endl;
	cout << "현재 당신의 위치는 x(" << _x << "), y(" << _y << ")" << endl;
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
	if (_x == 1 && _y == 1)
	{
		BattleBossMonster();
	}
	else if (_x == 2 && _y == 1)
	{
		_goal = 1;
	}
	else
	{
		BattleMonster();
	}
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