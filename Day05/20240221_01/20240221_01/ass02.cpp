#include <iostream>
#include <time.h>
using namespace std;

void main() {
	srand(time(NULL));
	int _random = rand() % 100 + 1;
	int _input = 101;

	while (1) {
		cout << "���ڸ� �Է��غ����� : ";
		cin >> _input;
		if (_input > _random) cout << "down" << endl;
		else if (_input < _random)  coaut << "up" << endl;
		else 
		{
			cout << "������ " << _random << "�̾����ϴ�.";
			exit(0);
		}
	}
}