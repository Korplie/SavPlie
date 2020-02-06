#pragma once


#include<d3d9.h>
class Scene;

static class GameManager
{
public:
	static void init(HWND hWnd);
	static void Render();
	static void Update();

	static Scene* nowScene;

	GameManager();
	~GameManager();
private:
	static LPDIRECT3D9 g_pD3D;
	static LPDIRECT3DDEVICE9 g_pd3dDevice;
};

