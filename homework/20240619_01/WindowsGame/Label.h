#pragma once
#include "UI.h"
class Label : public UI
{
	DECLARE_CHILD(Label, UI);

public:
	void SetText(wstring text);
	void SetAlign(int textAlign);
	void SetFont(wstring fontName, int fontSize);

	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
protected:
	wstring _text = L"";
	HFONT _font = {};
	int _fontSize = 12;
	int _textAlign = TA_LEFT;
};

