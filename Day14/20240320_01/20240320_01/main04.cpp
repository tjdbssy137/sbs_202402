#include "pch.h"
void main()
{
	// ������ ���ؼ� ���ڽ��ϴ�.
	// �׵��� ��� ����

	srand(time(NULL));
	int arr[100] = {};
	for (int i = 0; i < 100; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < 1000; i++)
	{
		int first = rand() % 100;
		int second = rand() % 100;

		int temp = arr[first];
		arr[first] = arr[second];
		arr[second] = temp;
	}

	// random�� ������ 2����
	// 1. ������ max���� 32627�̴�.
	//	=> ���� �ƴմϴ�.(����??)
	//	=> ���������� ���� ��� ������ Ȯ��ǥ
	//	=> �̰Ÿ� ������ �� ����
	
	// 2. �ƹ��� �õ带 �����ٰ� ������, ���� ������ �׷��� �̻ڰ� �������� ����
	// ���� ���� ������ �޾Ƽ� ���� ������ ��찡 ����.
	//

	// rand() �� �� ����
	// ������.


	//���� RandomModule
	RandomModule* randomModule = new RandomModule();

	for (int i = 0; i < 1000; i++)
	{
		cout << randomModule->GetRandomInt(0, 32627) << endl;
	}

	// auto��,
	// ���带 ������ �������� ���ؼ� �˾Ƽ� ������, runtime ���߿� ������ �� �ƴ�.
	
	// �׷��� auto�� ����ϸ� �� �Ǵ� ����!
	// ȸ�縶�� �� auto�� ���� ��Ű�� ȸ�� ����
	// ex) �޾��
}
