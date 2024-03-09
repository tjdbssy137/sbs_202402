#pragma once

#include <iostream>
#include <string>
using namespace std;
#define COUNT 20
class HangMan
{
private:
	string _word[8] = {"position", "surprise", "umbrella", "triangle", "tomorrow", "reaction", "occasion", "birthday"};
	string _answer = "";
	string _display = " _ _ _ _ _ _ _ _";
	string _input = "";
	int _count = 0;
	int _game = 0;
public:
	HangMan();
	~HangMan();
	void PrintWord();
	void ChooseWord();
	void InputWord();
	void CompareWord();

};

