#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Character {
	string Name;
	int HP;
	int Attack;

	// void print(); ���漱�� ����
	void print(int test) // �Ķ���� ��� ����.
	{
		cout << "Name : " << Name << endl;
		cout << "HP : " << HP << endl;
		cout << "ATTACK : " << Attack << endl;
		cout << "test : " << test;
	}
};

/* 
void Character::Print() //�� �Լ� ���� ����.
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
	// ����ü
	
	// ĳ���� ����ü
	// - �ٸ���ġ
	//		- ĳ���� �̸�
	//		- HP
	//		- ATTACK
	
	// ĳ���� ����â
	// �� ���ȵ��� �Է� ���� �� �ְ� �� ����.
	ChooseCharcter();
	//PrintCharacter();
	// ����ü �Լ�
	// ����ü ���ο� �Լ� ���� ����.
	
	// ĳ���� ������ ����ϰ� �ʹ�.
	//
}
void ChooseCharcter()
{
	Character character;
	cout << "�ٸ���ġ�� �̸��� �Է����ּ��� : ";
	getline(cin, character.Name);
	cout << "�ٸ���ġ�� HP�� �Է����ּ��� : ";
	cin >> character.HP;
	cout << "�ٸ���ġ�� Attack�� �Է����ּ��� : ";
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