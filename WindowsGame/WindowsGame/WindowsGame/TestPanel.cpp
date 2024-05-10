#include "pch.h"
#include "TestPanel.h"
#include "Image.h"
void TestPanel::Init()
{
	Super::Init();
	{
		Resource->LoadTexture(L"T_Victory", L"UIStudy/img_victory.bmp");
		Resource->CreateSprite(L"S_Victory", Resource->GetTexture(L"T_Victory"));

		this->SetRect(Shape::MakeCenterRectLTWH(0, 0, WIN_SIZE_X, WIN_SIZE_Y));
		{
			Image* image1 = new Image();
			image1->SetRect(Shape::MakeCenterRectLTWH(0, 0, WIN_SIZE_X, WIN_SIZE_Y));//panel기준으로 해야하기 때문에 좌표가 같아야 함.
			image1->SetSprite(Resource->GetSprite(L"S_Victory"));
			image1->Init();
			this->AddChild(image1);
		}
	}
}
void TestPanel::Render(HDC hdc)
{
	Super::Render(hdc);
}
void TestPanel::Update()
{
	Super::Update();
}
void TestPanel::Release()
{
	Super::Release();
}