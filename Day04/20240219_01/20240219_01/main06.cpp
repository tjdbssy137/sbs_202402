#include <iostream>
#include <time.h>
using namespace std;

int _attack = 4;
int _hp = 100;
int _x = 0;
int _y = 0;
int moveCnt = 0;
int _monsterHp = 0; // 1~ 10 random
int _monsterAttack = 0; // 5 ~ 10 random 

int input;
void BattleMonster()
{
	cout << "���Ϳ� �����ƽ��ϴ�." << endl;
	//while�� ���
	while (_monsterHp > 0 && _hp > 0) {
		cout << "���͸� �����߽��ϴ�" << endl;
		_monsterHp -= _attack;
		cout << "system : ������ ���� ü����.. " << _monsterHp << endl;

		cout << "���͸� �����߽��ϴ�" << endl;
		_hp -= _attack;

	}
}
void MovePlayer() 
{
	cout << "�÷��̾ ������ ������ ����ּ��� (0 : ��, 1 : ��, 2 : ��, 3 : ��)" << endl;
	cin >> input;
	moveCnt++;
}
void PrintGameStartScene()
{
	printf(" _____________________________________\n");
	printf("|                                     |\n");
	printf("|             Game Start              |\n");
	printf("|_____________________________________|\n");
}
void main()
{
	srand(time(NULL));
	while(moveCnt < 5)
	{
		PrintGameStartScene();
	}
	

}