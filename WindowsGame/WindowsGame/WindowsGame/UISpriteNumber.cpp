#include "pch.h"
#include "UISpriteNumber.h"
#include "Sprite.h"
void UISpriteNumber::Init()
{
	Super::Init();
}
void UISpriteNumber::Render(HDC hdc)
{
	if (_isShow == false) return;
	Super::Render(hdc);

	// TextOut ��� TransparentBlt ����Ͽ�, Number���
	// TextOut(hdc, this->_pos.x, this->_pos.y, L"����",3);
	// ::TransparentBlt
	// Sprite ���徿 Render�� �������.

	// ���ھ߱��� ��ó��
	// 1. �ڸ����� �󸶳� �Ǵ���
	// 2. �׷����� ù��° ��ǥ�� �����.
	// 
	// _pos.x, _pos.y < �츮�� ������ ������ �߽���ǥ
	// _pos.x - �̹��� ���α��� / 2 gks rkqtdmfh rlflrl tlwkr
	// _pos.x - ��ü���� / 2
	// _pos.x - (�̹��� ���� ������ * ���ڸ� ����) / 2
	// 
	// �߽���ǥ �������� �׸����� 
	// 1. end Position�� ���� ���Ѵ�
	// 2. SpriteNumber�� ���̸�ŭ ���鼭 �� ��ġ���� �׸��� �����Ѵ�
	// 
	// 1. end Position�� ���� ���Ѵ�
	//		(currentNubmer->���ڸ����� üũ�ϴ� ����)
	//		- _sprites[currentNumber]->GetSize().x �� ��� ���ϸ� totalWidth�� ����
	//		- _pos.x + totalWidth / 2 ���� end Position
	// ���� �ڸ�, ���� �ڸ�, ���� �ڸ�

	int endPosition = 0;
	int totalWidth = 0;
	int temp = _number;

	do
	{
		int currentNumber = temp % 10;
		temp /= 10;
		totalWidth = _sprites[currentNumber]->GetSize().x;
	} while (0 < temp);
	endPosition = _pos.x + totalWidth / 2;

	// 2. SpriteNumber�� ���̸�ŭ ���鼭 �� ��ġ���� �׸��� �����Ѵ�
	//	- ���� �ڸ� ��ġ�� : endPosition - sprites[�����ڸ�]->GetSize().x
	//	- ���� �ڸ� ��ġ�� : endPosition - sprites[�����ڸ�]->GetSize().x - sprites[�����ڸ�]->GetSize().x

	temp = _number;
	int currentPosition = endPosition;
	do
	{
		int currentNumber = temp % 10;
		temp /= 10;
		currentPosition -= _sprites[currentNumber]->GetSize().x;

		::TransparentBlt(hdc,
			currentPosition,
			this->_pos.y - _sprites[currentNumber]->GetSize().y / 2,
			_sprites[currentNumber]->GetSize().x,
			_sprites[currentNumber]->GetSize().y,
			_sprites[currentNumber]->GetDC(),
			_sprites[currentNumber]->GetPos().x,
			_sprites[currentNumber]->GetPos().y,
			_sprites[currentNumber]->GetSize().x,
			_sprites[currentNumber]->GetSize().y,
			_sprites[currentNumber]->GetTransparent());
	} while (0 < temp);
}
void UISpriteNumber::Update()
{
	Super::Update();
}
void UISpriteNumber::Release()
{
	Super::Release();
}

void UISpriteNumber::SetNumber(int number)
{
	_number = number;
}
void UISpriteNumber::SetSprites(wstring resourceName)
{
	for (int i = 0; i < 10; i++)
	{
		wchar_t spriteName[256];
		wsprintf(spriteName, L"%s_%d", resourceName.c_str(), i);

		_sprites[i] = GET_SINGLE(ResourceManager)->GetSprite(spriteName);
		printf("Error : UISpriteNumber::SetSprites(wstring resourceName) Not Found Resource");
	}
}
void UISpriteNumber::SetSprite(Sprite* sprite, int number)
{
	assert(0 <= number && number <= 9);
	_sprites[number] = sprite;
}