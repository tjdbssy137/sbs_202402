void Comment01()
{
	// 1. Flipbook 완성
	//	- Duration, Loop 기능
	
	// 2. Camera에 대해..
	//	- 주말 숙제는 2048(camera 안 필요)
	
	// 3. 간단하게 if문 동작 원리
	//	- 상식으로 알고 있으면 알쓸신잡
}

void Comment02()
{
	// if문 동작 원리
	
	bool conditionHeavy1 = true; // CheckCollision(아주 조금 무거움)
	// bool 타입이 함수로 들어가면 무거움
	bool conditionHeavy2 = false;
	bool conditionLight3 = true; // 
	bool conditionLight4 = false;


	// "||" 연산은 true를 만나면 뒤의 연산은 하지 않는다.
	// 그러면 앞에 가벼운 값을 넣는 게 좋음.
	// if (conditionHeavy1 || conditionLight3)
	// if (conditionLight3 || conditionHeavy1) <- 이게 더 좋음
	if (conditionHeavy1 || conditionLight3)
	{
		//printf("해당 코드가 실행된다.");
	}
	else
	{
		//printf("그 외 코드가 실행된다.");
	}

	// if문에서
	// - && 연산자 동작은 false를 만나면 뒤의 연산을 하지 않음
	// - 보통 메이저 언어들은 거의 다 이럼
	// if (conditionHeavy2 && conditionLight3)
	// if (conditionLight3 && conditionHeavy2) <- 이게 더 좋음
	if (conditionHeavy2 && conditionLight3)
	{
		//printf("둘 다 참이면 실행된다.");
	}
	else
	{
		//printf("그 외 코드가 실행된다.");
	}

	// 이정도면 습관화 해주면 됨.
	// 출현 빈도가 별로 없는 거부터 앞에 두기
}

void Comment03()
{
	// Flipbook이란?
	// 종이 애니메이션 
	
	// 유니티에는 Animation이라고 통합 되어 있고
	// 언리얼은 Flipbook, Animation 따로 나누고 있음
}

void Comment04()
{
	// 실습
	// FlipbookActor을 상속 받아서
	// CreatureActor를 만들고
	// 컨트롤러도 있어야 함.

	// space를 누르면 공격(Attack)
	// 화살표를 누르면 이동(Move)
	// 가만히 있으면 Idle 상태
}

void Comment05()
{
	// 오목
	// 오목판을 좌표화 한다음
	// 마우스의 클릭위치에서 제일 가까운 곳에 액터 생성
	
	// 
}