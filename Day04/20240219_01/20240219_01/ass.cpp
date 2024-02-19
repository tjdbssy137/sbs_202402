#include <iostream>
#include <time.h>
using namespace std;

// ����2
// TEXT RPG �����
// Attack, HP, X = 0, Y = 0�� ����

// 1. ������ �����ϸ� �����¿�� �̵��� �� �ִ�.
// 2. �� ĭ ������ ������ �濡 �����Ѵ�
// 3. �濡���� ���Ϳ� ����ġ�µ�,
// 4. ������ ���ݷ��� 1~10 ����(����), HP�� 5~10 ����. (�濡 ���� ������ ���ݷ°� ü���� ����)
// 5. ���Ϳ� ���� �� �뾿 ������
// 6. ���Ͱ� ������ �ٸ� ������ �̵��� �� �ִ�
// 7. ���� 5�� �����̰ų� x = 2, y =1 ������ ���� ������ Ŭ���� �ȴ�
// 8. x = 1, y = 1 ���� ������
// 9. ������ �ɷ�ġ�� hp = 50, attack = 20
// 10. ������ ���� ������ ������ ������ 

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
	cout << "|| system || ���� ���Ϳ� �����ƽ��ϴ�." << endl;
	while (_hp > 0)
	{
		_attckRandom = rand() % _attack + _upgradeAttck;
		cout << "���� ���͸� " << _attckRandom << "��ŭ �����߽��ϴ�.." << endl;
		_bossMonsterHp -= _attckRandom;
		if (_bossMonsterHp < 0)
		{
			cout << "���� ���͸� óġ�߽��ϴ�." << endl;
			cout << "���� : 20HP ġ��, ���ݷ� 3 ����... ����� HP : " << _hp + 20 << endl;
			_upgradeAttck += 3;
			break;
		}
		cout << "���� ������ ���� ü����.. " << _bossMonsterHp << endl;

		_bossMonsterAttack = rand() % 6 + 15;
		cout << "���� ���Ͱ� ����� " << _bossMonsterAttack << "��ŭ �����߽��ϴ�" << endl;
		_hp -= _bossMonsterAttack;
		cout << "����� ���� ü����.. " << _hp << endl;
	}
	if (_hp < 0) GameEnd(_hp);
}
void BattleMonster()
{
	_monsterHp = rand() % 5 + 6;
	cout << "|| system || ���Ϳ� �����ƽ��ϴ�." << endl;
	while (_hp > 0)
	{
		_attckRandom = rand() % _attack + _upgradeAttck;
		cout << "���͸� " << _attckRandom << "��ŭ �����߽��ϴ�.." << endl;
		_monsterHp -= rand() % _attack + _upgradeAttck;
		if (_monsterHp < 0) {
			cout << "���͸� óġ�߽��ϴ�." << endl;
			cout << "���� : 10HP ġ��, ���ݷ� 1 ����... ����� HP : " << _hp + 10 << endl;
			_upgradeAttck++;
			break;
		}
		cout << "������ ���� ü����.. " << _monsterHp << endl;

		_monsterAttack = rand() % 9 + 1;
		cout << "���Ͱ� ����� " << _monsterAttack << "��ŭ �����߽��ϴ�" << endl;
		_hp -= _monsterAttack;
		cout << "����� ���� ü����.. " << _hp << endl;
	}
	if (_hp < 0) GameEnd(_hp);
}
void MovePlayer()
{
	cout << "�÷��̾ ������ ������ ����ּ��� (0 : ��, 1 : ��, 2 : ��, 3 : ��)" << endl;
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
	cout << "����� ��ġ�� x(" << _x << "), y(" << _y << ")" << endl;
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