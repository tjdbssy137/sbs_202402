#include <iostream>
using namespace std;

void main() {
	// #TIP. ������ �ٲٱ� Ctrl + R + R
	
	// cin >> // scanf_s
	// cout << "�Ҹ�" << endl; // printf("�Ҹ�\n"); 
	// => ��� cout ������ %d�� ������� �ʰ� �������� ���� �Է� => cout << sum << endl;
	int a, b, c, d;
	int sum = 0;

	printf("���� �Է� >> ");
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