#include "stdafx.h"
#include "TestObj.h"
#include"Animation.h"
#include"InputManager.h"
#include"Camera.h"
#include"Bullet.h"
#include<Windows.h>
#include"Scene.h"
#include"GraphicManager.h"

TestObj::TestObj()
{
}


TestObj::~TestObj()
{
}

void TestObj::Awake()
{
	animation->SetAnimation("TestAni");
	name = "Player";
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

void TestObj::OnCollisionEnter(GameObject * gameObject)
{
	if (gameObject->name == "Enemy")
	{

		isActive = false;
		gameObject->isActive = false;
	}
}

void TestObj::OnDestroy()
{
	GameManager::nowScene->nextSceneName="Main";
}

void TestObj::OnRender()
{
	GraphicManager::DrawT("잉 테스트에연", {position });
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
		auto bullet = Instantiate<Bullet>(position);
		if (bullet != nullptr)
		{
			bullet->SetOption(normal, 40);
			
		}
	}
	if (InputManager::GetKey(InputManager::KeyCode::M1)&&Camera::scale.x<1.5f)
	{
		Camera::scale.x += 0.01f;
		Camera::scale.y += 0.01f;
	}
	if (InputManager::GetKey(InputManager::KeyCode::Space) && Camera::scale.x>0.5f)
	{
		Camera::scale.x -= 0.01f;
		Camera::scale.y -= 0.01f;
	}
	if (InputManager::GetKey(InputManager::KeyCode::M1) && InputManager::GetKeDowny(InputManager::KeyCode::Space) )
	{
		GameManager::sans();
	}
	if (InputManager::GetKey(InputManager::KeyCode::M0) && InputManager::GetKeDowny(InputManager::KeyCode::Space))
	{
		isActive = true;
	}

}
