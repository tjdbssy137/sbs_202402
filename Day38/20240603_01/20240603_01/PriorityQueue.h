#pragma once
#include <vector>
#include <assert.h>
using namespace std;

template <typename T>
class PriorityQueue
{
private:
	vector<T> _arr;
public:
	T& Peek()
	{
		assert(0 < _arr.size());
		return _arr[0];
	}

	bool Enmpty()
	{
		return _arr.size() == 0;
	}
	void Pop()
	{
		assert(0 < _arr.size());
		::swap(_arr[_arr.size() - 1], _arr[0]);
		_arr.pop_back();

		int index = 0;

		while (true)
		{
			if (_arr.size() == 0)
			{
				break;
			}
			if (_arr.size() - 1 < index * 2 + 1)
			{
				// ���� �ε����� �迭 ������� �� Ŀ�������� ��.
				break;
			}
			T& currentNode = _arr[index];
			T& leftNode = _arr[index * 2 + 1];
			T rightNode = _arr[index];
			bool rightNodeExist = false;

			if (index * 2 + 2 < _arr.size() - 1)
			{
				rightNode = _arr[index * 2 + 2];
				rightNodeExist = true;
			}

			if (rightNodeExist)
			{
				if (leftNode < rightNode)
				{
					// ������ �ڽ��� �����ڽĺ��� �� ũ��
					// ������ �ڽİ� ��
					if (currentNode < rightNode)
					{
						::swap(_arr[index * 2 + 2], currentNode);
						index = index * 2 + 2;
					}
					else
					{
						break;
					}
				}
				else if (rightNode < leftNode)
				{
					// ������ �ڽ��� �����ڽĺ��� �� ũ��
					//������ �ڽİ� ��
					if (currentNode < leftNode)
					{
						::swap(leftNode, currentNode);
						index = index * 2 + 1;
					}
					else
					{
						break;
					}
				}
			}
			
		}
	}
	void Push(T data)
	{
		_arr.push_back(data);
		int index = _arr.size() - 1;
		while (true)
		{
			if (index == 0) break;
			
			// �θ���� �����带 ��
			T parentNode = _arr[(index - 1) / 2];
			T currentNode = _arr[index];

			if (parentNode < currentNode) // �θ���� �ڽĳ�庸�� �׻� ���� Ŀ���ϹǷ�. ������ ������.
			{
				::swap(parentNode, currentNode);
				/*T temp = _arr[(index - 1) / 2];
				_arr[(index - 1) / 2] = currentNode;
				_arr[index] = temp;*/
				index = (index - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}
};

