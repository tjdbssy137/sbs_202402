#include "pch.h"
#include "Label.h"

void Label::SetText(wstring text)
{
	_text = text;
}
void Label::SetAlign(int textAlign)
{
	_textAlign = textAlign;
}
void Label::SetFont(wstring fontName, int fontSize)
{
	_fontSize = fontSize;
	_font = CreateFont(
		_fontSize,
		0,
		0,
		0,
		1000,
		0,
		0,
		0,
		HANGEUL_CHARSET,
		0,
		0,
		0,
		VARIABLE_PITCH | FF_ROMAN,
		fontName.c_str()
	);
}

void Label::Init()
{
	Super::Init();
}
void Label::Render(HDC hdc)
{
	if (_isShow == false) return;

	HFONT oldFont = (HFONT)SelectObject(hdc, _font);

	Vector2Int size = this->_size;
	Vector2Int pos = this->_pos;

	//시작지점과 끝지점 구하기
	Vector2Int startPos = { pos.x - size.x / 2, pos.y - size.y / 2 };
	Vector2Int endPos = { pos.x + size.x / 2, pos.y + size.y / 2 };


	switch (_textAlign)
	{
	case TA_CENTER:
		SetTextAlign(hdc, TA_CENTER);
		TextOut(hdc, pos.x, pos.y - _fontSize / 2, _text.c_str(), _text.length());
		break;

	case TA_LEFT:
		SetTextAlign(hdc, TA_LEFT);
		TextOut(hdc, startPos.x, startPos.y - _fontSize / 2, _text.c_str(), _text.length());
		break;

	case TA_RIGHT:
		SetTextAlign(hdc, TA_RIGHT);
		TextOut(hdc, endPos.x, endPos.y - _fontSize / 2, _text.c_str(), _text.length());
		break;
	default:
		break;
	}

	SelectObject(hdc, oldFont);

	Super::Render(hdc);
}
void Label::Update()
{
	Super::Update();
}
void Label::Release()
{
	Super::Release();

	DeleteObject(_font);
}