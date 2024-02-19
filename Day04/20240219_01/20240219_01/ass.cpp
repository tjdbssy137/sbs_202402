#include <iostream>
#include <time.h>
using namespace std;

// 숙제2
// TEXT RPG 만들기
// Attack, HP, X = 0, Y = 0가 있음

// 1. 게임이 시작하면 상하좌우로 이동할 수 있다.
// 2. 한 칸 움직일 때마다 방에 입장한다
// 3. 방에서는 몬스터와 마주치는데,
// 4. 몬스터의 공격력은 1~10 사이(랜덤), HP는 5~10 사이. (방에 들어가면 몬스터의 공격력과 체력이 지정)
// 5. 몬스터와 내가 한 대씩 때린다
// 6. 몬스터가 죽으면 다른 방으로 이동할 수 있다
// 7. 방을 5번 움직이거나 x = 2, y =1 방으로 가면 게임이 클리어 된다
// 8. x = 1, y = 1 방은 보스방
// 9. 보스의 능력치는 hp = 50, attack = 20
// 10. 그전에 내가 죽으면 게임이 끝난다 

int _attack = 4;
int _upgradeAttck = 0;
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

void GameEnd(int hp) {
	if (hp > 0) cout << "~~THE END~~" << endl;
	else
	{
		cout << "try again..." << endl;
		_end = 1;
	}
}
void BattleBossMonster() {
	_bossMonsterHp = 50;
	cout << "|| system || 보스 몬스터와 마주쳤습니다." << endl;
	while (_hp > 0)
	{
		_attckRandom = rand() % _attack + _upgradeAttck;
		cout << "보스 몬스터를 " << _attckRandom << "만큼 가격했습니다.." << endl;
		_bossMonsterHp -= _attckRandom;
		if (_bossMonsterHp < 0)
		{
			cout << "보스 몬스터를 처치했습니다." << endl;
			cout << "보상 : 20HP 치유, 공격력 3 증가... 당신의 HP : " << _hp + 20 << endl;
			_upgradeAttck += 3;
			break;
		}
		cout << "보스 몬스터의 남은 체력은.. " << _bossMonsterHp << endl;

		_bossMonsterAttack = rand() % 6 + 15;
		cout << "보스 몬스터가 당신을 " << _bossMonsterAttack << "만큼 가격했습니다" << endl;
		_hp -= _bossMonsterAttack;
		cout << "당신의 남은 체력은.. " << _hp << endl;
	}
	if (_hp < 0) GameEnd(_hp);
}
void BattleMonster()
{
	_monsterHp = rand() % 5 + 6;
	cout << "|| system || 몬스터와 마주쳤습니다." << endl;
	while (_hp > 0)
	{
		_attckRandom = rand() % _attack + _upgradeAttck;
		cout << "몬스터를 " << _attckRandom << "만큼 가격했습니다.." << endl;
		_monsterHp -= rand() % _attack + _upgradeAttck;
		if (_monsterHp < 0) {
			cout << "몬스터를 처치했습니다." << endl;
			cout << "보상 : 10HP 치유, 공격력 1 증가... 당신의 HP : " << _hp + 10 << endl;
			_upgradeAttck++;
			break;
		}
		cout << "몬스터의 남은 체력은.. " << _monsterHp << endl;

		_monsterAttack = rand() % 9 + 1;
		cout << "몬스터가 당신을 " << _monsterAttack << "만큼 가격했습니다" << endl;
		_hp -= _monsterAttack;
		cout << "당신의 남은 체력은.. " << _hp << endl;
	}
	if (_hp < 0) GameEnd(_hp);
}
void MovePlayer()
{
	cout << "플레이어가 움직일 방향을 골라주세요 (0 : 북, 1 : 남, 2 : 서, 3 : 동)" << endl;
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
	cout << "당신의 위치는 x(" << _x << "), y(" << _y << ")" << endl;
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