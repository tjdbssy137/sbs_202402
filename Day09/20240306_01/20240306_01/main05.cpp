#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Character {
	string Name;
	int HP;
	int Attack;

	// void print(); 전방선언 가능
	void print(int test) // 파라메터 사용 가능.
	{
		cout << "Name : " << Name << endl;
		cout << "HP : " << HP << endl;
		cout << "ATTACK : " << Attack << endl;
		cout << "test : " << test;
	}
};

/* 
void Character::Print() //로 함수 구현 가능.
{	
	cout << "Name : " << Name << endl;
	cout << "HP : " << HP << endl;
	cout << "ATTACK : " << Attack << endl;
}
*/
vector<Character> VectorArray;

void ChooseCharcter();
void PrintCharacter();
void main()
{
	// 구조체
	
	// 캐릭터 구조체
	// - 다마고치
	//		- 캐릭터 이름
	//		- HP
	//		- ATTACK
	
	// 캐릭터 선택창
	// 각 스탯들을 입력 받을 수 있게 끔 만듦.
	ChooseCharcter();
	//PrintCharacter();
	// 구조체 함수
	// 구조체 내부에 함수 선언 가능.
	
	// 캐릭터 정보를 출력하고 싶다.
	//
}
void ChooseCharcter()
{
	Character character;
	cout << "다마고치의 이름을 입력해주세요 : ";
	getline(cin, character.Name);
	cout << "다마고치의 HP을 입력해주세요 : ";
	cin >> character.HP;
	cout << "다마고치의 Attack을 입력해주세요 : ";
	cin >> character.Attack;
	VectorArray.push_back(character);

	character.print(5);
}
void PrintCharacter()
{
	for (int i = 0; i < VectorArray.size(); i++)
	{
		cout << "Name : " << VectorArray[i].Name << endl;
		cout << "HP : " << VectorArray[i].HP << endl;
		cout << "ATTACK : " << VectorArray[i].Attack << endl;
	}
}