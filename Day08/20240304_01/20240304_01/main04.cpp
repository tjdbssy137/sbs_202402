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
	/*
	Student student = {};
	student.English = 90;
	student.Math = 89;
	student.Korean = 80;
	*/
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
		sum[i] = (student.English + student.Math + student.Korean) / 3;
		students.push_back(student);
	}

	vector<int> list;
	vector<int> temp;
	list.push_back(sum[0]);
	for (int i = 1; i < 10; i++)
	{
		list.push_back(sum[i]);
		for (int j = 0; j < i; j++)
		{
			if (list.at(j) < sum[i])
			{
				int temp = list.at(i);
				list.at(i) = list.at(j);
				list.at(j) = temp;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (sum[j] == list.at(i))
			{
				cout << i+1 << "등 학생은 " << j+1 << "번 학생입니다." << endl;
				cout << j + 1 << "의 English 점수 : " << students[j].English << endl;
				cout << j + 1 << "의 Math 점수 : " << students[j].Math << endl;
				cout << j + 1 << "의 Korean 점수 : " << students[j].Korean << endl;
				cout << j + 1 << "의 평균 점수 : " << list.at(i) << endl;
				cout << endl;
			}
		}
	}
}