#include <iostream>
#include <vector>
using namespace std;

void main()
{
	// vector
	// ���� ���� �迭
	// #include<vector>
	// using namespace std;

	vector<int> myVector;
	for (int i = 0; i < 45; i++)
	{
		myVector.push_back(i + 1);
	}
	cout <<"myVector.size() : " << myVector.size() << endl;
	//�����
	//myVector.erase(myVector.begin() + 5);
	//myVector.begin() + 5 => 5��° �ε����� �����.
	
	for (int i = 0; i < 45; i++)
	{
		cout << myVector[i] << "  ";
	}

	printf("\n\nVector 2���� �迭\n");

	vector<vector<int>> arr; // 2���� �迭
	for (int i = 0; i < 5; i++)
	{
		vector<int> temp;
		for (int j = 0; j < 5; j++)
		{
			temp.push_back(i * 5 + j);
		}
		arr.push_back(temp);
	}

	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			cout << arr[i][j] << " ";
		}
		printf("\n");
	}
}