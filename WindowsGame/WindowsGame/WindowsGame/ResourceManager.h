#pragma once
class ResourcesBase;

class ResourceManager
{
	DECLARE_SINGLE(ResourceManager);
public:
	void Init();
	void Release();

private:
	wstring _resourcePath;
	map<wstring, ResourcesBase*> _resources;
};

// map은
// BinaryTree의 데이터를 key로 들어가게 하고 - wstring
// 그 안에 실제 데이터가 따로 있다. - ResourcesBase*
// map의 장점은 검색이 빠르다.
