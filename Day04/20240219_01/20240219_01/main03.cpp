#include <iostream>
using namespace std;

void main() {
	// #TIP. 변수명 바꾸기 Ctrl + R + R
	
	// cin >> // scanf_s
	// cout << "할말" << endl; // printf("할말\n"); 
	// => 대신 cout 에서는 %d를 사용하지 않고 변수명을 직접 입력 => cout << sum << endl;
	int a, b, c, d;
	int sum = 0;

	printf("점수 입력 >> ");
	//scanf_s("%d %d %d %d", &a, &b, &c, &d);
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	scanf_s("%d", &d);

	sum += a;
	sum += b;
	sum += c;
	sum += d;
	
	if (sum >= 400)
		printf("A");
	else if (sum >= 350)
		printf("B");
	else if (sum >= 300)
		printf("C");
	else
		printf("D");
}