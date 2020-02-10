#pragma once

#include<vector>
#include<d3dx9.h>
class KeyState
{
public:
	int vkCode;
	bool isOn;//Ű�� ������ �դ�����
	bool isDown;//Ű�� �ѹ� ���ȳ�
	bool isUp;//Ű�� ���°�

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

