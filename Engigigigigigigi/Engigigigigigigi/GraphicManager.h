#pragma once

#include<d3dx9.h>
#include<map>
#include<string>

class GameObject;

static class GraphicManager
{
public:
	GraphicManager();
	~GraphicManager();

	static void init(LPDIRECT3DDEVICE9 device);

	static void AddTexture(std::string textureName, LPCWSTR fileName);
	static LPDIRECT3DTEXTURE9 GetTexture(std::string textureName);
	static LPDIRECT3DTEXTURE9 createTexture(LPCWSTR fileName);
	static void Render();
	static void Render(GameObject* object);
	static D3DXVECTOR2 GetTextureSize(LPDIRECT3DTEXTURE9 texture);
	static D3DXVECTOR2 GetTextureSize( std::string textureName);
	static bool compare(GameObject*o1, GameObject*o2);
	static void DrawT(std::string str, D3DXVECTOR2 position);

private:
	static LPDIRECT3DDEVICE9 device;
	static LPD3DXSPRITE sprite;
	static std::map<std::string, LPDIRECT3DTEXTURE9> textureMap;
	static ID3DXFont * font;


};

