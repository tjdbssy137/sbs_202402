#include <iostream>
#include <Windows.h>
using namespace std;

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void main()
{
	system("pause"); // �Ͻ�����
	system("cls"); // ȭ�� �о����
	gotoxy(20, 10); printf("�ȳ��ϼ���");

	//�ܼ� ���� �ٲٱ�
	//�ܼ� ��Ʈ ũ�� �ٲٱ�
}