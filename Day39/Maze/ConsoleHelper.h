#pragma once
#include <Windows.h>
enum class ConsoleColor
{
	BLACK = 0,
	RED = FOREGROUND_RED,
	GREEN = FOREGROUND_GREEN,
	BLUE = FOREGROUND_BLUE,
	YELLOW = FOREGROUND_RED | FOREGROUND_GREEN,
	MAGENTA = FOREGROUND_RED | FOREGROUND_BLUE,
	WHITE = RED | GREEN | BLUE
};

class ConsoleHelper
{
public:
	static void SetCursorPosition(int x, int y);
	static void SetCursorColor(ConsoleColor textColor, ConsoleColor backgroundColor);
	static void ShowConsoleCursor(bool flag);
};

