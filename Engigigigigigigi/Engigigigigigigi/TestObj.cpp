#include "stdafx.h"
#include "TestObj.h"
#include"Animation.h"
#include"InputManager.h"
#include"Camera.h"
#include"Bullet.h"
#include<Windows.h>
#include"Scene.h"

TestObj::TestObj()
{
}


TestObj::~TestObj()
{
}

void TestObj::Awake()
{
	animation->SetAnimation("TestAni");
	position = { 0.0f,0.0f };
	sortingLayer = 1;
	degree = 5;

}

void TestObj::Update()
{
	PlayerMove();
	MouseInput();
}

void TestObj::LateUpdate()
{
	CameraMove();
}

void TestObj::PlayerMove()
{
	if (InputManager::GetKey(InputManager::KeyCode::W))
	{
		position.y -= 5.5f;
	}
	if (InputManager::GetKey(InputManager::KeyCode::A))
	{
		position.x -= 5.5f;
	}
	if (InputManager::GetKey(InputManager::KeyCode::S))
	{
		position.y += 5.5f;
	}
	if (InputManager::GetKey(InputManager::KeyCode::D))
	{
		position.x += 5.5f;
	}
}

void TestObj::CameraMove()
{
	auto diff = position - Camera::position;

	Camera::position += diff*0.1f;
}

void TestObj::MouseInput()
{
	auto mousePosition = InputManager::mousePosition;

	auto diff = mousePosition - position;

	auto radian = atan2(diff.y, diff.x);

	degree = D3DXToDegree(radian);
	D3DXVECTOR2 normal;
	D3DXVec2Normalize(&normal, &diff);
	if (InputManager::GetKey(InputManager::KeyCode::M0))
	{
		auto bullet=Instantiate<Bullet>(position);
		if (bullet != nullptr)
		{
			bullet->SetOption(normal, 10);
		}
	}
	
}
