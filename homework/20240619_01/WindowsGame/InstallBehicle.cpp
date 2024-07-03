#include "pch.h"
#include "InstallBehicle.h"
#include "Dev2Scene.h"
#include "BehicleActor.h"

void InstallBehicle::Init()
{
	Super::Init();
}
void InstallBehicle::Render(HDC hdc)
{
	Super::Render(hdc);
}
void InstallBehicle::Update()
{
	Super::Update();
}
void InstallBehicle::Release()
{
	Super::Release();
}

void InstallBehicle::InstallBehicleFunc(Vector2Int pos)
{
	Dev2Scene* dev2Scene = dynamic_cast<Dev2Scene*>(CurrentScene);
	vector<BehicleActor*> behicles = dev2Scene->GetBehicleActor();
	if (behicles.size() == _index) // vector 범위 벗어나는 것 방지
	{
		_index = 0;
	}
	behicles[_index]->SetCellPos(pos, true);
	_index++;
}