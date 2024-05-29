#pragma once
class ResourceBase;
class Texture;
class Sprite;
class Flipbook;
struct FlipbookInfo;
class Sound;
class Tilemap;
class Tile;

class ResourceManager
{
	DECLARE_SINGLE(ResourceManager);
public:
	void Init();
	void Release();

	Texture* LoadTexture(const wstring& key, const wstring& path, uint32 transparent = RGB(255, 0, 255));
	Texture* GetTexture(const wstring& key);

	Sprite* CreateSprite(const wstring& key, Texture* texture, int x = 0, int y = 0, int cx = 0, int cy = 0);
	Sprite* GetSprite(const wstring& key);

	Flipbook* CreateFlipbook(const wstring& key, FlipbookInfo info);
	Flipbook* GetFlipbook(const wstring& key);

	Sound* GetSound(const wstring& key);
	Sound* LoadSound(const wstring& key, const wstring& path);

	Tilemap* GetTileMap(const wstring& key);
	Tilemap* LoadTileMap(const wstring& key, const wstring& path);
	Tilemap* CreateTileMap(const wstring& key, Vector2Int mapSize, int tileSize, vector<vector<Tile>> tiles);
private:
	wstring _resourcePath;
	map<wstring, ResourceBase*> _resources;
};

