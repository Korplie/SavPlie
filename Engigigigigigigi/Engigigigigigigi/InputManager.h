#pragma once

#include<vector>
#include<d3dx9.h>
class KeyState
{
public:
	int vkCode;
	bool isOn;//키가 눌리고 잇ㄱ을때
	bool isDown;//키가 한번 눌렸나
	bool isUp;//키를 땠는가

	KeyState(int vkCode): vkCode(vkCode),isOn(false),isDown(false),isUp(false)
	{

	}
};

static class InputManager
{
public:
	InputManager();
	~InputManager();

	static void init(HWND hWnd);
	static void Update();
	static D3DXVECTOR2 InputManager::mousePosition;
	static std::vector<KeyState*>KeyStateVector;

	static HWND hWnd;

	enum class KeyCode { W, A, S, D,  M0, M1, Space, MAX };
	static void AddKey(KeyCode keyCode, int vkCode);

	static bool GetKey(KeyCode keyCode);
	static bool GetKeDowny(KeyCode keyCode);
	static bool GetKeyUp(KeyCode keyCode);

};

