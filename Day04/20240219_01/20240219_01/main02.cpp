#include <iostream>
// - input : Ű���� �Է�, ���콺 �Է� ��
// - output : ���(�������� �ܼ� ����)
using namespace std;
// �Լ��� �����ϰ� �� �� ����

// ��� ���α׷� ���� main�̶�� �Լ��� ã�Ƽ� �����Ѵ�.
void main() {
	int a = 0;

	// if��, ��� ���α׷��Ӱ� ���� ���� ����ϴ� ����.

	if (a == 0) //���ǿ� ���� ���� ���� ��ų �� �ִ� ����
		printf("a�� 0�Դϴ�.\n");

	// ���α׷����� ���Ϸ��� ���� �ڵ�� �ٲ� �� �־�� �Ѵ�.
	
	// if�� ����
	// if(���ǽ�)
	// { ������ ���� �� �����ϴ� �ڵ� }

	// ���ǽ�
	// ���� �� 1 true
	// ������ �� 0 false
	int num1 = 10;
	int num2 = 20;

	printf("num1[%d] > num2[%d] : %d\n", num1, num2, num1 > num2);
	printf("num1[%d] < num2[%d] : %d\n", num1, num2, num1 < num2);
	
	// �񱳿����� (����� �׻� 0�� 1�� ���´�)
	// A > B : A�� B���� ũ��
	// A < B : A�� B���� �۴�
	// A >= B : A�� B���� ũ�ų� ����
	// A <= B : A�� B���� �۰ų� ����
	// A != B : A�� B�� ���� �ʴ�
	// A == B : A�� B�� ����
	// A && B : A�� B => A�� B �� �� ���� ���� ���� ��ȯ
	// A || B : A �Ǵ� B => A�� B �߿� �ϳ��� ���̾ ���� ��ȯ


	// if�� => ���� ~~���
	// else if�� => �׷��� �ʰ� ~~��
	//  => if�� ������ false + ���ο� ������ true �� ��
	// else �� => �׷��� ������
	int input1 = 0;

	printf("������ �Է����ּ��� : ");
	scanf_s("%d", &input1);

	if (90 < input1) {
		printf("A�Դϴ�.");
	}
	else if (80 < input1) {
		printf("B�Դϴ�.");
	}
	else if (70 < input1) {
		printf("C�Դϴ�.");
	}
	else if (60 < input1) {
		printf("D�Դϴ�.");
	}
	else {
		printf("F�Դϴ�.");
	}
}