#include "pch.h"
#include "ResourceManager.h"
#include "ResourceBase.h"
#include "Texture.h"
#include "Sprite.h"
#include "Flipbook.h"
#include "Sound.h"
#include "Tilemap.h"
void ResourceManager::Init()
{
	_resources.clear();
	_resourcePath = L"../Resources/";
}
void ResourceManager::Release()
{
	for (auto& item : _resources)
	{
		SAFE_DELETE(item.second);
	}
	_resources.clear();
}

Texture* ResourceManager::LoadTexture(const wstring& key, const wstring& path, uint32 transparent)
{
	if (_resources.contains(key))
	{
		return GetTexture(key);
	}

	wstring fullPath = _resourcePath + path;
	Texture* texture = new Texture();
	texture->LoadBmp(fullPath);
	texture->SetTransparent(transparent);

	_resources[key] = texture;

	return texture;
}

Texture* ResourceManager::GetTexture(const wstring& key)
{
	return dynamic_cast<Texture*>(_resources[key]);
}

Sprite* ResourceManager::CreateSprite(const wstring& key, Texture* texture, int x, int y, int cx, int cy)
{
	if (_resources.contains(key))
	{
		return GetSprite(key);
	}

	if (cx == 0)
	{
		cx = texture->GetSize().x;
	}

	if (cy == 0)
	{
		cy = texture->GetSize().y;
	}

	Sprite* sprite = new Sprite(texture, x, y, cx, cy);
	_resources[key] = sprite;
	return sprite;
}
Sprite* ResourceManager::GetSprite(const wstring& key)
{
	return dynamic_cast<Sprite*>(_resources[key]);
}

Flipbook* ResourceManager::CreateFlipbook(const wstring& key, FlipbookInfo info)
{
	if (_resources.contains(key))
	{
		return GetFlipbook(key);
	}

	Flipbook* flipbook = new Flipbook();
	flipbook->SetInfo(info);
	_resources[key] = flipbook;
	return flipbook;
}
Flipbook* ResourceManager::GetFlipbook(const wstring& key)
{
	return dynamic_cast<Flipbook*>(_resources[key]);
}


Sound* ResourceManager::LoadSound(const wstring& key, const wstring& path)
{
#ifdef USE_SOUND
	if (_resources.contains(key))
	{
		return GetSound(key);
	}

	Sound* sound = new Sound();
	wstring fullPath = _resourcePath + path;
	sound->LoadWave(fullPath);
	_resources[key] = sound;
	return sound;
#else
	return nullptr;
#endif
}

Sound* ResourceManager::GetSound(const wstring& key)
{
#ifdef USE_SOUND
	return dynamic_cast<Sound*>(_resources[key]);
#else
	return nullptr;
#endif
}

Tilemap* ResourceManager::GetTileMap(const wstring& key)
{
	return dynamic_cast<Tilemap*>(_resources[key]);
}

Tilemap* ResourceManager::LoadTileMap(const wstring& key, const wstring& path)
{
	if (_resources.contains(key))
	{
		return GetTileMap(key);
	}

	Tilemap* tileMap = new Tilemap();
	tileMap->LoadFile(path);
	_resources[key] = tileMap;

	return tileMap;
}

Tilemap* ResourceManager::CreateTileMap(const wstring& key, Vector2Int mapSize, int tileSize, vector<vector<Tile>> tiles)
{
	if (_resources.contains(key))
	{
		return GetTileMap(key);
	}

	Tilemap* tileMap = new Tilemap();
	tileMap->SetMapSize(mapSize);
	tileMap->SetTileSize(tileSize);
	tileMap->SetTiles(tiles);
	_resources[key] = tileMap;

	return tileMap;
}