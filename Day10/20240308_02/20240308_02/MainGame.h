#pragma once
class MainGame
{
private:
	int _money = 1000;
	// 변수는 웬만하면 전부 이곳에.
public :
	MainGame(); // 생성자	new할 때 실행(생애 최초 1번)
	~MainGame(); // 소멸자	delete할 때 실행(생애 최초 1번)
	void Bet();
};

