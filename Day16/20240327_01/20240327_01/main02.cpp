#include <iostream>
using namespace std;

void main()
{
	//����ȯ ĳ���� �� ����
	// (�ϳ� �� �ִµ�, �� �� C�����̶� ����)
	// 
	// �ڷ����� ����
	// - C ���� ĳ����
	float a = 3.3f;
	int e = (int)a;

	//�ּҰ��� ������ �޴´�
	int f = (int)&a;

	// - C++ ������ ĳ���� (C���� ���� ��õ)
	// 1. static_cast (���� ĳ����)
	// float -> int
	// string -> int ���� ������� ���� �� �� ��.
	int g = static_cast<int>(a);

	// - 2. dynamic_cast
	// ��Ӱ� ������ ���� ĳ����
	// ���� �ٽ� ���.. �ʹݿ� ����
	MasterKey* key = new MasterKey();
	Key* myKey1 = dynamic_cast<MasterKey*>(key);

	// -3. reinterpret_cast
	// ���� �� ��
	// �޸� �״�� ĳ���� ���� ��
	int bb = 123;
	int* ptr1 = reinterpret_cast<int*>(bb);


}