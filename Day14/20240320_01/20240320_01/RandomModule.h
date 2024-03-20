#pragma once
#include <random>
#include <chrono>
// 여기에 적을 코드는 이해보단 흐름을 알기.

class RandomModule
{
public:
	RandomModule()
	{
		//시드를 현재 시간으로 변경
		// auto 키워드
		auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		//high_resolution_clock => 초정밀 시계로
		//.now() => 지금 시간을
		//.time_since_epoch() => 1970년 1월 1일 기준으로 몇초가 지났는지
		//.count() => 그 카운트를 세겠다.
		_engine.seed(seed);
	}
	~RandomModule() {}
public:
	// 지정된 범위 내의 정수를 반환하는 메서드
	int GetRandomInt(int min, int max)
	{
		//dist -> min과 max사이에서 랜덤값을 뽑아주는 것.
		std::uniform_int_distribution<int> dist(min, max);
		return dist(_engine);
	}

	// 지정된 범위 내의 실수를 반환하는 메서드
	double GetRandomDouble(double min, double max)
	{
		//dist -> min과 max사이에서 랜덤값을 뽑아주는 것.
		std::uniform_real_distribution<double> dist(min, max);
		return dist(_engine);
	}
private:
	std::mt19937 _engine;
};