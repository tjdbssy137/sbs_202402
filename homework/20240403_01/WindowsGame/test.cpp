#include "pch.h"
#include "test.h"

void test::Init()
{
	Super::Init();
}
void test::Render(HDC hdc) {
	Super::Render(hdc);

	wstring str = L"TestScene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());
}
void test::Update()
{
	Super::Update();

}
void test::Release()
{
	Super::Release();
}