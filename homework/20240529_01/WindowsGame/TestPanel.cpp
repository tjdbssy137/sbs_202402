#include "pch.h"
#include "TestPanel.h"
#include "Image.h"
#include "Panel.h"
#include "Button.h"
void TestPanel::Init()
{
	Super::Init();

	Resource->LoadTexture(L"T_VictoryUI", L"UIStudy/img_victory.bmp");
	Resource->CreateSprite(L"S_VistoryUI", Resource->GetTexture(L"T_VictoryUI"));
	Resource->CreateSprite(L"S_IconUI", Resource->GetTexture(L"T_PlayerDown"), 0, 0, 200, 200);
	Resource->CreateSprite(L"S_IconUI_Default", Resource->GetTexture(L"T_PlayerDown"), 0, 0, 200, 200);
	Resource->CreateSprite(L"S_IconUI_Hover", Resource->GetTexture(L"T_PlayerUp"), 200, 0, 200, 200);
	Resource->CreateSprite(L"S_IconUI_Pressed", Resource->GetTexture(L"T_PlayerRight"), 400, 0, 200, 200);
	Resource->CreateSprite(L"S_IconUI_Disabled", Resource->GetTexture(L"T_PlayerDown"), 600, 0, 200, 200);

	this->SetRect(Shape::MakeCenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y / 2, 0, 0));


	Panel* iconListPanel = new Panel();
	{
		iconListPanel->SetRect(Shape::MakeCenterRect(100, 0, 0, 0));
		this->AddChild(iconListPanel);
	}
	

	//background는 중심에 나오게끔.
	{
		Image* image = new Image();
		image->SetRect(Shape::MakeCenterRect(0, 0, 0, 0));
		image->SetSprite(Resource->GetSprite(L"S_VistoryUI"));
		image->Init();
		iconListPanel->AddChild(image);
	}

	//아이콘은 중심에서 살짝 왼쪽, 오른쪽
	{
		Image* image = new Image();
		image->SetRect(Shape::MakeCenterRect(-200, 0, 0, 0));
		image->SetSprite(Resource->GetSprite(L"S_IconUI"));
		image->Init();
		iconListPanel->AddChild(image);
	}

	{
		Image* image = new Image();
		image->SetRect(Shape::MakeCenterRect(200, 0, 0, 0));
		image->SetSprite(Resource->GetSprite(L"S_IconUI"));
		image->Init();
		iconListPanel->AddChild(image);
	}

	{
		Button* button = new Button();
		button->SetRect(Shape::MakeCenterRect(0, 0, 200, 200));
		button->SetSprite(ButtonState::Default, Resource->GetSprite(L"S_IconUI_Default"));
		button->SetSprite(ButtonState::Hover, Resource->GetSprite(L"S_IconUI_Hover"));
		button->SetSprite(ButtonState::Pressed, Resource->GetSprite(L"S_IconUI_Pressed"));
		button->SetSprite(ButtonState::Disabled, Resource->GetSprite(L"S_IconUI_Disabled"));
		button->AddOnClickDelegate(this, &TestPanel::OnClick_GotoDev2Scene);
		button->Init();
		iconListPanel->AddChild(button);
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

void TestPanel::OnClick_GotoDev2Scene()
{
	GET_SINGLE(SceneManager)->ChangeScene(SceneType::Dev2Scene);
}