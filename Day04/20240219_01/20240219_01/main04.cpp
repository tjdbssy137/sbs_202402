#include <iostream>
using namespace std;

void main() {
	//SWITCH 문
	// IF문과 아주 유사하고 IF문에 대체될 수 있다.
	// IF문과의 차이점 -> SWITCH문이 가독성이 더 좋고, 아주 미세하지만 속도면에서 더 우수.
	// 모든 switch 문은 if문으로 바꿀 수 있지만, 모든 if문을 switch문으로 바꿀 수 없다.
	// 점수 구간 대에 대한 성적( main02.cpp, main03.cpp 참고 )

	int hand;
	cout << "가위(1)바위(2)보(3) 입력 : ";
	cin >> hand;

	cout << "당신은 ";

	switch (hand) {
	case 1:
		cout << "가위를 냈습니다." << endl;
		break;
	case 2:
		cout << "바위를 냈습니다." << endl;
		break;
	case 3:
		cout << "보를 냈습니다." << endl;
		break;
	default :
		cout << "잘못 뽑았습니다." << endl;
		break;
	}
}