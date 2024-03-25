#include "pch.h"
#include "Defines.h"
class MySingleton
{
};

class GameManager
{
DECLARE_SINGLE(GameManager) // 꼼수
public:
	void GameStart()
	{
		cout << "게임이 시작합니다" << endl;
	}
};

/* // 위의 내용을 풀어쓰면 아래임.
class GameManager
{
private:
	//생성자, 소멸자를 스스로 아니면 못 사용하게 private에 막음.
	GameManager() {}
	~GameManager() {}
public :
	static GameManager* GetInstance()
	{
		static GameManager gameManager;
		return &gameManager;
	}
	void GameStart()
	{
		cout << "게임이 시작합니다" << endl;
	}
};
*/

void Funtion()
{
	//static은 한 번만 초기화 되고 다시 선언할 때는 동작하지 않음.
	// 10번 호출하면 a의 값이 매번 0으로 초기화 되지 않고 더해짐.
	static int a = 0;
	a++;
	cout << "a : " << a << endl;
}

void main()
{
	// 싱글톤이란,
	// 프로그램에서 단 하나의 객체만 존재하게 만드는 패턴
	
	/*
	MySingleton* mySingleton = new MySingleton();
	MySingleton* mySingleton2 = new MySingleton();
	MySingleton* mySingleton3 = new MySingleton();
	MySingleton* mySingleton4 = new MySingleton();
	MySingleton* mySingleton5 = new MySingleton();
	*/

	// 이렇게 만들기 싫다
	// 프로그래머가 잘해서 한 개만 만들면 좋은데
	// 강제적으로 한 개만 만들게 제약을 줄 수 있으면 실수를 방지할 수 있으니까.

	// GameManager 같이 게임을 관리하는 클래스는 여러개 있어야할 이유가 없다.
	// GameManger은 단 하나만 존재하게 하기 위해 싱글톤 패턴을 쓴다.
	// 일단 new를 사용하면 안 됨.

	for (int i = 0; i < 10; i++)
	{
		Funtion();
	}

	GameManager* gm = GameManager::GetInstance(); // 접근
	

	// 싱글톤을 부정적으로 보는 관점
	//기본적으로 전역변수를 사용하는 건 안 좋다고 봄.
	//메모리 관점이나 프로그래밍 유지보수 관점에서나..

	// <메모리 구조>
	// 1. 코드 영역
	// 2. 힙 영역
	// 3. 스택 영역
	// 4. 데이터 영역 -> 용량이 적음. (read가 빠르고, write가 느림)

	// GameManager을 호출하는 곳
	// 되게 여러 곳에서 GameManager을 참조하게 됨.
	// 어디서나 쓸 수 있기에
	// 캡슐화가 100% 잘 되어 있는 게 아니라면 코드가 꼬일 수밖에..
	
	// -> 전역변수는 나쁘다
	// 각자 알아서 잘 관리하는 코드가 좋은 코드다
	// 아이러니하게도 전역변수는 생산성을 올려줌. (편하기 때문에)

	// 막말로 싱글톤을 안 쓰면 게임개발을 못 할 정도. ㄷ
	// 이런거 신경 쓰지 말고 싱글톤 패턴 쓰면 됨.
}