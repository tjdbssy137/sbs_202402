#include <iostream>
#include <time.h>
using namespace std;

void main() {
	srand(time(NULL));
	int _random = rand() % 100 + 1;
	int _input = 101;

	while (1) {
		cout << "숫자를 입력해보세요 : ";
		cin >> _input;
		if (_random < _input) cout << "down" << endl;
		else if (_input < _random)  cout << "up" << endl;
		else 
		{
			cout << "정답은 " << _random << "이었습니다.";
			exit(0);
		}
	}
}