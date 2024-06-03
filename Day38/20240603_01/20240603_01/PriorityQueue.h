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
				// 왼쪽 인덱스가 배열 사이즈보다 더 커져버리면 끝.
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
					// 오른쪽 자식이 왼쪽자식보다 더 크면
					// 오른쪽 자식과 비교
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
					// 오른쪽 자식이 왼쪽자식보다 더 크면
					//오른쪽 자식과 비교
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
			
			// 부모노드와 현재노드를 비교
			T parentNode = _arr[(index - 1) / 2];
			T currentNode = _arr[index];

			if (parentNode < currentNode) // 부모노드는 자식노드보다 항상 값이 커야하므로. 작으면 문제임.
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

