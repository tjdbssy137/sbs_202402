#include <iostream>
using namespace std;

#include <time.h>

void main() {
	srand(time(NULL));
	int random = rand() % 31;
	printf("random1 = %d\n", random);

	int random2 = rand() % 101;
	printf("random2 = %d\n", random2);

	// 25 ~ 40 ������ ���� ���ڸ� ����ϱ�
	// 0 ~ 15 ������ �������ڿ��� +25�� �ϸ� �ȴ�.
	int random3 = rand() % 16 + 25;
	printf("random3 = %d\n", random3);
	
	int random4 = rand() % 121 + 150;
	printf("random4 = %d\n", random4);

	//�Է� input
	// -> Ű����, ���콺, ��ġ, ������� ��
	// -> �ܼ��� Ű���常 ���.

	//scanf��� �ϴ� ���� ������ ���� �Է¿� ���ؼ� �ٷ� ��.
	int input1 = 0;

	//����
	//scanf_s("%d", &������);
	
	//printf("input1 >> ");
	//scanf_s("%d", &input1);
	//printf("input1 : %d\n", input1);

	
	//�ֻ��ó
	//���α׷��� �������� ������ ������
	//�������� �� �� ����.
	
	//printf("����(0) ����(1) ��(2) �߿� �ϳ��� �������ּ��� >> ");
	//scanf_s("%d", &input1);

	//�ǽ�.
	//���� �� ���� �Է¹޾Ƽ�
	//�� �ΰ� ������ random ���ڸ� ����ϵ���.
	int a = 0, b = 0;
	printf("input A and B >> ");
	scanf_s("%d %d", &a, &b);

	printf("%d�� %d ������ ������ ���� %d", a, b, rand() % (a - b + 1) + b);

}