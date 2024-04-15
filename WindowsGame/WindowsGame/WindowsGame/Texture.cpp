#include "pch.h"
#include "Texture.h"
Texture::Texture()
{

}
Texture::~Texture()
{

}

Texture* Texture::LoadMap(const wstring& path)
{

	// 외부에 있는 텍스처를 로딩하는 방법
	// windowsAPI에서 제공해주는 걸 사용

	HDC hdc = ::GetDC(_hWnd);
	_hdc = CreateCompatibleDC(hdc);
	_bitmap = (HBITMAP)LoadImage(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	
	if (_bitmap == NULL)
	{
		MessageBox(_hWnd, path.c_str(), L"Image Load Failed!", 0);
		return nullptr;
	}
	//hdc에다가 bitmap을 넣어줌
	HBITMAP prev = (HBITMAP)SelectObject(_hdc, _bitmap);
	DeleteObject(prev);

	BITMAP bit = {};
	GetObject(_bitmap, sizeof(BITMAP), &bit);
	_size.x = bit.bmWidth;
	_size.y = bit.bmHeight;

	return this;
}