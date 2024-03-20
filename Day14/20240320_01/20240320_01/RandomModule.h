#pragma once
#include <random>
#include <chrono>
// ���⿡ ���� �ڵ�� ���غ��� �帧�� �˱�.

class RandomModule
{
public:
	RandomModule()
	{
		//�õ带 ���� �ð����� ����
		// auto Ű����
		auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		//high_resolution_clock => ������ �ð��
		//.now() => ���� �ð���
		//.time_since_epoch() => 1970�� 1�� 1�� �������� ���ʰ� ��������
		//.count() => �� ī��Ʈ�� ���ڴ�.
		_engine.seed(seed);
	}
	~RandomModule() {}
public:
	// ������ ���� ���� ������ ��ȯ�ϴ� �޼���
	int GetRandomInt(int min, int max)
	{
		//dist -> min�� max���̿��� �������� �̾��ִ� ��.
		std::uniform_int_distribution<int> dist(min, max);
		return dist(_engine);
	}

	// ������ ���� ���� �Ǽ��� ��ȯ�ϴ� �޼���
	double GetRandomDouble(double min, double max)
	{
		//dist -> min�� max���̿��� �������� �̾��ִ� ��.
		std::uniform_real_distribution<double> dist(min, max);
		return dist(_engine);
	}
private:
	std::mt19937 _engine;
};