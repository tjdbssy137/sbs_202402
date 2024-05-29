#pragma once
#include "UI.h"
class Panel : public UI
{
	DECLARE_CHILD(Panel, UI);

public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

protected:
	vector<UI*> _children;

public:
	void AddChild(UI* ui);
	bool RemoveChild(UI* ui);
};

