#include "pch.h"
#include "Dev2Scene.h"
void Dev2Scene::Init()
{
	Super::Init();
}
void Dev2Scene::Render(HDC hdc) {
	Super::Render(hdc);
	wstring str = L"Dev2Scene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());
}
void Dev2Scene::Update()
{
	Super::Update();

	if (Input->GetKey(KeyCode::Control) && Input->GetKeyDown(KeyCode::RightMouse))
	{// 두 개를 입력 받을 때에는 둘 중 하나는 GetKey로 해야함. 둘 다 GetKeyDown으로 받으면 한 프레임에 동시에 두 개 눌러야 함.
		GET_SINGLE(SceneManager)->ChangeScene(SceneType::Dev1Scene);
	}
}
void Dev2Scene::Release()
{
	Super::Release();
}