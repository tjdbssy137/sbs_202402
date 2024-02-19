#include <iostream>
using namespace std;

void main() {
	int a, b, c, d;
	int sum = 0;

	printf("점수 입력 >> ");
	scanf_s("%d %d %d %d", &a, &b, &c, &d);

	sum += a;
	sum += b;
	sum += c;
	sum += d;
	
	if (sum > 400)
		printf("A");
	else if (sum > 350)
		printf("B");
	else if (sum > 300)
		printf("C");
	else
		printf("D");
}