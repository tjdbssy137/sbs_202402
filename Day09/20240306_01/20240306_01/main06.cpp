#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

void main()
{
	// 콘솔에서만 쓰일 기술이고
	// 콘솔을 다루는 거 일주일도 안 남음
	// 콘솔 게임 끝.
	// 이해 안 되면 안 해도 됨.

	int oldGameTime = GetTickCount64(); // 현재 게임 시간을 기억한다. (0초)
	//GetTickCount() => 게임이 시작하고 몇 ms가 지났는지?
	
	while (true)
	{
		// 1초에 한 번씩
		int currentGameTime = GetTickCount64();
		if (1000 < currentGameTime - oldGameTime)
		{
			//system("cls");
			cout << "1초가 지났습니다." << endl;
			oldGameTime = currentGameTime;
		}
	}
	// 2D 애니메이션
	// 이미지 여러장을 체인지 하는 형식으로 애니메이션을 주는데
	// 그 알고리즘이 위의 것.
}