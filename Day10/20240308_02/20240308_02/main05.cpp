#include <iostream>
using namespace std;

void main()
{
	// �迭�� ���� �Ҵ�
	// �迭�� �����Ϳ� ���.

	// �����Ҵ��� �迭�ε� �� �� ����
	// ������ �����ͷ� �޴� ���� �ƴϰ�
	// �׳� �Ȱ��� ������ �����ͷ� �迭 �����Ҵ��� ��.
	
	//new int[ũ��]
	int* arr = new int[10];
	int count = 20;
	int myArr[count]; // �� ��

	// ��Ÿ�� ���߿� �޸𸮸� �Ҵ��ϴ� �Ŷ�, �׶� �´� �迭 ũ�⸦ ��� ������ ���� ����.
	int* myArr = new int[count];
	// �Ҵ��ϴ� ��
	for (int i = 0; i < count; i++)
	{
		myArr[i] = i + 1;
	}

	//�����ϴ� ��
	delete[] myArr;
}