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
	system("pause"); // 일시정지
	system("cls"); // 화면 밀어버림
	gotoxy(20, 10); printf("안녕하세요");

	//콘솔 색상 바꾸기
	//콘솔 폰트 크기 바꾸기
}