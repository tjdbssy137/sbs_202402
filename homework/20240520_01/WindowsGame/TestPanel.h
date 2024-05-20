#pragma once
#include "Panel.h"
class TestPanel : public Panel
{
	DECLARE_CHILD(TestPanel, Panel)
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};

