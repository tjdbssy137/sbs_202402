#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

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

void PrintDino()
{
	printf("                ■■■■■■■■    \n");
	printf("               ■  ■■■■■■■   \n");
	printf("               ■■■■■■■■■■   \n");
	printf("   ■           ■■■■■■■      \n");
	printf("  ■■        ■■■■■■■■■■■     \n");
	printf("  ■■■      ■■■■■■■■■■■■■■   \n");
	printf("   ■■■■  ■■■■■■■■■■■■■■  ■■ \n");
	printf("     ■■■■■■■■■■■■■■■■       \n");
	printf("       ■■■■■■■■■■■■■        \n");
	printf("         ■■■■■■■■           \n");
	printf("          ■■■■■■            \n");
	printf("           ■■■■             \n");
	printf("            ■■■■■■          \n");
	printf("            ■■■■■■■         \n");
	printf("                            \n");
}
void main()
{
	setcolor(10, 0); // 색상 변경

	printf("PRESS 'A' OR 'D'\n");
	PrintDino();
	printf("      Feed          Hug       ");
	int sel = 0;
	while (true)
	{
		char input;
		if (_kbhit())
		{
			input = _getch();

			gotoxy(sel + 8, 15); printf("  ");
			switch (input)
			{
			case 'a':
				sel = 0;
				break;
			case 'd':
				sel = 13;
				break;
			default:
				break;
			}
			gotoxy(sel + 8, 15); printf("▼");

		}
	}

}