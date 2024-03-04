#include <iostream>
#include <Windows.h>
using namespace std;

// 실습2
// gotoxy()사용해서 캐릭터 만들기

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setcolor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

void main()
{
	//system("pause"); // 일시정지
	//system("cls"); // 화면 밀어버림
	gotoxy(0, 10);
	setcolor(10, 0); // 색상 변경
	printf("□□□□□□□□□□□□□□□□\n");
	printf("□□□□□□■■■■□□□□□□\n");#include <iostream>
#include <Windows.h>
using namespace std;

// 실습2
// gotoxy()사용해서 캐릭터 만들기

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setcolor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

void main()
{
	//system("pause"); // 일시정지
	//system("cls"); // 화면 밀어버림
	gotoxy(0, 10);
	setcolor(10, 0); // 색상 변경
	printf("□□□□□□□□□□□□□□□□\n");
	printf("□□□□□□■■■■□□□□□□\n");
	printf("□□□□□□■■■■□□□□□□\n");
	printf("□□□□■■■■■■■■□□□□\n");
	printf("□□□■■□■■■■□■■□□□\n");
	printf("□□■■□■■■■■■□■■□□\n");
	printf("□■■□□□■■■■□□□■■□\n");
	printf("□□□□□■■■■■■□□□□□\n");
	printf("□□□□■■□□□□■■□□□□\n");
	printf("□□□□■■□□□□■■□□□□\n");
	printf("□□□■■■□□□□■■■□□□\n");
	printf("□□□□□□□□□□□□□□□□\n");

	//콘솔 색상 바꾸기
	//콘솔 폰트 크기 바꾸기
}
	printf("□□□□□□■■■■□□□□□□\n");
	printf("□□□□■■■■■■■■□□□□\n");
	printf("□□□■■□■■■■□■■□□□\n");
	printf("□□■■□■■■■■■□■■□□\n");
	printf("□■■□□□■■■■□□□■■□\n");
	printf("□□□□□■■■■■■□□□□□\n");
	printf("□□□□■■□□□□■■□□□□\n");
	printf("□□□□■■□□□□■■□□□□\n");
	printf("□□□■■■□□□□■■■□□□\n");
	printf("□□□□□□□□□□□□□□□□\n");

	//콘솔 색상 바꾸기
	//콘솔 폰트 크기 바꾸기
}