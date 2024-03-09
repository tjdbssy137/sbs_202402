#include "HangMan.h"
// 3) 행맨
//
// 1. 컴퓨터가 랜덤한 단어 중에 하나를 선택
// - 이때 단어는 position, surprise, umbrella, triangle, tomorrow, reaction 중에 하나를 뽑는다
// 2. _ _ _ _ _ _ _ _
// 3. 사용자가 문자열을 입력
// 4. 이때 맞는 문자가 있으면 표시를 해줌
// - 입력 : oooooooo -> 출력 : _ o _ _ _ _ o _ n
// 5. 20번 동안 단어를 완성 못하면 플레이어 패배.
// string a = "position";
// a[0] = p;
// a[7] = n;
// a.size(); // 가능 

HangMan::HangMan()
{
	srand(time(NULL));
	ChooseWord();

	while (_game != 1)
	{
		PrintWord();
		InputWord();
		CompareWord();
		if (COUNT <= _count)
		{
			cout << "횟수를 초과하셨습니다." << endl;
			cout << "정답은 " << _answer << "이었습니다." << endl;
			break;
		}
	}
}
void HangMan::PrintWord()
{
	for (int i = 0; i < _display.size(); i++)
	{
		cout << _display[i];
	}
	cout << endl;
}
void HangMan::ChooseWord()
{
	_answer = _word[rand() % 6];
}
void HangMan::InputWord()
{
	_input.clear();
	cout << "예측되는 단어를 입력해주세요 : ";
	getline(cin, _input);
	this->_count++;
}
void HangMan::CompareWord()
{
	if (_input == _answer)
	{
		cout << "정답을 맞추셨습니다." << endl;
		cout << _answer << endl;
		_game = 1;
	}
	else
	{
		for (int i = 0; i < _answer.size(); i++)
		{
			if (_input[i] == _answer[i])
			{
				_display[(i * 2) + 1] = _input[i];
			}
		}
	}
}
HangMan::~HangMan()
{
	cout << "동적할당 해제" << endl;
}