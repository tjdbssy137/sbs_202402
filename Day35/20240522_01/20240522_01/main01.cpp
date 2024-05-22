#include <iostream>
using namespace std;

void main()
{
	// file write
	// 1. C 스타일 
	// 2. C++ 스타일 

	// C 스타일
	if(false)
	{
		FILE* file = nullptr;
		// 접근 권한
		// wb : write + binary
		// wt : write + text
		// rb : read + binary
		// rt : read + text
		fopen_s(&file, "test.txt", "wb");
		if (file == nullptr)
		{
			cout << "file nullptr 에러" << endl;
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
			cout << "file nullptr 에러" << endl;
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