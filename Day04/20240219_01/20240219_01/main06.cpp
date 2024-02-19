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
	cout << "몬스터와 마주쳤습니다." << endl;
	//while문 사용
	while (_monsterHp > 0 && _hp > 0) {
		cout << "몬스터를 가격했습니다" << endl;
		_monsterHp -= _attack;
		cout << "system : 몬스터의 남은 체력은.. " << _monsterHp << endl;

		cout << "몬스터를 가격했습니다" << endl;
		_hp -= _attack;

	}
}
void MovePlayer() 
{
	cout << "플레이어가 움직일 방향을 골라주세요 (0 : 북, 1 : 남, 2 : 서, 3 : 동)" << endl;
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