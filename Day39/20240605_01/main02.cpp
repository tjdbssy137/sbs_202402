#include <iostream>
#include "solution1.hpp"
using namespace std;


void main()
{
	{
		vector<vector<int>> computers = {
			{1, 1, 0} ,
			{1, 1, 0} ,
			{0, 0, 1}
		};
		cout << solution(3, computers) << endl;
	}

	{
		vector<vector<int>> computers = {
			{1, 1, 0} ,
			{1, 1, 1} ,
			{0, 1, 1}
		};
		cout << solution(3, computers) << endl;
	}
}