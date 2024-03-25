#include "pch.h"
#define Interface class

Interface IDoorOpener
{
public:
	virtual void OpenDoor() abstract;
};

Interface IDoorCloser
{
public:
	virtual void CloseDoor() abstract;
};

class Key : public IDoorOpener, IDoorCloser // 강사님 자료 확인 필요
{
protected:// 상속받은 애들이 사용할 수 있음, 본인 + 상속받은 애만 접근 가능
	string _name;
private: // 상속해도 이건 못 씀, 본인만 접근 가능
	//string _name;
public : // 아무나 접근 가능
	void SetName(string name)
	{
		_name = name;
	}
	void OpenDoor()
	{
		printf("[%s] 문을 열지 못 했다\n", _name.c_str());
	}
	virtual void OpenDoor2()
	{
		printf("[%s] 문을 열지 못 했다\n", _name.c_str());
	}
	void CloseDoor()
	{
		cout << "문을 닫지 못했다." << endl;
	}
};
// 상속 문법 ( : public 클래스명 )
class MasterKey : public Key
{
public:
	void OpenDoor()
	{
		
		printf("[%s] 문을 열었다\n", _name.c_str());
	}

	virtual void OpenDoor2() override // virtual만 써도 됨, override는 가독성 용.
	{

		printf("[%s] 문을 열었다\n", _name.c_str());
	}

	void CloseDoor()
	{
		cout << "문을 닫지 못했다." << endl;
	}
};

//////////////// ////////////////

void main()
{
	// 2. 클래스
	// 클래스의 네가지 특징
	// 중요한데, 외울거까진 아님.

	// 상속, 다형성, 캡슐화, 추상화

	// 클래스 (객체)
	// 구조체 (데이터)

	// 1. 상속
	// - 함수와 변수를 재활용 할 수 있다.
	{
		MasterKey* masterKey = new MasterKey();

		masterKey->SetName("마스터키");
		masterKey->OpenDoor();

		delete masterKey;
	}

	// 2. 다형성
	// - 부모 클래스로 자식 클래스를 생성했을 때
	//		=> 부모클래스 자료형으로 자식클래스 함수를 호출할 수 있다.
	Key* key = new MasterKey();
	// MasterKey* masterKey = new Key(); // << 안됨
	key->SetName("마스터키2");
	key->OpenDoor2(); // 자식클래스로 생성을 했어도 호출은 부모(본인) 클래스 함수로 호출
	delete key;
	

	// 3. 캡슐화
	// protected, private, public으로 나누는 것
	// 기본적으로 변수를 외부에 노출 시키지 않는다
	// 클래스의 기본 원칙
	// 외부에 노출 시키지 않으면 대체 어떤 장점이 있길래..
	// 그 편한걸 감수하고 노출ㄹ을 안 시키는 지?

	// 클래스 << 하나의 책임을 담당하는 자료형
	// 클래스 예시 중
	// TimeManager >> 시간을 관리해주는 클래스
	// 저 내부변수까지 컨트롤할 필요가 있을까?
	// 내부적인 변수는 private로 아예 노출을 시키지 않는다
	// 외부에서는 단순하게
	// 현재 시간
	// 이전 프레임~ 현재 프레임 걸린시간


	// 4. 추상화
	// 다른 언어에서는 interface라고 함
	// 추상화는 함수만 선언되어 있고, 본문 정의는 안 되어있는 상태
	{
		Key* key1 = new Key();
		IDoorOpener* opener = key1;
		//key->SetKey();는 안 됨.
		opener->OpenDoor();

		IDoorCloser* closer = key1;
		closer->CloseDoor();
	}
	// interface에서 선언한 것만 불러올 수 있음.

}