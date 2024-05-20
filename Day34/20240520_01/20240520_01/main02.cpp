#include <iostream>
using namespace std;

enum WeaponType
{
	WT_LASER,
	WT_SANTAN
};
void main()
{
	// ������ �ӵ�
	// ���� ���� ���� -> ��Ʈ����!!

	// ����(���� Ÿ��)
	//		(��������, ��ź�� etc) (�̷� �͵� ������ 32������ �� �Ѱ���??)
	
	// �ٵ� ��Ʈ ������ ������
	// 32������ �ѱ�� ������ ������ ����ٴ� ��,,

	// 0000
	// 0001 => WT_LASER
	// 0010 => WT_SANTAN

	// 0011 -> ���������̸鼭 ��ź���� ���
	int weapon = (1 << WT_LASER) | (1 << WT_SANTAN);

	printf("weapon : %d\n", weapon);

	// C++ 
	// if(����) ���ڰ� 0�� �ƴϸ� true
	// �ٵ� C++�� �ƴ� ������ if(����) --> ����(�񱳿����ڷ� Ȯ���ϰ� �������.)
	if (0 < (weapon & (1 << WeaponType::WT_LASER))) 
		// "0 < "�� ��� �Ǳ�������, �ٸ� ���� �ű�� �ȴٸ� ������ ���̱� ���� "0 < "�� ����
	{
		printf("������ �ɼ� �߰�\n");
		printf("���ݷ� ���� + 5\n");
	}
	
	if (0 < (weapon & (1 << WeaponType::WT_SANTAN)))
	{
		printf("��ź �ɼ� �߰�\n");
		printf("���ݷ� ���� + 15\n");
	}
}