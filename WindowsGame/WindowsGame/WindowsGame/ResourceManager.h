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

// map��
// BinaryTree�� �����͸� key�� ���� �ϰ� - wstring
// �� �ȿ� ���� �����Ͱ� ���� �ִ�. - ResourcesBase*
// map�� ������ �˻��� ������.
