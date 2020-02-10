#include "stdafx.h"
#include "InputManager.h"
#include<Windows.h>
#include"Camera.h"

std::vector<KeyState*>InputManager::KeyStateVector= std::vector<KeyState*>();
D3DXVECTOR2 InputManager::mousePosition  {0.0f, 0.0f};
HWND InputManager::hWnd = HWND();
InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

void InputManager::init(HWND hWnd)
{
	InputManager::hWnd = hWnd;
	KeyStateVector.resize(static_cast<int>(KeyCode::MAX));
	AddKey(KeyCode::W, 'W');
	AddKey(KeyCode::A, 'A');
	AddKey(KeyCode::S, 'S');
	AddKey(KeyCode::D, 'D');
	AddKey(KeyCode::M0, VK_LBUTTON);
	AddKey(KeyCode::M1, VK_RBUTTON);
	AddKey(KeyCode::Space, VK_SPACE);


	
}

void InputManager::Update()
{
	//범위지정 포
	for (auto key : KeyStateVector)
	{
		key->isUp = key->isDown = false;
		if (GetAsyncKeyState(key->vkCode) & 0x8000)
		{

			if (!key->isOn)
				key->isDown = true;
			key->isOn = true;
		}
		else
		{
			if (key->isOn)
				key->isUp = true;
			key->isOn = false;
		}
	
	}
	POINT pos;
	GetCursorPos(&pos);
	ScreenToClient(hWnd, &pos);
	mousePosition = { static_cast<float>(pos.x-Camera::screenWidth*0.5f),static_cast<float>(pos.y - Camera::screenHeight*0.5f) };
	mousePosition += Camera::position;
}

void InputManager::AddKey(KeyCode keyCode, int vkCode)
{
	KeyStateVector[static_cast<int>(keyCode)] = new KeyState(vkCode);
}

bool InputManager::GetKey(KeyCode keyCode)
{
	return KeyStateVector[static_cast<int>(keyCode)]->isOn;
}

bool InputManager::GetKeDowny(KeyCode keyCode)
{
	return KeyStateVector[static_cast<int>(keyCode)]->isDown;
	
}

bool InputManager::GetKeyUp(KeyCode keyCode)
{
	return KeyStateVector[static_cast<int>(keyCode)]->isUp;
	
}
