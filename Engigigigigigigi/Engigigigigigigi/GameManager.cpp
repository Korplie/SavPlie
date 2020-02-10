
#include "GameManager.h"
#include"Camera.h"
#include"Scene.h"
#include"GraphicManager.h"
#include"TestObj.h"
#include"BackGround.h"
#include"InputManager.h"
#include"Enemy.h"

 LPDIRECT3D9 GameManager::g_pD3D= LPDIRECT3D9();
 LPDIRECT3DDEVICE9 GameManager::g_pd3dDevice= LPDIRECT3DDEVICE9();
 Scene* GameManager::nowScene=nullptr;
void GameManager::init(HWND hWnd)
{
	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.BackBufferHeight = Camera::screenHeight;
	d3dpp.BackBufferWidth = Camera::screenWidth;

	g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &g_pd3dDevice);

	GraphicManager::init(g_pd3dDevice);
	InputManager::init(hWnd);

	nowScene = new Scene();

	Instantiate<TestObj>({ 0.0f,0.0f });
	Instantiate<BackGround>({ 0.0f,0.0f });
	Instantiate < Enemy > ({ 100,100 });
	Instantiate < Enemy >({ -100,100 });
	Instantiate < Enemy >({ -100,-100 });
	Instantiate < Enemy >({ 100,-100 });
}

void GameManager::Render()
{
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(111, 111, 111), 1.0f, 0);
	g_pd3dDevice->BeginScene();

	//오브젝트 렌더어어어어어어어ㅓ어어어어어ㅓ어어어ㅓ어리리이이이이이이이잉이잉
	GraphicManager::Render();

	g_pd3dDevice->EndScene();
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

void GameManager::Update()
{
	InputManager::Update();
	nowScene->Update();
	Camera::Update();
}


GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}
