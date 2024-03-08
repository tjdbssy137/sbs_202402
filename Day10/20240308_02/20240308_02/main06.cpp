#include <iostream>
#include "MainGame.h"
using namespace std;

// Ŭ���� ����
class Card {
private: // ������� ���� �� �� �ִ�.
	// Ŭ������ �⺻�� private�̴�.
	int MyVariable;
public : // ������� �ƹ��� �� �� �ְ� ��.
	int Index;

	// ����ü �Լ��� ���� �� �ƴٰ�, ���߿� ���������� ����� ��
	// Ŭ���� �Լ��� �������� �����ߴ�.
	// �׷��� Ŭ������ ����ü�� �������� �⺻���� private����, public������ ���̴�.(c++ ����)
	void Print()
	{
		printf("class print");
	}
};

struct CardStruct {
private:

public:
	// ����ü�� �⺻�� public �̰�
	int Index;
};

void main()
{
	// class
	// ���� ���ܱ� 2ȣ

	// class = struct
	
	// Ŭ���� ���
	// Ŭ������ ����ü�� �����ϰ� ����� ���� �ڷ���.

	Card card = {};
	card.Index = 0;

	CardStruct cardStruct = {};
	cardStruct.Index = 1;

	//C++�� Ư���ϱ⿡, 
	// �Ϲ����� Ŭ���� Ư¡�� ¤�� �Ѿ��.
	// Ŭ���� - ���� ���� Ŭ������ heap�� �Ҵ� ��.(���� �޸𸮶�� ��) 
	// ����ü - ���� ���� ����ü�� stack�� �Ҵ� ��.(���� �޸𸮶�� ��)
	
	// [�ַ� heap�� �����Ͱ� ū ���� �ٷ��]
	// Ŭ���� �ڷ��� -> ��ü(= �ھư� �ִ�)
	// ����ü �ڷ��� -> ������(= �ھư� ����)
	// ��� ����ü�� ������ ��� ������ Ŭ������� �����ϴ� �� ����.
	// 
	// Ŭ���� - ���� ���� Ŭ������ heap�� �Ҵ� ��.(���� �޸𸮶�� ��) 
	// C++������ ���� Ŭ������ new�� ���.
	// Ŭ������ ������ �̷��� ������ּ���.
	// �ҽ����� �߰� -> Ŭ���� -> Ŭ���� �̸� : MainGame -> 
	//

	MainGame* mainGame = new MainGame();
	delete mainGame;
	//MainGame_BlackJack* mainGame = new MainGame_BlackJack();
}