#include "pch.h"
#include "TestPanel.h"
#include "Image.h"
#include "Button.h"

void TestPanel::Init()
{
	Super::Init();
	{
		Resource->LoadTexture(L"T_Victory", L"UIStudy/img_victory.bmp");
		Resource->CreateSprite(L"S_Victory", Resource->GetTexture(L"T_Victory"));		
		Resource->LoadTexture(L"T_Mole", L"Mole/mole.bmp");
		Resource->CreateSprite(L"S_Mole_Idle", Resource->GetTexture(L"T_Mole"), 0, 0, 85, 113);
		Resource->CreateSprite(L"S_Mole_Die", Resource->GetTexture(L"T_Mole"), 85, 0, 85, 113);
			
		auto a = Resource->GetTexture(L"T_PlayerDown");

		Resource->CreateSprite(L"S_IconUI", Resource->GetTexture(L"T_PlayerDown"), 0, 0, 200, 200);
		Resource->CreateSprite(L"S_IconUI_Default", Resource->GetTexture(L"T_PlayerDown"), 0, 0, 200, 200);
		Resource->CreateSprite(L"S_IconUI_Hover", Resource->GetTexture(L"T_PlayerUp"), 200, 0, 200, 200);
		Resource->CreateSprite(L"S_IconUI_Pressed", Resource->GetTexture(L"T_PlayerRight"), 400, 0, 200, 200);
		Resource->CreateSprite(L"S_IconUI_Disabled", Resource->GetTexture(L"T_PlayerDown"), 600, 0, 200, 200);

		this->SetRect(Shape::MakeCenterRect(WIN_SIZE_X/ 2, WIN_SIZE_Y / 2, 1000, 1000));
		
		
		Panel* iconListPanel = new Panel();
		{
			iconListPanel->SetRect(Shape::MakeCenterRect(100, 0, 0, 0));
			this->AddChild(iconListPanel);
		}

		{
			Image* image1 = new Image();
			image1->SetRect(Shape::MakeCenterRect(0, 0, 0, 0));//panel기준으로 해야하기 때문에 좌표가 같아야 함.
			image1->SetSprite(Resource->GetSprite(L"S_Victory"));
			image1->Init();
			iconListPanel->AddChild(image1);
		}

		{
			Image* image1 = new Image();
			image1->SetRect(Shape::MakeCenterRect(0, 60, 0, 0));//panel기준으로 해야하기 때문에 좌표가 같아야 함.
			image1->SetSprite(Resource->GetSprite(L"S_Mole_Idle"));
			image1->Init();
			iconListPanel->AddChild(image1);
		}

		{
			Button* button = new Button();
			button->SetRect(Shape::MakeCenterRect(0, 0, 200, 200));
			button->SetSprite(ButtonState::Default, Resource->GetSprite(L"S_IconUI_Default"));
			button->SetSprite(ButtonState::Hover, Resource->GetSprite(L"S_IconUI_Hover"));
			button->SetSprite(ButtonState::Pressed, Resource->GetSprite(L"S_IconUI_Pressed"));
			button->SetSprite(ButtonState::Disabled, Resource->GetSprite(L"S_IconUI_Disabled"));
			button->Init();
			iconListPanel->AddChild(button);
			
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