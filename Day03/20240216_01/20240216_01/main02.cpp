#include <iostream>
using namespace std;

void main() {
	//���� -> ������ ����

	//1. ������ ��������?
	// -> ���α׷����� ����ؾ��ϴ� ������.

	//2. ���� ����ϴ� ��
	// [1] �ڷ��� ������ = ��;
	// [2] �ڷ��� ������;
	
	// �ڷ��� => ���� �ڷ���
	//1 byte ���� = 8bit (0 ~ 255), (-128 ~ 127)
	//2 byte ���� = 16bit (2��)
	//4 byte ���� = 32bit (-21�� ~ 21��)
	// => CPU������ ������ ������
	//8 byte ���� = 64bit 

	// 1 byte : char
	// 2 byte : short
	// 4 byte : int
	// 8 byte : long long

	int a = 1;
	printf("a : %d\n", a);
	printf("a : %10d\n", a);
	printf("a : -%10d\n", a);

	short b = 5000000; //2���� �ʰ��ϸ� ���� �˾Ƽ� �߸�.
	printf("b : %d\n", b);
	// => 19264�� ��µ�
	// ������ �� �ִ� ��Ʈ�� �����Ǿ��ֱ� ������ ��ġ�� ������ ���� �� ����.
	
	long long c = 1;

	char d = 'a';
	string e = "apple";

	float f = 1.0f;
	double g = 1.0f;

	bool h = true;
}