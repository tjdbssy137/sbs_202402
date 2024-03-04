#include <iostream>
#include <vector>
using namespace std;

// 컨벤션(네이밍 규칙) 대문자로 시작 (Pascal Case)
// 함수명도 대문자
// define은 전부 대문자
// 변수명은 소문자


struct Student // 하나의 자료형 안에 여러 개의 값을 기억시킬 수 있다.
{
	// 대문자로 시작(Pascal Case)
	int English;
	int Math;
	int Korean;
};

void main()
{
	// 구조체
	// 변수선언, 자료형

	// 자료형 종류
	
	// 기본 자료형
	//	- C++ 문법에서 기본적으로 제공해주는 자료형
	// 사용자 정의 자료형
	//	- 사용자가 필요해서 커스텀해서 만들게 하는 자료형
	//	- 구조체는 여기에 속함
	//	- enum

	// 구조체는 내가 원하는 데이터셋을 만들 수 있다.
	
	Student student = {};
	student.English = 90;
	student.Math = 89;
	student.Korean = 80;
	// 하나의 자료형 안에 여러 개의 값을 기억시킬 수 있다.

	vector<Student> students;
	//students.push_back(student);

	//실습
	// 10명의 학생 점수 데이터를 벡터 리스트로 만들어서 (평균점수가 높은 순으로) 출력.

	srand(time(NULL));


	int sum[10] = {};
	for (int i = 0; i < 10; i++)
	{
		Student student = {};
		student.English = rand() % 101;
		student.Math = rand() % 101;
		student.Korean = rand() % 101;
		sum[i] = (student.English + student.Math + student.Korean)/3;
		students.push_back(student);
	}

	vector<int> list;
	vector<int> temp;
	list.push_back(sum[0]);
	for (int i = 1; i < 10; i++)
	{
		if (sum[i - 1] < sum[i])
		{
			while (list.size() > 0)
			{
				int a = list[list.size() - 1];
				list.pop_back();
				temp.push_back(a);
			}
			list.push_back(sum[i]);
			while (temp.size() > 0)
			{
				int a = temp[temp.size() - 1];
				temp.pop_back();
				list.push_back(a);
			}
		}
	}
/*
	for (int i = 0; i < 10; i++)
	{
		cout << list[i] << endl;
	}
*/


	for (int i = 0; i < 10; i++)
	{
		cout << "students[" << i << "].English : " << students[i].English << endl;
		cout << "students[" << i << "].Math : " << students[i].Math << endl;
		cout << "students[" << i << "].Korean : " << students[i].Korean << endl;
		cout << endl;
	}
	
}