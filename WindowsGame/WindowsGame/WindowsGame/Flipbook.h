#pragma once
#include "ResourceBase.h"

struct FlipbookInfo//������ �ϳ��ϳ� getter setter �ϱ� ����� ������
{
	Texture* texture;
	Vector2Int size;
	int start = 0;
	int end = 0;
	int line = 0;

	float duration = 1.0f; //�� flipbook ��ü �����ϴ� �� �ɸ��� �ð�
	bool loop = true; // 1ȸ�� �ϰ� �������, ��� �ݺ��� ���� 
};
class Flipbook : public ResourceBase
{
private:
	FlipbookInfo _info = {};
public:
	Flipbook();
	virtual ~Flipbook();//virtual�Ҹ��� ������ dynamic_cast�ȵ�
public:
	void SetInfo(FlipbookInfo& info){ _info = info; }
	const FlipbookInfo& GetInfo() { return _info; }
};

