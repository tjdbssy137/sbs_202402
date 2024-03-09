#include "HangMan.h"
// 3) ���
//
// 1. ��ǻ�Ͱ� ������ �ܾ� �߿� �ϳ��� ����
// - �̶� �ܾ�� position, surprise, umbrella, triangle, tomorrow, reaction �߿� �ϳ��� �̴´�
// 2. _ _ _ _ _ _ _ _
// 3. ����ڰ� ���ڿ��� �Է�
// 4. �̶� �´� ���ڰ� ������ ǥ�ø� ����
// - �Է� : oooooooo -> ��� : _ o _ _ _ _ o _ n
// 5. 20�� ���� �ܾ �ϼ� ���ϸ� �÷��̾� �й�.
// string a = "position";
// a[0] = p;
// a[7] = n;
// a.size(); // ���� 

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
			cout << "Ƚ���� �ʰ��ϼ̽��ϴ�." << endl;
			cout << "������ " << _answer << "�̾����ϴ�." << endl;
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
	cout << "�����Ǵ� �ܾ �Է����ּ��� : ";
	getline(cin, _input);
	this->_count++;
}
void HangMan::CompareWord()
{
	if (_input == _answer)
	{
		cout << "������ ���߼̽��ϴ�." << endl;
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
	cout << "�����Ҵ� ����" << endl;
}