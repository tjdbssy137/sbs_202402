#include <iostream>
using namespace std;

//로또 생성기
// 1) 1 ~ 45까지 적힌 array를 만든다
// 2) array를 섞는다
// 3) 그중 7개를 뽑는다
void main()
{
	int arr[45] = {};
	for (int i = 0; i < 45; i++)
	{
		arr[i] = i + 1;
	}

	srand(time(NULL));
	for (int i = 0; i < 10000; i++)
	{
		int firstIndex = rand() % 45;
		int secondIndex = rand() % 45;

		int temp = arr[firstIndex];
		arr[firstIndex] = arr[secondIndex];
		arr[secondIndex] = temp;
	}

	cout << "로또 당첨 번호는.. ";
	for (int i = 0; i < 7; i++)
	{
		cout << arr[rand() % 45] << " ";
	}
}