#pragma once
#include <chrono>
#include <random>
class RandomManager
{
	DECLARE_SINGLE(RandomManager)
public:
	void Init()
	{
		auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		_engine.seed(seed);
	}

	int GetRandomInt(int min, int max)
	{
		std::uniform_int_distribution<int> dist(min, max);
		return dist(_engine);
	}

	double GetRandomDouble(double min, double max)
	{
		std:uniform_real_distribution<double> dist(min, max);
		return dist(_engine);
	}

private:
	//·£´ý ¿£Áø
	std::mt19937 _engine;

};

