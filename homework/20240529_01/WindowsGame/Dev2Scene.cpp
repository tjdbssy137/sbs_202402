#include "pch.h"
#include "Dev2Scene.h"
void Dev2Scene::Init()
{
	Super::Init();

}
void Dev2Scene::Render(HDC hdc)
{
	Super::Render(hdc);

	wstring str = L"Dev2Scene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());
}
void Dev2Scene::Update()
{
	Super::Update();

	if (Input->GetKey(KeyCode::Control) && Input->GetKeyDown(KeyCode::RightMouse))
	{
		GET_SINGLE(SceneManager)->ChangeScene(SceneType::Dev1Scene);
	}
}
void Dev2Scene::Release()
{
	Super::Release();

}