#include "MainGame.h"
// ���� ����� �ִٸ� �̰����� ����
// ����ü��簡.. �� �׷� �� ����� ����.
#include <iostream>
using namespace std;

MainGame::MainGame()
{
	printf("���� ���� ������");
	//���⸦ void main()�̶� �����ϰ� �ڵ��ϸ� ��.

	// ���� ����
	// �Լ� ����/����

	// 1. ���� ���� �ϴ� ��
	// ��� ���Ϸ� ����
	// int _money = 1000; // _ <- ����� �ʼ�. Ŭ���� ���������� �������� ����(�ǹ�).
	this->_money; // money;

	// 2. �Լ� ���� �ϴ� ��
	// public �Ʒ��� ���� ����.
	// void Bet();
}

void MainGame::Bet()
{
	cout << "�������ּ��� : ";
	cin >> this->_money;
}

MainGame::~MainGame()
{
	printf("���� ���� �Ҹ���");
}