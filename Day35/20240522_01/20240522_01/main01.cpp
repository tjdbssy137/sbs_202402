#include <iostream>
using namespace std;

void main()
{
	// file write
	// 1. C ��Ÿ�� 
	// 2. C++ ��Ÿ�� 

	// C ��Ÿ��
	if(false)
	{
		FILE* file = nullptr;
		// ���� ����
		// wb : write + binary
		// wt : write + text
		// rb : read + binary
		// rt : read + text
		fopen_s(&file, "test.txt", "wb");
		if (file == nullptr)
		{
			cout << "file nullptr ����" << endl;
			return;
		}
		int a = 3;
		fwrite(&a, sizeof(a), 1, file);
		fwrite(&a, sizeof(a), 1, file);
		fwrite(&a, sizeof(a), 1, file);

		fclose(file);
	}

	if (true)
	{
		FILE* file = nullptr;
		fopen_s(&file, "test.txt", "rb");
		if (file == nullptr)
		{
			cout << "file nullptr ����" << endl;
			return;
		}
		int value;
		fread(&value, sizeof(value), 1, file);
		fread(&value, sizeof(value), 1, file);
		fread(&value, sizeof(value), 1, file);
		
		printf("value : %d", value);

		fclose(file);
	}
}