/*
���� �� ���� �Է� �޾Ƽ�
100, 200, 300, 400
ó�� ���� �� �� ������ ���� ���ڿ��� ����° ���ڸ� ����
�׹�° ���ڸ� ���� ���� ���
*/
#include <iostream>
#include <time.h>
using namespace std;

void main() {
	srand(time(NULL));
	int a, b, c, d;
	printf("���� �� �� �Է� >> ");
	scanf_s("%d %d %d %d", &a, &b, &c, &d);
	int random = rand() % (a - b + 1) + b;
	printf("�� �� ������ ���� ���� %d\n", random);

	int subtract = random - c;
	printf("���� ������ ����° ���ڸ� �� ���� %d\n", subtract);

	int multiply = subtract * d;
	printf("���� ����� %d", multiply);
}